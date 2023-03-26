#ifndef ERRORWRITER_H
#define ERRORWRITER_H
#include "Base.h"	

class ErrorWriter : public Base
{
public:
	ErrorWriter(Base* parent, std::string name = "ErrorWriter");
	void handlerError(std::string command);
};
#endif