#include <iostream>
using namespace std;

namespace aaa {
class Shape {
    int a;

public:
    virtual void Draw() { }
};
}

class Rect : public aaa::Shape {
};

int main()
{
    aaa::Shape s1;
    s1.Draw(); // Shape::Draw(&s1);

    printf("%p\n", &aaa::Shape::Draw);
}
