// 33_STL6.cpp
#include <iostream>
#include <string>
using namespace std;

#if 0
class Sample {
    int data = 100;

public:
    void foo() { cout << "foo" << endl; }
    void goo() { cout << "goo" << endl; }

    void go()
    {
        // 람다 표현식 안에서 멤버 함수 또는 멤버 데이터에
        // 접근하기 위해서는 this를 캡쳐해야 합니다.
        auto fn = [this] {
            foo();
            goo();

            cout << data << endl;
        };

        fn();
    }
};

int main()
{
    Sample s;
    s.go();
}
#endif

#include <functional>
// : function
// => 범용 함수 포인터

class Button {
    string name;

    function<void()> handler;

public:
    Button(const string& s)
        : name { s }
    {
    }

    void SetHandler(function<void()> h)
    {
        handler = h;
    }

    void Click()
    {
        handler();
    }
};

void foo() { cout << "foo" << endl; }

class Window {
public:
    // void Close(Window* this)
    void Close()
    {
        cout << "Window close" << endl;
    }
};

int main()
{
    Button button("닫기");
    Window window;

    button.SetHandler(foo);
    button.SetHandler([] {
        cout << "lambda" << endl;
    });

    button.SetHandler(bind(&Window::Close, window));

    // bind(&Window::Close, window);

    button.Click();
}
