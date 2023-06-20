// 22_복사생성자2.cpp
#include <iostream>
using namespace std;

class Sample {
public:
    Sample() { cout << "Sample()" << endl; }
    ~Sample() { cout << "~Sample()" << endl; }

    Sample(const Sample&) { cout << "Sample(const Sample&)" << endl; }
};

// 복사 생성자
// 1) 함수의 인자로 객체가 call by value로 전달될 때
// void foo(Sample s)
#if 0
void foo(const Sample& s)
{
}


int main()
{
    Sample s;
    cout << "-----------------------" << endl;
    foo(s);
    cout << "-----------------------" << endl;
}
#endif

// 2) 함수가 객체를 값으로 반환할 때
Sample s;
// Sample foo()
Sample& foo()
{
    return s; // 반환용 임시 객체가 생성됩니다. - 복사 생성자 호출
}

int main()
{
    cout << "-----------------------" << endl;
    foo(); // 반환용 임시 객체가 파괴됩니다.
    cout << "-----------------------" << endl;
}
