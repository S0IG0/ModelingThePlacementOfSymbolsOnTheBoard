#ifndef OBJECT_5_H
#define OBJECT_5_H
#include "Base.h"

class Object_5 : public Base
{
public:
	Object_5(Base* parent, std::string name = "root");

	void signal(std::string& data); // Выдать сигнал
	void handler(std::string data); // Обработать сигнал

private:

};

#endif // !OBJECTONE_H
