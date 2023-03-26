#ifndef APP_H
#define APP_H

#include "Base.h"
#include "Object_1.h"
#include "Object_2.h"
#include "Object_3.h"
#include "Object_4.h"
#include "Object_5.h"

class App : public Base
{
public:
	App(Base* parent, std::string name = "root");

	void read_commands();				//	Считывание комманд (FIND, SET, END)
	void read_commands_connects();		//	Считывание комманд (SET_CONNECT, DELETE_CONNECT, SET_CONDITION, EMIT, END)
	void set_connects();				//  Сохранение связей между объектами
	void bild_tree_objects();			//	Построение дерева по уникальным именам
	void bild_tree_objects_of_paths();	//	Построение дерева по путями в объектам ("obj_1/obj2/obj6")
	void signal(std::string& data); 	//	Выдать сигнал
	void handler(std::string data); 	//	Обработать сигнал

	int exec_app();						//	Основной алгоритм для уникальных имен
	int exec_app_of_paths();			//	Основной алгоритм для построения дерева по путям
	int exec_app_of_paths_connects();	//	Основной алгоритм для построения дерева по путям и создание связей с объектами 
	int detect_obj(Base* obj);			//	Определение класса объекта

private:
	bool successful = true;				//	Успешность построения дерева
	void on_all(Base* obj);				//	Включает все объекты на древе

	typeSignal typeSignalData[6] = {
		SIGNAL(App::signal),
		SIGNAL(Object_1::signal),
		SIGNAL(Object_2::signal),
		SIGNAL(Object_3::signal),
		SIGNAL(Object_4::signal),
		SIGNAL(Object_5::signal),
	};

	typeHandler typeHandlerData[6] = {
		HANDLER(App::handler),
		HANDLER(Object_1::handler),
		HANDLER(Object_2::handler),
		HANDLER(Object_3::handler),
		HANDLER(Object_4::handler),
		HANDLER(Object_5::handler),
	};
};

#endif