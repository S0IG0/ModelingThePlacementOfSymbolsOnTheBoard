#ifndef OBJECT_3_H
#define OBJECT_3_H
#include "Base.h"

class Object_3 : public Base
{
public:
	Object_3(Base* parent, std::string name = "root");

	void signal(std::string& data); // ������ ������
	void handler(std::string data); // ���������� ������

private:

};

#endif // !OBJECTONE_H
