#include <iostream>
using namespace std;

#include "Car.h"

void foo();

int main()
{
    Car car[3];
    cout << car[0].GetCount() << endl;

    foo();
    cout << car[0].GetCount() << endl;
}
