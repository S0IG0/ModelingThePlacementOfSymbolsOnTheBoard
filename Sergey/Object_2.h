#ifndef OBJECT_2_H
#define OBJECT_2_H
#include "Base.h"

class Object_2 : public Base
{
public:
	Object_2(Base* parent, std::string name = "root");

	void signal(std::string& data); // ������ ������
	void handler(std::string data); // ���������� ������

private:

};

#endif // !OBJECTONE_H
