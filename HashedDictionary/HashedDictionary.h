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
		@param searchKeyThe search key to be searched.
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
}// end constructor

template<class KeyType, class ItemType>
bool HashedDictionary<KeyType, ItemType>::add(const KeyType & searchKey, const ItemType & newItem)
{
	return false;
}// end add

template<class KeyType, class ItemType>
bool HashedDictionary<KeyType, ItemType>::remove(const KeyType & searchKey)
{
	return false;
}// end remove

template<class KeyType, class ItemType>
ItemType HashedDictionary<KeyType, ItemType>::getItem(const KeyType & searchKey) const throw(NotFoundException)
{
	return ItemType();
}// end getItem

template<class KeyType, class ItemType>
bool HashedDictionary<KeyType, ItemType>::contains(const KeyType & searchKey) const
{
	return false;
}// end contains

template<class KeyType, class ItemType>
int HashedDictionary<KeyType, ItemType>::getHashIndex(const KeyType & searchKey) const
{
	return 0;
}// end getHashIndex
