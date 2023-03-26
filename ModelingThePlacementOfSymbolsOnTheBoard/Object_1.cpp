#include "Object_1.h"

Object_1::Object_1(Base* parent, std::string name) : Base(parent, name)
{
}

void Object_1::signal(std::string& data)
{
	std::cout << "\nSignal from " << getAbsolutePath();
	data += " (class: 2)";
}

void Object_1::handler(std::string data)
{
	std::cout << "\nSignal to " << getAbsolutePath() << " Text:  " << data;
}