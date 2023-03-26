#include "Base.h"

Base::Base(Base* parent, std::string name) : name(name), parent(parent)
{
	if (parent != nullptr)	// т.к корневой объект тоже создвется этим конструтором, необходима проверка
	{
		parent->children.push_back(this);
	}
}

Base::~Base()
{
	for (auto& child : children)
	{
		delete child;
	}
}

std::string Base::getName()
{
	return name;
}

void Base::setName(std::string name)
{
	this->name = name;
}

void Base::setParent(Base* parent)
{
	// Если есть ткущий родитель
	if (this->parent != nullptr && parent != nullptr)
	{
		auto& parentChildren = this->parent->children;
		for (int i = 0; i < parentChildren.size(); i++)
		{
			if (parentChildren[i] == this)
			{
				parentChildren.erase(parentChildren.begin() + i);
				break;
			}
		}

		// Перезаписываем родителя
		this->parent = parent;

		// Записываем в родителя нового ребенка
		parent->children.push_back(this);
	}
}

Base* Base::getParent()
{
	return parent;
}

void Base::printObjects()
{
	if (children.size() > 0)
	{
		std::cout << name;

		for (auto child : children)
		{
			std::cout << "  " << child->getName();
		}

		for (auto child : children)
		{
			if (child->children.size() != 0)
			{
				std::cout << "\n";
				break;
			}
		}

		for (auto child : children)
		{
			child->printObjects();
		}
	}
}

void Base::printTreeObjects(int deep)
{
	if (deep == 0)
	{
		std::cout << name;
	}

	for (auto child : children)
	{
		std::cout << "\n";
		std::cout.width(((deep + 1) * 4) + child->name.length());
		std::cout << child->name;

		child->printTreeObjects(deep + 1);
	}
}

void Base::printStatusObjects(int deep)
{
	if (deep == 0)
	{
		if (status == 0)
		{
			std::cout << name << " is not ready";
		}
		else
		{
			std::cout << name << " is ready";
		}
	}

	for (auto child : children)
	{
		std::string name = child->name;

		std::cout << "\n";
		std::cout.width(((deep + 1) * 4) + name.length());
		std::cout << name;

		if (child->status == 0)
		{
			std::cout << " is not ready";
		}
		else
		{
			std::cout << " is ready";
		}

		child->printStatusObjects(deep + 1);
	}
}

int Base::getStatus()
{
	return status;
}

void Base::setStatus(int digit)
{
	status = digit;
	if (status == 0)
	{
		for (auto& child : children)
		{
			child->setStatus(0);
		}
	}
}

Base* Base::searchByName(std::string name)
{
	Base* temp = nullptr;

	if (this->name == name)
	{
		temp = this;
	}
	else
	{
		for (auto child : children)
		{
			if (child->name == name)
			{
				temp = child;
				break;
			}
		}

		for (auto child : children)
		{
			if (temp != nullptr)
			{
				break;
			}

			temp = child->searchByName(name);
		}
	}

	return temp;
}

Base* Base::searchByPath(std::string path)
{
	Base* temp = nullptr;
	Base* root = this;

	while (root->parent != nullptr)
	{
		root = root->parent;
	}

	if (path.size() == 1 && path == ".")
	{
		temp = this;
	}
	else if (path.size() == 1 && path == "/")
	{
		temp = root;
	}
	else if (path.size() >= 2)
	{
		std::vector<std::string> arrNames;
		std::string tempName = "";

		int currentIndex = 0;
		int start = 0;

		if (path[0] == '/' && path[1] == '/')
		{
			start++;
		}

		for (int i = start; i <= path.size(); i++)
		{
			if ((path[i] == '/' && (i != start)) || i == (path.size()))
			{
				arrNames.push_back(tempName);
				tempName = "";
			}
			else if (path[i] != '/')
			{
				tempName += path[i];
			}
		}

		if (start != 0)
		{
			temp = root->searchByName(arrNames[0]);
		}
		else if (path[0] == '/')
		{
			temp = searchByPath(root, arrNames, currentIndex);
		}
		else
		{
			temp = searchByPath(this, arrNames, currentIndex);
		}
	}


	return temp;
}

Base* Base::searchByPath(Base* obj, std::vector<std::string>& arrNames, int currentIndex)
{
	Base* temp = nullptr;
	for (auto& child : obj->children)
	{
		if (child->name == arrNames[currentIndex])
		{
			if (arrNames.size() != currentIndex + 1)
			{
				temp = obj->searchByPath(child, arrNames, currentIndex + 1);
			}
			else
			{
				temp = child;
			}

			break;
		}
	}


	return temp;
}

std::string Base::getAbsolutePath()
{
	std::string path = parent == nullptr ? "/" : "";
	Base* temp = this;
	while (temp->parent != nullptr)
	{
		path = "/" + temp->name + path;
		temp = temp->parent;
	}

	return path;
}

void Base::setConnect(typeSignal signal, Base* obj, typeHandler handler)
{
	for (auto& connect : connects)
	{
		if (connect->signal == signal && connect->obj == obj && connect->handler == handler)
		{
			return;
		}
	}
	connects.push_back(new StructConnect({ signal, obj, handler }));
}

void Base::deleteConnect(typeSignal signal, Base* obj, typeHandler handler)
{
	for (int i = 0; i < connects.size(); i++)
	{
		if (connects[i]->signal == signal && connects[i]->obj == obj && connects[i]->handler == handler)
		{
			connects.erase(connects.begin() + i);
			break;
		}
	}
}

void Base::emitConnect(typeSignal signal, std::string command)
{
	if (status != 0)
	{
		(this->*(signal))(command);
		for (auto& connect : connects)
		{
			if (connect->obj->status != 0 && signal == connect->signal)
			{
				((connect->obj)->*(connect->handler))(command);
			}
		}
	}
}

std::fstream Base::file;