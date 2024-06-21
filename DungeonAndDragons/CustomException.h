#pragma once
#include"GenericException.h"

class CustomException : public GenericException
{
public:
	CustomException(std::string aux);
	void printException() override;
};