#ifndef WRITER_H
#define WRITER_H
#include "Base.h"
#include "Mover.h"

class Writer : public Base
{
public:
	Writer(Base* parent, std::string name = "Writer");
	void write(std::string& command);
	void signalWrite(std::string& command);
	void handlerWrite(std::string command);
private:
	bool is_latin_alphabet(char letter);
	int x = -1;
	bool successfull_write = false;
};
#endif