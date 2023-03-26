#include "Object_3.h"

Object_3::Object_3(Base* parent, std::string name) : Base(parent, name)
{
}

void Object_3::signal(std::string& data)
{
	std::cout << "\nSignal from " << getAbsolutePath();
	data += " (class: 4)";
}

void Object_3::handler(std::string data)
{
	std::cout << "\nSignal to " << getAbsolutePath() << " Text:  " << data;
}