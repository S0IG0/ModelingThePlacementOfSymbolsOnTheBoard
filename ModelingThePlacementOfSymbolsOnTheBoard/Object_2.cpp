#include "Object_2.h"

Object_2::Object_2(Base* parent, std::string name) : Base(parent, name)
{
}

void Object_2::signal(std::string& data)
{
	std::cout << "\nSignal from " << getAbsolutePath();
	data += " (class: 3)";
}

void Object_2::handler(std::string data)
{
	std::cout << "\nSignal to " << getAbsolutePath() << " Text:  " << data;
}