#include "Writer.h"
Writer::Writer(Base* parent, std::string name) : Base(parent, name)
{
}
void Writer::write(std::string& command)
{
	command = "";
	std::string letter = "";
	std::cin >> letter;

	if (x != file.tellp() || successfull_write == false) //(row != file.getRow() || column != file.getColumn())
	{
		x = file.tellp();
		if (is_latin_alphabet(letter[0]))
		{
			file << letter[0];
			successfull_write = true;
		}
		else
		{
			command = "The letter does not belong to the Latin alphabet: " + letter;
			successfull_write = false;
		}
	}
	else
	{
		char buf[sizeof(int) * 2 + sizeof("Attempt to sequentially write to a cell ( ,  )")];
		snprintf(buf, sizeof(buf), "Attempt to sequentially write to a cell ( %d, %d )", (int)x / 11 + 1, x % 11 + 1);
		command = buf;
		successfull_write = false;
	}
}
void Writer::signalWrite(std::string& command)
{
}
void Writer::handlerWrite(std::string command)
{
	if (command == "WRITE")
	{
		command = "";
		std::string letter = "";
		std::cin >> letter;
		if (x != file.tellp() || successfull_write == false)
		{
			x = file.tellp();
			if (is_latin_alphabet(letter[0]))
			{
				file << letter[0];
				successfull_write = true;
			}
			else
			{
				command = "The letter does not belong to the Latin alphabet: " + letter;
				successfull_write = false;
			}
		}
		else
		{
			char buf[sizeof(int) * 2 + sizeof("Attempt to sequentially write to a cell ( ,  )")];
			snprintf(buf, sizeof(buf), "Attempt to sequentially write to a cell ( %d, %d )", (int)x / 11 + 1, x % 11 + 1);
			command = buf;
			successfull_write = false;
		}
		if (command != "")
		{
			emitConnect(SIGNAL(Writer::signalWrite), command);
		}
	}
}
bool Writer::is_latin_alphabet(char letter)
{
	for (int i = 'A'; i <= 'Z'; i++)
	{
		if (letter == (char)i)
		{
			return true;
		}
	}
	for (int i = 'a'; i <= 'z'; i++)
	{
		if (letter == (char)i)
		{
			return true;
		}
	}
	return false;
}