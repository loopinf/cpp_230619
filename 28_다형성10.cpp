// 28_다형성8.cpp
#include <iostream>
#include <vector>
using namespace std;

#include <mutex>

mutex m;

class Shape {
public:
    virtual ~Shape() { }

    // 변하는 것은 자식이 가상함수를 통해 재정의하고, 변하지 않는 것은
    // 부모가 템플릿 메소드를 제공합니다.
    // virtual void Draw() const final

    // NVI(Non Virtual Interface)
    void Draw() const
    {
        m.lock();
        DrawImpl();
        m.unlock();
    }

protected:
    virtual void DrawImpl() const = 0;
};

class Rect : public Shape {
protected:
    void DrawImpl() const override
    {
        cout << "Draw Rect" << endl;
    }
};

class Circle : public Shape {
protected:
    void DrawImpl() const override { cout << "Draw Circle" << endl; }
};

// 새로운 도형의 추가
class Triangle : public Shape {
protected:
    void DrawImpl() const override { cout << "Triangle Circle" << endl; }
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
        } else if (cmd == 3) {
            shapes.push_back(new Triangle);
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
