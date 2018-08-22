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
#include "HashedDictionaryInterface.h"
#include "HashedDictionary.h"

/**
	Displays the menu.
*/
void displayMenu();

/**
	Ask the user for a menu choice.
	@return The user's menu choice.
*/
int askForMenuChoice();

/**
	Prompts the user to create an entry to add to the dictionary.
	@param dictionaryPtr The dictionary to add the entry.
*/
void performAddOperation(
	HashedDictionaryInterface<std::string, std::string>* dictionaryPtr);

/**
	Prompts the user for an item to retrieve from the dictionary.
	@param dictionaryPtr The dictionary to retrieve an entry from.
*/
void performRetrieveOperation(
	HashedDictionaryInterface<std::string, std::string>* dictionaryPtr);

/**
	Prompts the user for an item to remove from the dictionary.
	@param dictionaryPtr The dictionary to remove an entry from.
*/
void performRemoveOperation(
	HashedDictionaryInterface<std::string, std::string>* dictionaryPtr);

int main()
{
	HashedDictionaryInterface<std::string, std::string>* dictionaryPtr =
		new HashedDictionary<std::string, std::string>;

	displayMenu();
	int userChoice = askForMenuChoice();
	switch (userChoice)
	{
	case 1:
		performAddOperation(dictionaryPtr);
		break;
	case 2:
		performRetrieveOperation(dictionaryPtr);
		break;
	case 3:
		performRemoveOperation(dictionaryPtr);
		break;
	default:
		break;
	}

    return 0;
}

void displayMenu()
{
	std::cout << "\n\n     Welcome to the HashedDictionary!\n\n";
	std::cout << "         ,..........   ..........,\n"
		<< "     ,..,'          '.'          ',..,\n"
		<< "    ,' ,'            :            ', ',\n"
		<< "   ,' ,'             :             ', ',\n"
		<< "  ,' ,'              :              ', ',\n"
		<< " ,' ,'............., : ,.............', ',\n"
		<< ",'  '............   '.'   ............'  ',\n"
		<< " '''''''''''''''''';''';''''''''''''''''''\n"
		<< "                    '''\n"
		<< "(Ascii Art from www.asciiart.eu/books/books)\n\n";

	std::cout << "Main menu:\n"
		<< "1 - Add item to the dictionary.\n"
		<< "2 - Retrieve an item from the dictionary.\n"
		<< "3 - Remove an item from the dict24ionary.\n"
		<< "4 - Terminate the program.\n\n";
}

int askForMenuChoice()
{
	bool isValidChoice = false;
	int userMenuChoice = 0;
	do
	{
		std::cout << "Enter a menu choice: ";
		std::string userChoiceText;
		std::getline(std::cin, userChoiceText);

		try
		{
			userMenuChoice = std::stoi(userChoiceText);
		}
		catch (...)
		{
			std::cout << "Invalid menu option.\n\n";
			continue;
		}
		if (userMenuChoice > 4 || userMenuChoice < 0)
		{
			std::cout << "Menu option must be within the range of 1-4.\n\n";
		}
		else
		{
			isValidChoice = true;
		}
	} while (!isValidChoice);

	return userMenuChoice;
}

void performAddOperation(
	HashedDictionaryInterface<std::string, std::string>* dictionaryPtr)
{
	std::string searchKey = "";
	std::cout << "Create a search key or enter a period(.) to return to main menu: ";
	std::getline(std::cin, searchKey);
	while (searchKey[0] != '.')
	{
		std::string dataItem = "";
		std::cout << "Enter a data item to be associated with " << searchKey << ": ";

		bool IsAdded = dictionaryPtr->add(searchKey, dataItem);
		if (IsAdded)
		{
			std::cout << "Search key " << searchKey <<
				" and data item " << dataItem << " have been added to the dictionary.\n\n";
		}
		else
		{
			std::cout << "Search key is already within the dictionary.\n\n";
		}

		std::string searchKey = "";
		std::cout << "Create a search key or enter a period(.) to return to main menu: ";
		std::getline(std::cin, searchKey);
	}
}

void performRetrieveOperation(
	HashedDictionaryInterface<std::string, std::string>* dictionaryPtr)
{
}

void performRemoveOperation(
	HashedDictionaryInterface<std::string, std::string>* dictionaryPtr)
{
}
