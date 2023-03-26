#include "Mover.h"
Mover::Mover(Base* parent, std::string name) : Base(parent, name)
{
}
void Mover::move(std::string& command)
{
	command = "";
	int temp_x, temp_y;
	std::cin >> temp_x >> temp_y;
	if ((temp_x >= 1 && temp_x <= 10) && (temp_y >= 1 && temp_y <= 10))
	{
		x = temp_x;
		y = temp_y;
		file.seekp(0, std::ios_base::beg);
		file.seekp(((x - 1) * 11 + y - 1));
	}
	else
	{
		char buf[sizeof(x) + sizeof(y) + sizeof("Coordinate is wrong (  ,   )")];
		snprintf(buf, sizeof(buf), "Coordinate is wrong ( %d, %d )", temp_x, temp_y);
		command = buf;
	}
}
void Mover::handlerMove(std::string command)
{
	file.seekp(0, std::ios_base::beg);
	file.seekp(((x - 1) * 11 + y - 1));
}
void Mover::moveToBegin(std::string command)
{
	file.seekp(0, std::ios_base::beg);
}
void Mover::moveToEnd(std::string command)
{
	if (command != "")
	{
		file.seekp(0, std::ios_base::end);
	}
}
void Mover::MoveHandlerCommand(std::string command)
{
	if (command == "MOVE")
	{
		command = "";
		int temp_x, temp_y;
		std::cin >> temp_x >> temp_y;
		if ((temp_x >= 1 && temp_x <= 10) && (temp_y >= 1 && temp_y <= 10))
		{
			x = temp_x;
			y = temp_y;
			file.seekp(0, std::ios_base::beg);
			file.seekp(((x - 1) * 11 + y - 1));
		}
		else
		{
			char buf[sizeof(x) + sizeof(y) + sizeof("Coordinate is wrong (  ,   )")];
			snprintf(buf, sizeof(buf), "Coordinate is wrong ( %d, %d )", temp_x, temp_y);
			command = buf;
			this->emitConnect(SIGNAL(Mover::MoveSignal), command);
		}
	}

}
void Mover::MoveSignal(std::string& command)
{
}

