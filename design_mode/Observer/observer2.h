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
		Observable *observable_;
	public:
		Observer2() {}
		virtual void update() = 0;
		virtual ~Observer2() {}
	};

	class StatisticDisplay :public Observer2
	{
	public:
		void display();
		void update(Observable *observable);
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
		float temperature_;
		float humidity_;
		float pressure_;
		bool changed;
		std::list<Observer2*> observers;
	public:
		Observable();
		virtual void add_observer(Observer2*) = 0;
		virtual void delete_observer(Observer2*) = 0;
		virtual void notify_observer() = 0;
		virtual void set_changed() = 0;
		virtual void clear_changed() = 0;
		virtual bool has_changed() = 0;
		virtual ~Observable() {}
	};

	class WeatherData :public Observable
	{
	public:

		WeatherData();

		void set_changed();

		void clear_changed();

		bool has_changed();

		float get_temperature();

		float get_humidity();

		float get_pressure();

		void add_observer(Observer2* observer);

		void delete_observer(Observer2* observer);

		void notify_observer();

		void measurements_changed();

		void set_measurements(const float temperature, 
			const float humidity, 
			const float pressure);
	};
#pragma endregion Observable

} //namespace observer_mode