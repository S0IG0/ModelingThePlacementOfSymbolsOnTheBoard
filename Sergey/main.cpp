#include "System.h"
int main()
{
	System system(nullptr);
	system.build_tree_of_paths();
	return system.exec_app();
}
