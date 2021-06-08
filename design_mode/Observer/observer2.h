#include <iostream>
#include <string>
#include <list>
namespace observer_mode
{
	class Observable;

#pragma region Observer2
	class Observer2
	{
	protected:
		std::string name;
		Observable *observable;
	public:
		Observer2(std::string name, Observable *sub);
		virtual void update() = 0;
		virtual ~Observer2() {}
	};

	class StatisticDisplay :public Observer2
	{
	public:
		void update();
		void display();
	};

	class GeneralDisplay :public Observer2
	{
	public:
		void update();
		void display();
	};

	class ForecastDisplay :public Observer2
	{
	public:
		void update();
		void display();
	};
#pragma endregion Observer

#pragma region Observable
	class Observable
	{
	protected:
		std::list<Observer2*> observers;
	public:
		virtual void add_observer(Observer2*) = 0;
		virtual void delete_observer(Observer2*) = 0;
		virtual void notify_observer() = 0;
		virtual void set_changed() = 0;
		virtual ~Observable() {}
	};
	class WeatherData :public Observable
	{
		float get_temperature();
		float get_humidity();
		float get_pressure();
	};
#pragma endregion Observable

} //namespace observer_mode