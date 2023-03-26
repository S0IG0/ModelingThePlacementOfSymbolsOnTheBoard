#ifndef FILEOPERATIONS_H
#define FILEOPERATIONS_H
#include "Base.h"

class FileOperations : public Base
{
public:
	FileOperations(Base* parent, std::string name = "FileOperations");
	void createFile(std::string& command);
};
#endif