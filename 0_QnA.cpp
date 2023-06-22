#include <iostream>
using namespace std;

class Shape {
    int a;

public:
    virtual void Draw() { }
};

int main()
{
    Shape s1;
    s1.Draw(); // Shape::Draw(&s1);

    printf("%p\n", &Shape::Draw);
}
