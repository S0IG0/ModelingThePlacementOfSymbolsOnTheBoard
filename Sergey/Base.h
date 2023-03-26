#ifndef BASE_H
#define BASE_H
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <cstdio> 
#include <fstream>
#include <sstream>
#define exit "endtree"
#define exitConnect "end_of_connections"
#define PATH_OUTPUT "field.txt"
#define SIZE_MATRIX 10
#define FILLER 8


/*
#ifndef BASE_H
#define BASE_H

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <cstdio>
#include <fstream>

#include <sstream>
// #include <thread>
// #include <mutex>

#define exit "endtree"
#define exitConnect "end_of_connections"
#define PATH_OUTPUT "field.txt"
// #define PATH_INPUT "input.txt"
// #define PATH_INPUT "input_test.txt"
// #define PATH_INPUT "input_2.txt"

#define SIZE_MATRIX 10
#define FILLER 8

/*
static std::string PATH_INPUT =
	"System\n"
	"/ FileOperations 2\n"
	"/ ReaderCommands 3\n"
	"/ Mover 4\n"
	"/Mover Writer 5\n"
	"/ ErrorWriter 6\n"
	"/ ConsoleWriter 7\n"
	"endtree\n"
	"/FileOperations / createFile handlerFile\n"
	"/ReaderCommands / readCommand handlerCommands\n"
	"/Mover /Mover move moveToEnd\n"
	"/Mover /ErrorWriter move handlerError\n"
	"/Mover/Writer /Mover write moveToEnd\n"
	"/Mover/Writer /ErrorWriter write handlerError\n"
	"/ /Mover signalReadParams moveToEnd\n"
	"/ /ErrorWriter signalReadParams handlerError\n"
	"/ConsoleWriter /ConsoleWriter signal_write_to_console handler_write_to_console\n"
	"end_of_connections";
*/

/*
static std::string PATH_INPUT =
	"System\n"
	"/ FileOperations 2\n"
	"/ ReaderCommands 3\n"
	"/ Mover 4\n"
	"/Mover Writer 5\n"
	"/ ErrorWriter 6\n"
	"/ ConsoleWriter 7\n"
	"endtree\n"
	"/FileOperations / createFile handlerFile\n"
	"/ReaderCommands /ReaderCommands readCommand handlerReadCommand\n"
	"/ReaderCommands / readCommand handlerEnd\n"
	"end_of_connections";


class System;
class App;
class Base;
typedef void(Base::* typeSignal)(std::string&);
typedef void(Base::* typeHandler)(std::string);

#define SIGNAL( function ) ( typeSignal ) ( &function )
#define HANDLER( function ) ( typeHandler ) ( &function )

struct StructConnect
{
	typeSignal signal;
	Base* obj;
	typeHandler handler;
};

class Base
{
	friend class App;
	friend class System;

public:
	Base(Base* parent, std::string name = "root");	// �����������
	virtual ~Base();								// ����������

	void printObjects(); 					// ������� �� ����� �������� � �������� ������ ���� � ����� �� �����
	void printStatusObjects(int deep = 0);	// ������� ������ ��������� ��������
	void printTreeObjects(int deep = 0);	// ������� �� ����� ����� ��������
	void setName(std::string name);			// ������ ��� ���� name, (�������� ��� � �������)
	void setParent(Base* parent); 			// ������ ��� ���� parent, (�������� �������� � �������)
	void setStatus(int digit);				// ������ ��� ���� status, (�������� ��������� � �������)

	void setConnect(typeSignal signal, Base* obj, typeHandler handler);		// ����� ������������ ����� ����� �������� �������� ������� � ������������ �������� �������
	void deleteConnect(typeSignal signal, Base* obj, typeHandler handler);	// ����� �������� (�������) ����� ����� �������� �������� ������� � ������������ �������� �������
	void emitConnect(typeSignal signal, std::string command);				// ����� ������ ������� �� �������� ������� � ��������� ��������� ����������. ���������� ������ ����� ������ ��� ���������� ������

	int getStatus();						// ������ ��� ���� status, (������ ��������� � �������)
	std::string getName(); 					// ������ ��� ���� name, (������ ��� �������)
	std::string getAbsolutePath();			// ������ (�����) ��������� ������� ���� �� �������
	Base* getParent(); 						// ������ ��� ���� parent, (������ �������� �������)
	Base* searchByName(std::string name);	// ����� ������� �� �����, (���� ������ ������ ������ ��������� �� ����, ���� �� ������ ������ nullptr)
	Base* searchByPath(std::string path);	// ����� ������� �� ����, (���� ������ ������ ������ ��������� �� ����, ���� �� ������ ������ nullptr)

	// static File file;
	static std::fstream file;

private:
	int status = 0;							// ��������� �������, (��������, �������)
	std::string name = "";					// ������������ ������� (���������� ����)
	Base* parent = nullptr;					// ��������� �� �������� ������
	std::vector<Base*> children;			// ��������� ���������� �� �������, ����������� � �������� ������� � ������ ��������.
	std::vector<StructConnect*> connects;	// ��������� �������������� ������

											// ����� ������� �� ����, (���� ������ ������ ������ ��������� �� ����, ���� �� ������ ������ nullptr)
	Base* searchByPath(Base* obj, std::vector<std::string> &arrNames, int currentIndex);
};

#endif

*/


static std::string PATH_INPUT =
"System\n"
"/ FileOperations 2\n"
"/ ReaderCommands 3\n"
"/ Mover 4\n"
"/Mover Writer 5\n"
"/ ErrorWriter 6\n"
"/ ConsoleWriter 7\n"
"endtree\n"
"/FileOperations / createFile handlerFile\n"
"/ReaderCommands /Mover readCommand MoveHandlerCommand\n"
"/ReaderCommands /Mover readCommand handlerMove\n"
"/ReaderCommands /Mover/Writer readCommand handlerWrite\n"
"/ReaderCommands /Mover readCommand moveToBegin\n"
"/ReaderCommands /ConsoleWriter readCommand handler_write_to_console\n"
"/ReaderCommands /Mover readCommand moveToEnd\n"
"/ReaderCommands /ErrorWriter readCommand handlerError\n"
"/ReaderCommands / readCommand handlerEnd\n"
"/Mover /Mover MoveSignal moveToEnd\n"
"/Mover /ErrorWriter MoveSignal handlerError\n"
"/Mover/Writer /Mover signalWrite moveToEnd\n"
"/Mover/Writer /ErrorWriter signalWrite handlerError\n"
"end_of_connections";

class System;
class App;
class Base;
typedef void(Base::* typeSignal)(std::string&);
typedef void(Base::* typeHandler)(std::string);
#define SIGNAL( function ) ( typeSignal ) ( &function )
#define HANDLER( function ) ( typeHandler ) ( &function )
struct StructConnect
{
	typeSignal signal;
	Base* obj;
	typeHandler handler;
};
class Base
{
	friend class App;
	friend class System;
public:
	Base(Base* parent, std::string name = "root");	// �����������
	virtual ~Base();								// ����������
	void printObjects(); 					// ������� �� ����� �������� � �������� ������ ���� � ����� �� �����
	void printStatusObjects(int deep = 0);	// ������� ������ ��������� ��������
	void printTreeObjects(int deep = 0);	// ������� �� ����� ����� ��������
	void setName(std::string name);			// ������ ��� ���� name, (�������� ��� � �������)
	void setParent(Base* parent); 			// ������ ��� ���� parent, (�������� �������� � �������)
	void setStatus(int digit);				// ������ ��� ���� status, (�������� ��������� � �������)
	void setConnect(typeSignal signal, Base* obj, typeHandler handler);		// ����� ������������ ����� ����� �������� �������� ������� � ������������ �������� �������
	void deleteConnect(typeSignal signal, Base* obj, typeHandler handler);	// ����� �������� (�������) ����� ����� �������� �������� ������� � ������������ �������� �������
	void emitConnect(typeSignal signal, std::string command);				// ����� ������ ������� �� �������� ������� � ��������� ��������� ����������. ���������� ������ ����� ������ ��� ���������� ������
	int getStatus();						// ������ ��� ���� status, (������ ��������� � �������)
	std::string getName(); 					// ������ ��� ���� name, (������ ��� �������)
	std::string getAbsolutePath();			// ������ (�����) ��������� ������� ���� �� �������
	Base* getParent(); 						// ������ ��� ���� parent, (������ �������� �������)
	Base* searchByName(std::string name);	// ����� ������� �� �����, (���� ������ ������ ������ ��������� �� ����, ���� �� ������ ������ nullptr)
	Base* searchByPath(std::string path);	// ����� ������� �� ����, (���� ������ ������ ������ ��������� �� ����, ���� �� ������ ������ nullptr)
	// static File file;
	static std::fstream file;
private:
	int status = 0;							// ��������� �������, (��������, �������)
	std::string name = "";					// ������������ ������� (���������� ����)
	Base* parent = nullptr;					// ��������� �� �������� ������
	std::vector<Base*> children;			// ��������� ���������� �� �������, ����������� � �������� ������� � ������ ��������.
	std::vector<StructConnect*> connects;	// ��������� �������������� ������
											// ����� ������� �� ����, (���� ������ ������ ������ ��������� �� ����, ���� �� ������ ������ nullptr)
	Base* searchByPath(Base* obj, std::vector<std::string>& arrNames, int currentIndex);
};
#endif

