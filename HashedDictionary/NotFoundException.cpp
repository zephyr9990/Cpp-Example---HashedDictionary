#include "stdafx.h"
#include "NotFoundException.h"

NotFoundException::NotFoundException(const std::string & message)
	: logic_error("Precondition violated exception: " + message)
{
}// end constructor
