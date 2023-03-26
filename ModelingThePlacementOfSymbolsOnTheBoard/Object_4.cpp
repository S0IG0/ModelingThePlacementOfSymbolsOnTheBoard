#include "Object_4.h"

Object_4::Object_4(Base* parent, std::string name) : Base(parent, name)
{
}

void Object_4::signal(std::string& data)
{
	std::cout << "\nSignal from " << getAbsolutePath();
	data += " (class: 5)";
}

void Object_4::handler(std::string data)
{
	std::cout << "\nSignal to " << getAbsolutePath() << " Text:  " << data;
}