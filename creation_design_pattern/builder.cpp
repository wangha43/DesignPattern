#include <string>
#include <iostream>
#include <memory>

using namespace std;

class Pizza
{
public:
    void setDough(const string & dough)
    {
        m_dough = dough;
    }

    void setSauce(const string & sauce)
    {
        m_sauce = sauce;
    }

    void setTopping(const string & topping)
    {
        m_topping = topping;
    }

    void open()const
    {
        cout << "Pizza with " << m_dough << " dough, " << m_sauce << " sauce and "
            << m_topping << " topping. Mmm." << endl;
    }

private:
    string m_dough;
    string m_sauce;
    string m_topping;
};
//product pizza

//Abstract base builder
class PizzaBuilder
{
public:
    virtual ~PizzaBuilder(){};

    Pizza * getPizza()
    {
        return m_pizza.release();
    }

    void createNewPizzaProduct()
    {
        m_pizza = std::make_unique<Pizza>();
    }

    virtual void builderDough()=0;
    virtual void buildSauce()=0;
    virtual void buildTopping()=0;

protected:
    unique_ptr<Pizza> m_pizza;
};


//---------------------------------//
//specific builder
class HawaiianPizzaBuilder : public PizzaBuilder
{
public:
    virtual ~HawaiianPizzaBuilder(){};

    virtual void builderDough()
    {
        m_pizza->setDough("cross");
    }

    virtual void buildSauce()
    {
        m_pizza->setSauce("mild");
    }

    virtual void buildTopping()
    {
        m_pizza->setTopping("ham+pineapple");
    }
};

class SpicyPizzaBuilder : public PizzaBuilder
{
public:
    virtual ~SpicyPizzaBuilder() {};

    virtual void builderDough()
    {
        m_pizza->setDough("pan baked");
    }
    virtual void buildSauce()
    {
        m_pizza->setSauce("hot");
    }
    virtual void buildTopping()
    {
        m_pizza->setTopping("pepperoni+salami");
    }
};

class Cook
{
  public:
    void openPizza()
    {
        m_pizzaBuilder->getPizza()->open();
        //unique_ptr---base virtual pizza class open
    }

    void makePizza(PizzaBuilder *pb)
    {
        m_pizzaBuilder = pb;
        m_pizzaBuilder->createNewPizzaProduct();
        m_pizzaBuilder->builderDough();
        m_pizzaBuilder->buildSauce();
        m_pizzaBuilder->buildTopping();
    }

private:
    PizzaBuilder * m_pizzaBuilder;
};


int main()
{
    Cook cook;
    HawaiianPizzaBuilder hawaiianPizzaBuilder;
    SpicyPizzaBuilder sp;

    cook.makePizza(&hawaiianPizzaBuilder);
    cook.openPizza();

    cook.makePizza(&sp);
    cook.openPizza();
    return 0;
}
