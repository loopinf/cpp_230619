// 28_다형성9.cpp
#include <iostream>
#include <vector>
using namespace std;

// 1. Refactoring
//  > Replace type code with polymorphism
//    마틴 파울러, 리팩토링
//    => 코드의 유지보수성을 떨어뜨리는 요소, 코드 냄새
//    => 동작을 변경하지 않고, 기존 코드의 구조를 개선하는 작업

// 2. 복제를 다형적으로 구현할 수 있습니다.
//  => Prototype Pattern

class Shape {
public:
    int type;
    virtual ~Shape() { }

    virtual void Draw() const { cout << "Draw Shape" << endl; }

    virtual Shape* Clone() const { return new Shape(*this); }
};

class Rect : public Shape {
public:
    void Draw() const override { cout << "Draw Rect" << endl; }

    Shape* Clone() const override
    {
        return new Rect(*this);
    }
};

class Circle : public Shape {
public:
    void Draw() const override { cout << "Draw Circle" << endl; }

    Shape* Clone() const override
    {
        return new Circle(*this);
    }
};

int main()
{
    vector<Shape*> shapes;

    while (1) {
        int cmd;
        cin >> cmd;

        if (cmd == 1) {
            shapes.push_back(new Rect);
        } else if (cmd == 2) {
            shapes.push_back(new Circle);
        }

        else if (cmd == 8) {
            int index;
            cout << "몇번째 도형";
            cin >> index;

            Shape* p = shapes[index];
            shapes.push_back(p->Clone());

#if 0
            if (p->type == 0) {
                // ..
            } else if (p->type == 1) {
                // ..
            }
#endif
        }

        else if (cmd == 9) {
            for (auto e : shapes) {
                e->Draw();
                // 다형성(polymorphism)

                // Draw  ---> Rect  --> Rect::Draw
                //           Circle --> Circle::Draw
                //         Triangle --> Triangle::Draw
            }
        } else if (cmd == 0) {
            break;
        }
    }

    for (auto e : shapes) {
        delete e;
    }
}
