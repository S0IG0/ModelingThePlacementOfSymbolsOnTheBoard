#ifndef OBJECT_5_H
#define OBJECT_5_H
#include "Base.h"

class Object_5 : public Base
{
public:
	Object_5(Base* parent, std::string name = "root");

	void signal(std::string& data); // ������ ������
	void handler(std::string data); // ���������� ������

private:

};

#endif // !OBJECTONE_H
