#include"observer1.h"
namespace observer_mode
{
#pragma region Observer
	//抽象观察者
	Observer::Observer(std::string name, Subject *sub)
	{
		this->name = name;
		this->sub = sub;
	}
	void StockObserver::update()
	{
		std::cout << name << " got it : " << sub->action << std::endl;
		if (sub->action == "liang is comming")
		{
			std::cout << "close stock and work" << std::endl;
		}
	}

	void NBAObserver::update()
	{
		std::cout << name << " got it : " << sub->action << std::endl;
		if (sub->action == "liang is comming")
		{
			std::cout << "close NBA and work" << std::endl;
		}
	}
#pragma endregion Observer

#pragma region Subject
	//具体通知者，秘书
	void Secretary::attach(Observer *observer)
	{
		observers.push_back(observer);
	}

	void Secretary::detach(Observer *observer)
	{
		std::list<Observer *>::iterator iter = observers.begin();
		while (iter != observers.end())
		{
			if ((*iter) == observer)
			{
				observers.erase(iter);
			}
			++iter;
		}
	}

	void Secretary::notify()
	{
		std::list<Observer *>::iterator iter = observers.begin();
		while (iter != observers.end())
		{
			(*iter)->update();
			++iter;
		}
	}
#pragma endregion Subject
} // namespace observer_mode