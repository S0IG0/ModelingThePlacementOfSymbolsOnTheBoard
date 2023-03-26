
#include "ConsoleWriter.h"
ConsoleWriter::ConsoleWriter(Base* parent, std::string name) : Base(parent, name)
{
}
void ConsoleWriter::signal_write_to_console(std::string& command)
{
	command = "";
	std::string line;
	while (std::getline(file, line))
	{
		command += line + "\n";
	}
	command.pop_back();
}
void ConsoleWriter::handler_write_to_console(std::string command)
{
	if (command == "END")
	{
		command = "";
		std::string line;
		while (std::getline(file, line))
		{
			command += line + "\n";
		}
		command.pop_back();
		std::cout << command;
	}
}
