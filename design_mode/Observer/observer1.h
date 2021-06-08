#include <iostream>
#include <string>
#include <list>

namespace observer_mode
{
	class Subject;

#pragma region Observer
	//抽象观察者
	class Observer
	{
	protected:
		std::string name;
		Subject *sub;
	public:
		Observer(std::string name, Subject *sub);
		virtual void update() = 0;
		virtual ~Observer() {}
	};
	//具体的观察者，看股票的
	class StockObserver :public Observer
	{
	public:
		StockObserver(std::string name, Subject *sub) :Observer(name, sub){}
		void update();
	};
	//具体的观察者，看NBA的
	class NBAObserver :public Observer
	{
	public:
		NBAObserver(std::string name, Subject *sub) :Observer(name, sub){}
		void update();
	};
#pragma endregion Observer

#pragma region Subject
	//抽象通知者
	class Subject
	{
	protected:
		std::list<Observer*> observers;
	public:
		std::string action;
		virtual void attach(Observer*) = 0;
		virtual void detach(Observer*) = 0;
		virtual void notify() = 0;
		virtual ~Subject() {}
	};
	//具体通知者，秘书
	class Secretary :public Subject
	{
		void attach(Observer *observer);
		void detach(Observer *observer);
		void notify();
	};
#pragma endregion Subject
} //namespace observer_mode