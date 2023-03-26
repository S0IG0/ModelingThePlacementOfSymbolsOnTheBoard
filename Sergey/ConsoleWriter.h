#ifndef CONSOLEWRITER_H
#define CONSOLEWRITER_H
#include "Base.h"

class ConsoleWriter : public Base
{
public:
	ConsoleWriter(Base* parent, std::string name = "ConsoleWriter");
	void signal_write_to_console(std::string& command);
	void handler_write_to_console(std::string command);
};
#endif