#ifndef OBJECT_1_H
#define OBJECT_1_H
#include "Base.h"

class Object_1 : public Base
{
public:
	Object_1(Base* parent, std::string name = "root");

	void signal(std::string& data); // Выдать сигнал
	void handler(std::string data); // Обработать сигнал	

private:

};

#endif // !OBJECTONE_H
