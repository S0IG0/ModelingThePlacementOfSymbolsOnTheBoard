#include "ReaderCommands.h"
ReaderCommands::ReaderCommands(Base* parent, std::string name) : Base(parent, name)
{
}
void ReaderCommands::readCommand(std::string& command)
{
	command = command_;
}
void ReaderCommands::handlerReadCommand(std::string command)
{
	std::cin >> command_;
	if (!(command_ == "MOVE" || command_ == "WRITE" || command_ == "END" || command_ == "SHOWTREE"))
	{
		std::string params;
		std::getline(std::cin, params);
		command_ = "ERROR command: " + command_ + params;
	}
	emitConnect(SIGNAL(ReaderCommands::readCommand), command);
}