#include "System.h"
System::System(Base* parent, std::string name) : Base(parent, name)
{
}
void System::set_connects()
{
	std::stringstream fileInput(PATH_INPUT);
	std::string temp = "";
	while (std::getline(fileInput, temp))
	{
		if (temp == exit)
		{
			break;
		}
	}
	while (true)
	{
		std::string path_signal, path_handler, nameSignal, nameHandler;
		fileInput >> path_signal;
		if (path_signal == "end_of_connections")
		{
			break;
		}
		fileInput >> path_handler;
		fileInput >> nameSignal;
		fileInput >> nameHandler;
		Base* obj_signal = searchByPath(path_signal);
		Base* obj_handler = searchByPath(path_handler);
		obj_signal->setConnect(
			typeSignalData[nameSignal],
			obj_handler,
			typeHandlerData[nameHandler]
		);
	}
}
void System::on_all(Base* obj)
{
	obj->status = 1;
	for (auto& child : obj->children)
	{
		child->status = 1;
		on_all(child);
	}
}
void System::signalReadParams(std::string& command)
{
	std::string parms;
	std::getline(std::cin, parms);
	command = "ERROR command: " + command + parms;
}
void System::handlerFile(std::string command)
{
	if (command != "")
	{
		std::cout << command;
		end = true;
	}
}
void System::handlerCommands(std::string command)
{
	if (command == "MOVE")
	{
		searchByPath("/Mover")->emitConnect(SIGNAL(Mover::move), command);
	}
	else if (command == "WRITE")
	{
		((Mover*)searchByPath("/Mover"))->handlerMove(command);
		searchByPath("/Mover/Writer")->emitConnect(SIGNAL(Writer::write), command);
	}
	else if (command == "END")
	{
		end = true;
		((Mover*)searchByPath("/Mover"))->moveToBegin(command);
		searchByPath("/ConsoleWriter")->emitConnect(SIGNAL(ConsoleWriter::signal_write_to_console), command);
	}
	else if (command == "SHOWTREE")
	{
		printStatusObjects();
		std::cout << "\n";
	}
	else
	{
		this->emitConnect(SIGNAL(System::signalReadParams), command);
	}
}
// std::mutex mtx;
int System::exec_app()
{
	// mtx.lock();
	set_connects();
	on_all(this);
	std::string command = "";
	searchByPath("/FileOperations")->emitConnect(SIGNAL(FileOperations::createFile), command);
	while (!end)
	{
		((ReaderCommands*)searchByPath("/ReaderCommands"))->handlerReadCommand("");
	}
	file.close();
	return 0;
}
void System::build_tree_of_paths()
{
	std::stringstream fileInput(PATH_INPUT);
	std::string path, name;
	int digit;
	fileInput >> name;
	std::string temp;
	this->name = name;
	while (true)
	{
		fileInput >> path;
		if (path == exit)
		{
			break;
		}
		fileInput >> name >> digit;
		Base* temp = searchByPath(path);
		if (temp == nullptr)
		{
			successful_build_tree = false;
			break;
		}
		if (digit == 2)
		{
			new FileOperations(temp, name);
		}
		else if (digit == 3)
		{
			new ReaderCommands(temp, name);
		}
		else if (digit == 4)
		{
			new Mover(temp, name);
		}
		else if (digit == 5)
		{
			new Writer(temp, name);
		}
		else if (digit == 6)
		{
			new ErrorWriter(temp, name);
		}
		else if (digit == 7)
		{
			new ConsoleWriter(temp, name);
		}
	}
	if (!successful_build_tree)
	{
		std::cout << "Object tree\n";
		printTreeObjects();
		std::cout << "\nThe head object " << path << " is not found";
	}
}

void System::handlerEnd(std::string command)
{
	if (command == "END")
	{
		end = true;
	}
}

