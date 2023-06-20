// 16_stack8.cpp
#include <iostream>
using namespace std;

#include "stack.h"

int main()
{
    Stack s1(100);

    s1.push(10);
    s1.push(20);
    s1.push(30);

    cout << s1.pop() << endl;
    cout << s1.pop() << endl;
    cout << s1.pop() << endl;
}
