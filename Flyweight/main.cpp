#include "Flyweight.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{
    string externState = "extern";

    FlyweightFactory* fc = new FlyweightFactory();

    Flyweight* fly = fc->GetFlyweight("hello");

    Flyweight* fly1 = fc->GetFlyweight("hello");
    //fly fly1 share one addres

    //应用外部状态
    fly1->Operation(externState);

    fc->GetFlyweightCount();

    return 0;
}