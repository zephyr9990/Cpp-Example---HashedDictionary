//HashedDictionary.h -- Defines a HashedDictionary

/************************************************************
*                                                          *
*  Author:        Rodel Aragon                             *
*  Course:        CS322 Data Structure and Algorithms II   *
*  Assignment:    Module 5, Written Assignment             *
*  Program:       Hashed Dictionary        		           *
*  Description:   Creates a Hashed Dictionary using        *
*				  seperate chaining                        *
*  Input:         User input strings                       *
*  Output:        Displays search key insert index, and    *
* 				  item associated with search key          *
*  Created:       11/26/2017                               *
*                                                          *
***********************************************************/

#pragma once

#include "HashedDictionaryInterface.h"
#include "HashedEntry.h"
#include "NotFoundException.h"

template<class KeyType, class ItemType>
class HashedDictionary : public HashedDictionaryInterface<KeyType, ItemType>
{
public:
	HashedDictionary();

	/**
		Inserts an item into the dictionary according to the item's search key.
		@pre The search key must be of type string and must differ from all keys
			presently in the dictionary.
		@post If the insertion was successful, newItem is in its proper position
			within the dictionary.
		@param searchKey The search key associated with the item to be inserted.
		@para newItem The item to add to the dictionary.
		@return True if the item was successfully added, otherwise false if not.
	*/
	bool add(const KeyType& searchKey, const ItemType& newItem);

	/**
		Removes an item with the given search key from the dictionary.
		@post If the item whose search key equals searchKey existed within the
		dictionary, the item was removed.
		@param searchKey The search key of the item to be removed.
		@return True if the item was successfully removed, or false if not.
	*/
	bool remove(const KeyType& searchKey);

	/**
		Retrieves an item with a given saerch key from a dictionary.
		@post If the retrieval was successful, the item is returned.
		@param searchKey The search key of the item to be retrieved.
		@return The item associated with the search key.
		@throw NotFoundException if the item does not exist.
	*/
	ItemType getItem(const KeyType& searchKey) const
		throw(NotFoundException);

	/**
		Checks to see whether a given search key occurs within the dictionary.
		@post The boolean value is returned and the data remains unchanged.
		@param searchKey The search key to be searched.
		@return True if the item is contained within the dictionary,
		otherwise false0.
	*/
	bool contains(const KeyType& searchKey) const;

private:
	/*
		Function to get the hash index.
		@param searchKey The search key of the item.
		@return The index of where the item would be placed according to
			its search key.
	*/
	int getHashIndex(const KeyType& searchKey) const;

	int itemCount;
	int hashTableSize;
	static const int DEFAULT_SIZE = 101;
	HashedEntry<KeyType, ItemType>* hashTable[DEFAULT_SIZE];
};

///////////////////////////////////////////////////////////////////////////////
// IMPLEMENTATION DETAILS
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
// PUBLIC METHODS START HERE
///////////////////////////////////////////////////////////////////////////////

template<class KeyType, class ItemType>
HashedDictionary<KeyType, ItemType>::HashedDictionary()
{
	itemCount = 0;
	hashTableSize = DEFAULT_SIZE;

	for (int i = 0; i < DEFAULT_SIZE; i++)
	{
		hashTable[i] = nullptr;
	}
}// end constructor

template<class KeyType, class ItemType>
bool HashedDictionary<KeyType, ItemType>::add(const KeyType & searchKey,
	const ItemType & newItem)
{
	if (!contains(searchKey))
	{
		HashedEntry<KeyType, ItemType> *entryToAddPtr =
			new HashedEntry<KeyType, ItemType>(newItem, searchKey);
		int hashIndex = getHashIndex(searchKey);

		// Add the entry to the chain at hashIndex
		// If chain is empty...
		if (hashTable[hashIndex] == nullptr)
		{
			hashTable[hashIndex] = entryToAddPtr;
		}
		else // insert node at the beginning of chain
		{
			entryToAddPtr->setNext(hashTable[hashIndex]);
			hashTable[hashIndex] = entryToAddPtr;
		}

		itemCount++;
		return true;
	}
	else
	{
		return false;
	}
}// end add

template<class KeyType, class ItemType>
bool HashedDictionary<KeyType, ItemType>::remove(const KeyType & searchKey)
{
	bool itemFound = false;
	int hashIndex = getHashIndex(searchKey);

	// if chain is not empty
	if (hashTable[hashIndex] != nullptr)
	{
		// Special case - first node has target
		if (searchKey == hashTable[hashIndex]->getKey())
		{
			HashedEntry<KeyType, ItemType>* entryToRemovePtr =
				hashTable[hashIndex];
			hashTable[hashIndex] = hashTable[hashIndex]->getNext();

			delete entryToRemovePtr;
			entryToRemovePtr = nullptr;
			itemCount--;
			itemFound = true;
		}
		else // search the rest of the chain
		{
			HashedEntry<KeyType, ItemType>* previousPtr = hashTable[hashIndex];
			HashedEntry<KeyType, ItemType>* currentPtr = previousPtr->getNext();
			while ((currentPtr != nullptr) && !itemFound)
			{
				// found item in chain so remove that node
				if (searchKey == currentPtr->getKey())
				{
					// make previousPtr point to node after current
					previousPtr->setNext(currentPtr->getNext());

					delete currentPtr;
					currentPtr = nullptr;
					itemCount--;
					itemFound = true;
				}
				else // Look at next entry in chain
				{
					previousPtr = currentPtr;
					currentPtr = currentPtr->getNext();
				}
			}
		}
	}
	return itemFound;
}// end remove

template<class KeyType, class ItemType>
ItemType HashedDictionary<KeyType, ItemType>::getItem(const KeyType & searchKey)
	const throw(NotFoundException)
{
	bool itemFound = false;
	int hashIndex = getHashIndex(searchKey);

	// if chain is not tempty
	if (hashTable[hashIndex] != nullptr)
	{
		// if beginning of chain equals search key
		if (searchKey == hashTable[hashIndex]->getKey())
		{
			return hashTable[hashIndex]->getItem();
		}
		else // search rest of chain
		{
			HashedEntry<KeyType, ItemType>* currentPtr = hashTable[hashIndex];
			currentPtr = currentPtr->getNext();

			while ((currentPtr != nullptr) && !itemFound)
			{
				// found item in chain
				if (searchKey == currentPtr->getKey())
				{
					itemFound = true;
					return currentPtr->getItem();
				}
				else // look at next entry in chain
				{
					currentPtr = currentPtr->getNext();
				}
			}
			throw NotFoundException("Entry not found in dictionary.");
		}
	}
	else
	{
		throw NotFoundException("Entry not found in dictionary.");
	}
	return ItemType();
}// end getItem

template<class KeyType, class ItemType>
bool HashedDictionary<KeyType, ItemType>::contains(const KeyType & searchKey) const
{
	bool itemFound = false;
	int hashIndex = getHashIndex(searchKey);

	// if chain is not empty
	if (hashTable[hashIndex] != nullptr)
	{
		// if beginning of chain equals search key
		if (searchKey == hashTable[hashIndex]->getKey())
		{
			return true;
		}
		else // search rest of chain
		{
			HashedEntry<KeyType, ItemType>* currentPtr = hashTable[hashIndex];
			while ((currentPtr != nullptr) && !itemFound)
			{
				// found item in chain
				if (searchKey == currentPtr->getKey())
				{
					itemFound = true;
				}
				else // Look at next entry in chain
				{
					currentPtr = currentPtr->getNext();
				}
			}
		}
	}
	return itemFound;
}// end contains

///////////////////////////////////////////////////////////////////////////////
// PUBLIC METHODS END HERE
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
// PRIVATE METHODS START HERE
///////////////////////////////////////////////////////////////////////////////


template<class KeyType, class ItemType>
int HashedDictionary<KeyType, ItemType>::getHashIndex(const KeyType& searchKey) const
{
	int hashIndex = 0;
	int searchKeyLength = searchKey.length();

	char letter = ' ';
	int letterValue = 0;
	// if key is comprised of more than one letter, use Horner's rule
	// to find hash value.
	if (searchKeyLength > 1)
	{
		int characterValue = 0;
		for (int i = 0; i < searchKeyLength; i++)
		{
			if (searchKey[i] != ' ')
			{
				letter = toupper(searchKey[i]);
				letterValue = static_cast<int>(letter) - 64;
				hashIndex = ((hashIndex * 32) + letterValue) % hashTableSize;
			}
		}
	}
	else
	{
		char letter = toupper(searchKey[0]);
		hashIndex = (static_cast<int>(letter) - 64) % hashTableSize;
	}
	return hashIndex;
}// end getHashIndex
