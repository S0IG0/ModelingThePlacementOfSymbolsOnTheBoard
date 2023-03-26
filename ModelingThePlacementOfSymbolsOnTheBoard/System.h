#ifndef SYSTEM_H
#define SYSTEM_H
#include "Base.h"
#include "FileOperations.h"
#include "ReaderCommands.h"
#include "Mover.h"
#include "Writer.h"
#include "ErrorWriter.h"
#include "ConsoleWriter.h"

class System : public Base
{
public:
	System(Base* parent, std::string name = "System");
	void build_tree_of_paths();
	void set_connects();
	void on_all(Base* obj);
	void signalReadParams(std::string& command);
	void handlerFile(std::string command);
	void handlerCommands(std::string command);
	void handlerEnd(std::string command);
	int exec_app();

private:
	bool successful_build_tree = true;
	bool end = false;
	std::map<std::string, typeSignal> typeSignalData = {
		{"signal_write_to_console",	SIGNAL(ConsoleWriter::signal_write_to_console)},
		{"signalReadParams",		SIGNAL(System::signalReadParams)},
		{"readCommand",				SIGNAL(ReaderCommands::readCommand)},
		{"createFile",				SIGNAL(FileOperations::createFile)},
		{"MoveSignal",				SIGNAL(Mover::MoveSignal)},
		{"signalWrite",				SIGNAL(Writer::signalWrite)},
		{"write",					SIGNAL(Writer::write)},
		{"move",					SIGNAL(Mover::move)},

	};
	std::map<std::string, typeHandler> typeHandlerData = {
		{"handler_write_to_console",HANDLER(ConsoleWriter::handler_write_to_console)},
		{"handlerReadCommand",		HANDLER(ReaderCommands::handlerReadCommand)},
		{"MoveHandlerCommand",		HANDLER(Mover::MoveHandlerCommand)},
		{"handlerCommands",			HANDLER(System::handlerCommands)},
		{"handlerError",			HANDLER(ErrorWriter::handlerError)},
		{"handlerFile",				HANDLER(System::handlerFile)},
		{"moveToBegin",				HANDLER(Mover::moveToBegin)},
		{"moveToEnd",				HANDLER(Mover::moveToEnd)},
		{"handlerMove",				HANDLER(Mover::handlerMove)},
		{"handlerEnd",				HANDLER(System::handlerEnd)},
		{"handlerWrite",			HANDLER(Writer::handlerWrite)},
	};
};
#endif