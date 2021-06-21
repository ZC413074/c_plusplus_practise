#include"./../Observer/observer1.h"
#include"./Observer//observer2.h"
using namespace observer_mode;
void observer_test()
{
	/// example 1
	//Subject *dwq = new Secretary(); //创建观察者<br>　　　　//被观察的对象
	//Observer *xs = new NBAObserver("xiaoshuai", dwq);
	//Observer *zy = new NBAObserver("zouyue", dwq);
	//Observer *lm = new StockObserver("limin", dwq);
	//dwq->attach(xs);
	//dwq->attach(zy);
	//dwq->attach(lm);
	//dwq->action = "going to have lunch";
	//dwq->notify();
	//std::cout << std::endl;
	//dwq->action = "liang is comming";
	//dwq->notify();

	/// example 2

	Observable *observable= new WeatherData();
	Observer2 *viewer1 = new StatisticDisplay(observable);
	Observer2 *viewer2 = new GeneralDisplay(observable);
	Observer2 *viewer3 = new ForecastDisplay(observable);
	observable->add_observer(viewer1);
	observable->add_observer(viewer2);
	observable->add_observer(viewer3);
	for (int i = 0; i < 10; ++i)
	{
		std::cout << "i=" << i << "\n";
		float temperature = 36.5 + float(i), humidity = 10.1 + float(i), pressure = 100.0 + float(i);
		observable->set_measurements(temperature, humidity, pressure);
		observable->notify_observer(observable);
	}

}