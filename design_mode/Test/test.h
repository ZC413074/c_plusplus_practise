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
	float temperature = 36.5, humidity = 10.1, pressure = 100.0;
	WeatherData *weather_observable = new WeatherData();
	weather_observable->set_measurements(temperature,humidity,pressure);
	weather_observable->set_changed();


	Observable *observable = weather_observable;
	Observer2 *viewer1 = new StatisticDisplay(observable);

}