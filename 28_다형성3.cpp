// 28_다형성3.c
#include <iostream>
#include <vector>
using namespace std;

class Animal { };
class Dog : public Animal { };
class Cat : public Animal { };

int main()
{
    // 동종을 보관하는 컨테이너
    vector<Animal*> animals;

    animals.push_back(new Dog);
    animals.push_back(new Cat);
}

#if 0
class Dog { };
class Cat { };

int main()
{
    vector<Dog*> dogs;
    vector<Cat*> cats;
}
#endif
