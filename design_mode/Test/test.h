#include"./../Observer/observer1.h"
using namespace observer_mode;
void observer_test()
{
	Subject *dwq = new Secretary(); //�����۲���<br>��������//���۲�Ķ���
	Observer *xs = new NBAObserver("xiaoshuai", dwq);
	Observer *zy = new NBAObserver("zouyue", dwq);
	Observer *lm = new StockObserver("limin", dwq);
	dwq->attach(xs);
	dwq->attach(zy);
	dwq->attach(lm);
	dwq->action = "going to have lunch";
	dwq->notify();
	std::cout << std::endl;
	dwq->action = "liang is comming";
	dwq->notify();
}