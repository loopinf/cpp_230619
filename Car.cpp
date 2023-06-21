// Car.cpp
#include "Car.h"

// 정적 멤버 변수 정의
int Car::cnt = 0;

Car::Car()
{
    cnt++;
}

Car::~Car()
{
    cnt--;
}

int Car::GetCount()
{
    return cnt;
}
