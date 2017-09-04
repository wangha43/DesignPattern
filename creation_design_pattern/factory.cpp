#include <string>
#include <stdexcept>
#include <iostream>
#include <memory>

using namespace std;

// class Pizza
// {
// public:
// 	void setDough(const string & dough)
// 	{
// 		m_dough = dough;
// 	}

// 	void setSayce(const string & sauce)
// 	{
// 		m_sauce = sauce;
// 	}

// 	void setTopping(const string & topping)
// 	{
// 		m_topping = topping;
// 	}

// 	void open()const
// 	{
// 		cout << "" <<;
// 	}

// private:
// 	string m_dough;
// 	string m_sauce;
// 	string m_topping;
// };

class Pizza
{
public:
	virtual int getPrice() const;
	virtual ~Pizza(){cout << "eating" <<endl;}; 
};

class HamAndMushroomPizza:public Pizza
{
public:
	virtual int getPrice() const
	{
		return 850;
	}
	virtual ~HamAndMushroomPizza(){cout << "eaten" <<endl;};
};

class DeluxePizza:public Pizza
{
public:
	virtual int getPrice() const
	{
		return 1050;
	}
	virtual ~DeluxePizza(){cout << "eaten" <<endl;};
};

class HahawaiianPizza:public Pizza
{
public:
	virtual int getPrice() const
	{
		return 1150;
	}
	virtual ~HahawaiianPizza(){
		cout << "eaten" <<endl;
	};	
};


class PizzaFactory
{
public:
	enum PizzaType
	{
		HamAndMushroom,
		Deluxe,
		Hahawaiian
	};

	static unique_ptr<Pizza> createPizza(PizzaType pizzaType)
	{
		switch(pizzaType)
		{
			case HamAndMushroom:
				return make_unique<HamAndMushroomPizza>();
			case Deluxe:
				return make_unique<DeluxePizza>();
			case Hahawaiian:
				return make_unique<HahawaiianPizza>();
		}
		throw "invalid pizza type";
	}
};

void pizza_information(PizzaFactory::PizzaType pizzatype)
{
	unique_ptr<Pizza> pizza = PizzaFactory::createPizza(pizzatype);
	cout << "Price of "<<pizzatype <<" is " << pizza->getPrice() <<endl;
}

int main()
{
	pizza_information(PizzaFactory::HamAndMushroom);
	return 0;
}