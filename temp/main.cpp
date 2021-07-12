#include"test.h"
#include<chrono>
#include<ctime>
#include<windows.h>
#include<vector>
enum DesignMode
{
	kObserver = 1

};

int main()
{
	std::cout << "\ncontainer_test: " << "\n";
	container_test();

	std::cout << "\nallocator_test: " << "\n";
	allocator_test();
	return 0;
}