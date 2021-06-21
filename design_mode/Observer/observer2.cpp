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

	void StatisticDisplay::update(Observable *observable)
	{
		if (observable->changed_)
		{
			WeatherData* weather_data = static_cast<WeatherData*>(observable);
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

	void GeneralDisplay::update(Observable *observable)
	{
		if (observable->changed_)
		{
			WeatherData* weather_data = static_cast<WeatherData*>(observable);
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

	void ForecastDisplay::update(Observable *observable)
	{
		if (observable->changed_)
		{
			WeatherData* weather_data = static_cast<WeatherData*>(observable);
			observable_->temperature_ = weather_data->get_temperature();
			observable_->pressure_ = weather_data->get_pressure();
		}
		display();
	}
#pragma endregion Observer

#pragma region Subject

	Observable::Observable()
	{
		changed_ = false;
	}
	WeatherData::WeatherData()
	{
		temperature_ = 0.0;
		humidity_    = 0.0;
		pressure_    = 0.0;
	}
	void WeatherData::set_changed()
	{
		changed_ = true;
	}

	void WeatherData::clear_changed()
	{
		changed_ = false;
	}

	bool WeatherData::has_changed()
	{
		return changed_;
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

	void WeatherData::notify_observer(Observable* observer)
	{
		if (changed_)
		{
			std::list<Observer2*>::iterator iter = observers.begin();
			while (iter != observers.end())
			{
				(*iter)->update(observer);
				++iter;
			}
			changed_ = false;
		}
	}
	void WeatherData::measurements_changed(Observable* observer)
	{
		set_changed();
		notify_observer(observer);
	}

	void WeatherData::set_measurements(const float temperature,
		const float humidity,
		const float pressure)
	{
		Observable * observable;
		observable->temperature_ = temperature;
		observable->humidity_ = humidity;
		observable->pressure_ = pressure;
		observable->changed_ = true;
		measurements_changed(observable);

	}

#pragma endregion Subject
} // namespace observer_mode