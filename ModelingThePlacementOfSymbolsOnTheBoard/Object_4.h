#ifndef OBJECT_4_H
#define OBJECT_4_H
#include "Base.h"

class Object_4 : public Base
{
public:
	Object_4(Base* parent, std::string name = "root");

	void signal(std::string& data); // Выдать сигнал
	void handler(std::string data); // Обработать сигнал

private:

};

#endif // !OBJECTONE_H
