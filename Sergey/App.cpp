#include "App.h"

App::App(Base* parent, std::string name) : Base(parent, name)
{

}

void App::bild_tree_objects()
{
	std::string name_1, name_2;
	int digit;

	std::cin >> name_1;

	setName(name_1);

	while (true)
	{
		std::cin >> name_1;

		if (name_1 == exit)
		{
			break;
		}

		std::cin >> name_2 >> digit;
		Base* temp = searchByName(name_1);

		if (digit == 2)
		{
			new Object_1(temp, name_2);
		}
		else if (digit == 3)
		{
			new Object_2(temp, name_2);
		}
		else if (digit == 4)
		{
			new Object_3(temp, name_2);
		}
		else if (digit == 5)
		{
			new Object_4(temp, name_2);
		}
		else if (digit == 6)
		{
			new Object_5(temp, name_2);
		}
	}

	while (std::cin >> name_1 >> digit)
	{
		Base* temp = searchByName(name_1);
		Base* tempParent = temp->getParent();

		if (tempParent == nullptr)
		{
			temp->setStatus(digit);
		}
		else
		{
			if (tempParent->getStatus() != 0)
			{
				temp->setStatus(digit);
			}
			else
			{
				temp->setStatus(0);
			}
		}

	}
}

void App::bild_tree_objects_of_paths()
{
	std::string path, name;
	int digit;

	std::cin >> name;

	setName(name);

	while (true)
	{
		std::cin >> path;

		if (path == exit)
		{
			break;
		}

		std::cin >> name >> digit;
		Base* temp = searchByPath(path);

		if (temp == nullptr)
		{
			successful = false;
			break;
		}

		if (digit == 2)
		{
			new Object_1(temp, name);
		}
		else if (digit == 3)
		{
			new Object_2(temp, name);
		}
		else if (digit == 4)
		{
			new Object_3(temp, name);
		}
		else if (digit == 5)
		{
			new Object_4(temp, name);
		}
		else if (digit == 6)
		{
			new Object_5(temp, name);
		}
	}

	if (!successful)
	{
		std::cout << "Object tree\n";
		printTreeObjects();
		std::cout << "\nThe head object " << path << " is not found";
	}
}


void App::read_commands()
{
	Base* current = this;
	Base* temp = nullptr;

	std::string name, path;

	bool isFirst = true;

	while (true)
	{
		std::cin >> name;

		if (name == "END")
		{
			break;
		}

		std::cin >> path;

		if (!isFirst)
		{
			std::cout << "\n";
		}

		temp = current->searchByPath(path);
		if (name == "FIND")
		{
			std::cout << path;

			if (temp == nullptr)
			{
				std::cout << "     Object is not found";
			}
			else
			{
				std::cout << "     Object name: " << temp->getName();
			}

		}
		else if (name == "SET")
		{

			if (temp == nullptr)
			{
				std::cout << "Object is not found: " << current->getName() << " " << path;
			}
			else
			{
				current = temp;
				std::cout << "Object is set: " << current->getName();
			}
		}

		isFirst = false;
	}
}

int App::exec_app_of_paths()
{

	if (successful)
	{
		std::cout << "Object tree\n";
		printTreeObjects();
		std::cout << "\n";
		read_commands();
	}

	return 0;
}

int App::exec_app()
{
	std::cout << "Object tree\n";
	printTreeObjects();
	std::cout << "\nThe tree of objects and their readiness\n";
	printStatusObjects();

	return 0;
}

void App::signal(std::string& data)
{
	std::cout << "\nSignal from " << getAbsolutePath();
	data += " (class: 1)";
}

void App::handler(std::string data)
{
	std::cout << "\nSignal to " << getAbsolutePath() << " Text:  " << data;
}

int App::detect_obj(Base* obj)
{
	int result = -1;

	if (dynamic_cast<App*>(obj))
	{
		result = 0;
	}
	else if (dynamic_cast<Object_1*>(obj))
	{
		result = 1;
	}
	else if (dynamic_cast<Object_2*>(obj))
	{
		result = 2;
	}
	else if (dynamic_cast<Object_3*>(obj))
	{
		result = 3;
	}
	else if (dynamic_cast<Object_4*>(obj))
	{
		result = 4;
	}
	else if (dynamic_cast<Object_5*>(obj))
	{
		result = 5;
	}

	return result;
}

void App::set_connects()
{
	while (true)
	{
		std::string path_signal, path_handler;
		std::cin >> path_signal;

		if (path_signal == "end_of_connections")
		{
			break;
		}

		std::cin >> path_handler;

		Base* obj_signal = searchByPath(path_signal);
		Base* obj_handler = searchByPath(path_handler);

		obj_signal->setConnect(
			typeSignalData[detect_obj(obj_signal)],
			obj_handler,
			typeHandlerData[detect_obj(obj_handler)]
		);
	}
}


void App::read_commands_connects()
{
	while (true)
	{
		std::string temp;
		std::cin >> temp;

		if (temp == "END")
		{
			break;
		}
		else if (temp == "EMIT")
		{
			std::cin >> temp;
			Base* obj_signal = searchByPath(temp);

			if (obj_signal)
			{
				std::cin.ignore();
				std::getline(std::cin, temp);

				obj_signal->emitConnect(typeSignalData[detect_obj(obj_signal)], temp);
			}
			else
			{
				std::cout << "\nObject " << temp << " not found";
			}

		}
		else if (temp == "SET_CONNECT")
		{
			std::cin >> temp;
			Base* obj_signal = searchByPath(temp);

			if (obj_signal)
			{
				std::cin >> temp;
				Base* obj_handler = searchByPath(temp);
				if (obj_handler)
				{
					obj_signal->setConnect(
						typeSignalData[detect_obj(obj_signal)],
						obj_handler,
						typeHandlerData[detect_obj(obj_handler)]
					);
				}
				else
				{
					std::cout << "\nHandler object " << temp << " not found";
				}
			}
			else
			{
				std::cout << "\nObject " << temp << " not found";
			}
		}
		else if (temp == "DELETE_CONNECT")
		{
			std::cin >> temp;
			Base* obj_signal = searchByPath(temp);

			if (obj_signal)
			{
				std::cin >> temp;
				Base* obj_handler = searchByPath(temp);
				if (obj_handler)
				{
					obj_signal->deleteConnect(
						typeSignalData[detect_obj(obj_signal)],
						obj_handler,
						typeHandlerData[detect_obj(obj_handler)]
					);
				}
				else
				{
					std::cout << "\nHandler object " << temp << " not found";
				}
			}
			else
			{
				std::cout << "\nObject " << temp << " not found";
			}
		}
		else if (temp == "SET_CONDITION")
		{
			int status;
			std::cin >> temp;
			Base* obj_signal = searchByPath(temp);

			if (obj_signal)
			{
				std::cin >> status;
				obj_signal->setStatus(status);
			}
			else
			{
				std::cout << "\nObject " << temp << " not found";
			}
		}
	}
}

void App::on_all(Base* obj)
{
	obj->status = 1;
	for (auto& chlid : obj->children)
	{
		chlid->status = 1;
		on_all(chlid);
	}
}

int App::exec_app_of_paths_connects()
{
	if (successful)
	{
		on_all(this);

		std::cout << "Object tree\n";
		printTreeObjects();
		set_connects();
		read_commands_connects();
	}

	return 0;
}