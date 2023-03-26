#include "FileOperations.h"
FileOperations::FileOperations(Base* parent, std::string name) : Base(parent, name)
{
}
void FileOperations::createFile(std::string& successful)
{
	successful = "";
	file.open(PATH_OUTPUT, std::ios_base::out);
	file.close();
	file.open(PATH_OUTPUT, std::ios_base::out | std::ios_base::in);

	if (file.is_open())
	{
		for (int i = 0; i < SIZE_MATRIX; i++)
		{
			for (int j = 0; j < SIZE_MATRIX; j++)
			{
				file << FILLER;
			}
			if (i != 9)
			{
				file << '\n';
			}
		}
	}
	else
	{
		successful = "File field.txt not create";
	}
}

