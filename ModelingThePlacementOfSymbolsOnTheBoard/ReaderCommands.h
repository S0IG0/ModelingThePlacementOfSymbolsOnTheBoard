#ifndef READERCOMMANDS_H
#define READERCOMMANDS_H
#include "Base.h"

class ReaderCommands : public Base
{
public:
	ReaderCommands(Base* parent, std::string name = "ReaderCommands");
	void readCommand(std::string& command);
	void handlerReadCommand(std::string command);
private:
	std::string command_ = "";
};
#endif