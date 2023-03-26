#include "Object_5.h"

Object_5::Object_5(Base* parent, std::string name) : Base(parent, name)
{
}

void Object_5::signal(std::string& data)
{
	std::cout << "\nSignal from " << getAbsolutePath();
	data += " (class: 6)";
}

void Object_5::handler(std::string data)
{
	std::cout << "\nSignal to " << getAbsolutePath() << " Text:  " << data;
}