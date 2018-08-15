// main.cpp : Defines the entry point for the console application.

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


#include "stdafx.h"

/**
	Displays the menu.
*/
void displayMenu();

/**
	Prompts the user to add an item to the dictionary.
	@param dictionaryPtr A pointer to the dictionary.
	@param searchKeys The vector containing the search keys.
*/
void addItem(HashedDictionaryInterface<string, string>* dictionaryPtr,
	vector<string>& searchKeys);

/**
	Prompts the user for an item to retrieve from the dictionary.
	@param dictionaryPtr A pointer to the dictionary.
	@param searchKeys The vector containing the search keys.
*/
void retrieveItem(HashedDictionaryInterface<string, string>* dictionaryPtr,
	vector<string>& searchKeys);

/**
	Prints the search keys that have values inside the dictionary.
	@param searchKeys The vector containing the search keys.
*/
void printSearchKeys(vector<string>& searchKeys);

int main()
{
	vector<string> searchKeys;
	HashedDictionaryInterface<string, string>* dictionaryPtr =
		new HashedDictionary<string, string>;


    return 0;
}

