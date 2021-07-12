#include"test.h"
#include<chrono>
#include<ctime>
#include<windows.h>
using namespace observer_mode;
enum DesignMode
{
	kObserver = 1

};

int main()
{

	for (int i = 0; i < 10; ++i)
	{
		
    using namespace std::chrono;  
  
    high_resolution_clock::time_point t1 = high_resolution_clock::now();  
  
    std::cout << "printing out 1000 stars...\n";  
    for (int i = 0; i<10; ++i) std::cout << "*";  
    std::cout << std::endl;  
    high_resolution_clock::time_point t2 = high_resolution_clock::now();  

    duration<double> time_span = duration_cast<duration<double>>(t2 - t1);  
    //std::cout << "It took me " << time_span.count() << " seconds.";  
	std::cout << t2.time_since_epoch().count()%1000 << std::endl;
    std::cout << std::endl;  
	}

	int mode = DesignMode::kObserver;
	switch (mode)
	{
	case 1:	observer_test();

	default:
		break;
	}

	return 0;
}