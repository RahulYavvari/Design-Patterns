#include <iostream>
#include <vector>
#include <algorithm>


class IObserver
{
public:
	virtual void update() = 0;
};

class IObservable
{
public:
	virtual void add(IObserver* o) = 0;
	virtual void remove(IObserver* o) = 0;
	virtual void notify() = 0;
};


class ConcreteObservable: public IObservable
{
public:
	double temperature;
	std::vector<IObserver*> observer_list;

	ConcreteObservable() : temperature(-273.0) {}

	void add(IObserver* o) override
	{
		observer_list.push_back(o);
	}

	void remove(IObserver* o) override
	{
		observer_list.erase(std::remove(observer_list.begin(), observer_list.end(), o), observer_list.end());
	}

	void notify() override
	{
		for (IObserver* observer : observer_list)
		{
			observer->update();
		}
	}

	double get_state()
	{
		return this->temperature;
	}

	void set_state(double temp)
	{
		this->temperature = temp;
	}
};

class ConcreteObserver: public IObserver
{
private:
	double rx_temp;
	ConcreteObservable* observable;
public:

	ConcreteObserver(ConcreteObservable* co) : observable(co), rx_temp(-273.0) {}

	void update() override
	{
		rx_temp = observable->get_state();
		this->display();
	}

	double get_temperature()
	{
		return rx_temp;
	}

	void display()
	{
		std::cout << "[TEMP]: " << rx_temp << std::endl;
	}
};

int main()
{
	ConcreteObservable* WeatherStation = new ConcreteObservable();

	ConcreteObserver* user1 = new ConcreteObserver(WeatherStation);
	ConcreteObserver* user2 = new ConcreteObserver(WeatherStation);
	ConcreteObserver* user3 = new ConcreteObserver(WeatherStation);
	ConcreteObserver* user4 = new ConcreteObserver(WeatherStation);
	ConcreteObserver* user5 = new ConcreteObserver(WeatherStation);

	WeatherStation->add(user1);
	WeatherStation->add(user2);
	WeatherStation->add(user3);
	WeatherStation->add(user4);
	WeatherStation->add(user5);

	WeatherStation->set_state(27.8946);
	WeatherStation->notify();

	delete WeatherStation;
	delete user1, user2, user3, user4, user5;
}