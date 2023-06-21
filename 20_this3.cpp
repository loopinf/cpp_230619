// 20_this3.cpp
#include <iostream>
using namespace std;

#if 0
// private 소멸자 의도
// : 객체 생성을 new를 통해서만 하겠다는 의도.
//  => 객체의 수명을 관리하는 방법을 제공하겠다.
//  => 지역 객체, 전역 객체를 생성할 수 없습니다.
class Sample {
public:
    Sample() { }

    // void Release(Sample* this)
    void Release()
    {
        delete this;
    }

private:
    ~Sample() { }
};

// Sample s;
int main()
{
    Sample* p = new Sample;

    // 파괴를 위한 멤버 함수를 제공해야 합니다.
    // delete p;
    p->Release(); // Sample::Release(p);

    // Sample s;
}
#endif

#if 0
// private 생성자 의도
//  - 내가 제공하는 방법으로만 객체 생성을 할 수 있도록 하겠다.
//  "객체 생성의 정책을 제한할 때"

// Design Pattern: Singleton
class Sample {
private:
    Sample() { }

public:
    ~Sample() { }

    friend Sample& GetInstance();
};

// Sample* GetInstance()
Sample& GetInstance()
{
    static Sample s;
    return s;
}

int main()
{
    Sample& s1 = GetInstance();
    cout << &s1 << endl;

    Sample& s2 = GetInstance();
    cout << &s2 << endl;
}
#endif

#if 0
Sample s1;
int main()
{
    Sample s2; // Sample::Sample()

    Sample* s3 = new Sample;
} // Sample::~Sample()
#endif
