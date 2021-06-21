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
		Observer2(Observable *observable);
		virtual void update(Observable *observable) = 0;
		virtual ~Observer2() {}
	};

	class StatisticDisplay :public Observer2
	{
	public:
		StatisticDisplay(Observable *observable);
		void display();
		void update(Observable *observable);
	};

	class GeneralDisplay :public Observer2
	{
	public:
		GeneralDisplay(Observable *observable);
		void update(Observable *observable);
		void display();
	};

	class ForecastDisplay :public Observer2
	{
	public:
		ForecastDisplay(Observable *observable);
		void update(Observable *observable);
		void display();
	};
#pragma endregion Observer

#pragma region Observable
	/*!

	*/
	class Observable
	{
	public:
		Observable();
		virtual void add_observer(Observer2*) = 0;
		virtual void delete_observer(Observer2*) = 0;
		virtual void notify_observer(Observable* observer) = 0;
		virtual void set_measurements(const float temperature,
			const float humidity,
			const float pressure) = 0;
		virtual ~Observable() {}

	protected:
		std::list<Observer2*> observers;
	public:
		bool changed_;
		float temperature_;
		float humidity_;
		float pressure_;
	};

	class WeatherData :public Observable
	{

	public:
		WeatherData();

		void add_observer(Observer2* observer);

		void delete_observer(Observer2* observer);

		void notify_observer(Observable* observer);

		void set_changed();

		void clear_changed();

		bool has_changed();

		float get_temperature();

		float get_humidity();

		float get_pressure();

		void measurements_changed(Observable* observer);

		void set_measurements(const float temperature, 
			const float humidity, 
			const float pressure);
	};
#pragma endregion Observable

} //namespace observer_mode