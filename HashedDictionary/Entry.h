// Entry.h : Defines an Entry

/************************************************************
*                                                          *
*  Author:        Rodel Aragon                             *
*  Course:        CS322 Data Structure and Algorithms II   *
*  Assignment:    Module 5, Written Assignment             *
*  Program:       Hashed Dictionary        		           *
*  Description:   Creates a Hashed Dictionary using        *
*				  seperate chaining                        *
*  Input:         User input strings                       *
*  Output:        Displays search key and item             *
*                 associated with search key.              *
*  Created:       11/26/2017                               *
*                                                          *
***********************************************************/

#pragma once

template<class KeyType, class ItemType>
class Entry
{
public:
	Entry();
	Entry(KeyType searchKey, ItemType newEntry);

	/**
		Retrieves the item.
		@return The data item.
	*/
	ItemType getItem() const;

	/**
		Retrieves the search key.
		@return the search key.
	*/
	KeyType getKey() const;

	/**
		Sets the data item to newEntry.
		@param newEntry The parameter for the entry.
	*/
	void setItem(const ItemType& newEntry);

	/**
		Sets the key to searchKey.
		@param searchKey The parameter to assign to searchKey.
	*/
	void setKey(const KeyType& searchKey);
	
private:
	KeyType searchKey;
	ItemType item;
};

///////////////////////////////////////////////////////////////////////////////
// IMPLEMENTATION DETAILS
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
// PUBLIC METHODS START HERE
///////////////////////////////////////////////////////////////////////////////

template<class KeyType, class ItemType>
Entry<KeyType, ItemType>::Entry()
{
	searchKey = "";
	item = "";
}// end constructor

template<class KeyType, class ItemType>
Entry<KeyType, ItemType>::Entry(KeyType searchKey, ItemType newEntry)
{
	this->searchKey = searchKey;
	item = newEntry;
}// end paramaterized constructor

template<class KeyType, class ItemType>
ItemType Entry<KeyType, ItemType>::getItem() const
{
	return item;
}// end getItem

template<class KeyType, class ItemType>
KeyType Entry<KeyType, ItemType>::getKey() const
{
	return searchKey;
}// end getKey

template<class KeyType, class ItemType>
void Entry<KeyType, ItemType>::setItem(const ItemType & newEntry)
{
	item = newEntry;
}// end setItem

template<class KeyType, class ItemType>
void Entry<KeyType, ItemType>::setKey(const KeyType & searchKey)
{
	this->searchKey = searchKey;
}// end setKey

 ///////////////////////////////////////////////////////////////////////////////
 // END PUBLIC METHODS
 ///////////////////////////////////////////////////////////////////////////////