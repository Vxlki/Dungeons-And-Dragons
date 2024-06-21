#pragma once
#include"IException.h"
#include<iostream>

class GenericException : public IException
{
protected:
	std::string exceptie;
public:
	GenericException(std::string aux = "Undhandled exception");
	void printException() override;
};