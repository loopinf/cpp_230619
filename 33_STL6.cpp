// 33_STL6.cpp
#include <iostream>
using namespace std;

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
