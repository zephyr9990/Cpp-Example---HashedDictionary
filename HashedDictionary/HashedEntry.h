// HashedEntry.h : Defines a HashedEntry

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
#include "Entry.h"

template<class KeyType, class ItemType>
class HashedEntry : public Entry<KeyType, ItemType>
{
public:
	HashedEntry();
	HashedEntry(KeyType searchKey, ItemType newEntry);
	HashedEntry(ItemType newEntry, KeyType searchKey,
		HashedEntry<KeyType, ItemType>* nextEntryPtr);

	/**
		Sets the pointer to the passed value.
		@param nextEntryPtr The pointer to the next entry.
		@post nextPtr will point to the same address as nextEntryPointer.
	*/
	void setNext(HashedEntry<KeyType, ItemType>* nextEntryPtr);

	/**
		Function to get a pointer to the next entry.
		@return The pointer to the next entry.
	*/
	HashedEntry<KeyType, ItemType>* getNext() const;

private:
	HashedEntry<KeyType, ItemType>* nextPtr;
};// end HashedEntry

///////////////////////////////////////////////////////////////////////////////
// IMPLEMENTATION DETAILS
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
// PUBLIC METHODS START HERE
///////////////////////////////////////////////////////////////////////////////

template<class KeyType, class ItemType>
HashedEntry<KeyType, ItemType>::HashedEntry()
{
	nextPtr = nullptr;
}// end constructor

template<class KeyType, class ItemType>
HashedEntry<KeyType, ItemType>::HashedEntry(KeyType searchKey, ItemType newEntry)
	: Entry<KeyType, ItemType>(searchKey, newEntry)
{
	nextPtr = nullptr;
}// end paramaterized constructor

template<class KeyType, class ItemType>
HashedEntry<KeyType, ItemType>::HashedEntry(ItemType newEntry, KeyType searchKey,
	HashedEntry<KeyType, ItemType>* nextEntryPtr)
	: Entry<KeyType, ItemType>(newEntry, searchKey)
{
	nextPtr = nextEntryPtr;
} // end paramterized constructor #2

template<class KeyType, class ItemType>
void HashedEntry<KeyType, ItemType>::setNext(HashedEntry<KeyType, ItemType>* nextEntryPtr)
{
	nextPtr = nextEntryPtr;
}// end setNext

template<class KeyType, class ItemType>
HashedEntry<KeyType, ItemType>* HashedEntry<KeyType, ItemType>::getNext() const
{
	return nextPtr;
}// end

///////////////////////////////////////////////////////////////////////////////
// END PUBLIC METHODS
///////////////////////////////////////////////////////////////////////////////