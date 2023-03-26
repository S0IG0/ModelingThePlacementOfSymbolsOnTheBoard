#ifndef MOVER_H
#define MOVER_H
#include "Base.h"

class Mover : public Base
{
public:
	Mover(Base* parent, std::string name = "Mover");
	void move(std::string& command);
	void MoveHandlerCommand(std::string command);
	void MoveSignal(std::string& command);

	//////////////////////////////////////////////
	void handlerMove(std::string command);		//
	void moveToBegin(std::string command);		//
	void moveToEnd(std::string command);		//
	//////////////////////////////////////////////
private:
	int x = 1, y = 1;
};
#endif