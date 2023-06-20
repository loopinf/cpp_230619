// 18_생성자4.cpp
#include <iostream>
using namespace std;

class Object {
public:
    Object() { cout << "Object()" << endl; }
    ~Object() { cout << "~Object()" << endl; }
};

int main()
{
    cout << "main 시작" << endl;
    Object* obj = new Object;

    delete obj;
    cout << "main 종료" << endl;
}

#if 0
void foo()
{
    static Object obj;
    // 함수가 최초에 실행되는 시점에 생성되고, 프로그램이 종료되기 전에 파괴됩니다.
}

int main()
{
    cout << "main 시작" << endl;
    foo();

    foo();

    foo();
    cout << "main 종료" << endl;
}
#endif

#if 0
Object obj; // Object() // 프로그램 시작 - 끝

int main()
{
    cout << "main 시작" << endl;
    cout << "main 종료" << endl;
}
// ~Object()
#endif

#if 0
int main()
{
    cout << "main 시작" << endl;
    {
        Object obj; // Object()
    } // ~Object()
    cout << "main 종료" << endl;
}
#endif

#if 0
int main()
{
    cout << "main 시작" << endl;
    Object obj; // Object()

    cout << "main 종료" << endl;
} // ~Object()
#endif
