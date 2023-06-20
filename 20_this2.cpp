// 20_this2.cpp
#include <iostream>
using namespace std;

class Sample {
    int data = 42;

public:
    // void f1(Sample* this)
    void f1() { cout << "f1" << endl; }

    int f2()
    {
        cout << "f2" << endl;
        return 42;
    }

    int f3()
    {
        cout << "f3" << endl;
        return data;
        //     this->data
    }

    //  MFC: GetHwnd / GetSafeHwnd
    // AOSP
    int f4()
    {
        if (this == nullptr)
            return 0;
        else
            return data;
    }
};

int main()
{
    Sample* p = nullptr;

    p->f1(); // Sample::f1(p); Sample::f1(nullptr)
    p->f2();

    p->f3();
}
