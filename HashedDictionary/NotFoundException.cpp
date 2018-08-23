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
*  Modified:      08/22/2018                               *
*                                                          *
***********************************************************/


#include "stdafx.h"
#include "NotFoundException.h"

NotFoundException::NotFoundException(const std::string & message)
	: logic_error("Precondition violated exception: " + message)
{
}// end constructor
