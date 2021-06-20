#include"observer2.h"
namespace observer_mode
{
#pragma region Observer
	Observer2::Observer2(Observable *observable)
	{
		this->observable_ = observable;
	}

	StatisticDisplay::StatisticDisplay(Observable *observable)
	{
		this->observable_ = observable;
	}

	void StatisticDisplay::display()
	{
		std::cout << "StatisticDisplay:temperature= " << observable_->temperature_;
		std::cout << ", humidity= " << observable_->humidity_ << std::endl;
	}

	void StatisticDisplay::update(Observable *observables)
	{
		observable_ = observables;
		if (observables->changed)
		{
			WeatherData* weather_data = static_cast<WeatherData*>(observables);
			observable_->temperature_ = weather_data->get_temperature();
			observable_->humidity_ = weather_data->get_humidity();
		}
		display();
	}

	GeneralDisplay::GeneralDisplay(Observable *observable)
	{
		this->observable_ = observable;
	}

	void GeneralDisplay::display()
	{
		std::cout << "GeneralDisplays:temperature= " << observable_->temperature_;
		std::cout << ", humidity= " << observable_->humidity_;
		std::cout << ", pressure= " << observable_->pressure_ << std::endl;
	}

	void GeneralDisplay::update(Observable *observables)
	{
		observable_ = observables;
		if (observables->changed)
		{
			WeatherData* weather_data = static_cast<WeatherData*>(observables);
			observable_->temperature_ = weather_data->get_temperature();
			observable_->humidity_ = weather_data->get_humidity();
			observable_->pressure_ = weather_data->get_pressure();
		}
		display();
	}

	ForecastDisplay::ForecastDisplay(Observable *observable)
	{
		this->observable_ = observable;
	}

	void ForecastDisplay::display()
	{
		std::cout << "ForecastDisplay:temperature= " << observable_->temperature_;
		std::cout << ", pressure= " << observable_->pressure_ << std::endl;
	}

	void ForecastDisplay::update(Observable *observables)
	{
		observable_ = observables;
		if (observables->changed)
		{
			WeatherData* weather_data = static_cast<WeatherData*>(observables);
			observable_->temperature_ = weather_data->get_temperature();
			observable_->humidity_ = weather_data->get_humidity();
			observable_->pressure_ = weather_data->get_pressure();
		}
		display();
	}
#pragma endregion Observer

#pragma region Subject

	Observable::Observable()
	{
		changed = false;
	}
	WeatherData::WeatherData()
	{
		temperature_ = 0.0;
		humidity_    = 0.0;
		pressure_    = 0.0;
	}
	void WeatherData::set_changed()
	{
		changed = true;
	}

	void WeatherData::clear_changed()
	{
		changed = false;
	}

	bool WeatherData::has_changed()
	{
		return changed;
	}

	float WeatherData::get_temperature()
	{
		return temperature_;
	}

	float WeatherData::get_humidity()
	{
		return humidity_;
	}

	float WeatherData::get_pressure()
	{
		return pressure_;
	}

	void WeatherData::add_observer(Observer2* observer)
	{
		observers.push_back(observer);
	}

	void WeatherData::delete_observer(Observer2* observer)
	{
			std::list<Observer2*>::iterator iter = observers.begin();
			while (iter != observers.end())
			{
				if ((*iter) == observer)
				{
					observers.erase(iter);
				}
				++iter;
			}
	}

	void WeatherData::notify_observer()
	{
		if (changed)
		{
			std::list<Observer2*>::iterator iter = observers.begin();
			while (iter != observers.end())
			{
				(*iter)->update();
				++iter;
			}
			changed = false;
		}
	}
	void WeatherData::measurements_changed()
	{
		set_changed();
		notify_observer();
	}

	void WeatherData::set_measurements(const float temperature,
		const float humidity,
		const float pressure)
	{
		temperature_ = temperature;
		humidity_ = humidity;
		pressure_ = pressure;
		measurements_changed();

	}

#pragma endregion Subject
} // namespace observer_mode