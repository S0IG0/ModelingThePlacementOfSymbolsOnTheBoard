#include "ErrorWriter.h"
ErrorWriter::ErrorWriter(Base* parent, std::string name) : Base(parent, name)
{
}
void ErrorWriter::handlerError(std::string command)
{
	if (command != "" && !(command == "MOVE" || command == "WRITE" || command == "END" || command == "SHOWTREE"))
	{
		file << "\n" << command;
	}
}
