#include"test.h"
using namespace observer_mode;
enum DesignMode
{
	kObserver = 1

};

int main()
{
	int mode = DesignMode::kObserver;
	switch (mode)
	{
	case 1:	observer_test();

	default:
		break;
	}

	return 0;
}