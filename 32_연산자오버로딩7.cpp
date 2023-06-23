// 32_연산자오버로딩7.cpp
#include <iostream>
using namespace std;

class Image {
public:
    Image() { cout << "Image()" << endl; }
    ~Image() { cout << "~Image()" << endl; }

    void Draw() const { cout << "Draw Image" << endl; }
};

// 스마트 포인터의 개념
// => 핵심: 포인터의 역활을 수행하고,
//         참조하는 자원의 수명을 관리합니다.
#if 0
class Ptr {
    Image* obj;

public:
    Ptr(Image* p = nullptr)
        : obj(p)
    {
    }

    ~Ptr() { delete obj; }

    Image& operator*() { return *obj; }
    Image* operator->() { return obj; }
};
#endif

template <typename T>
class Ptr {
    T* obj;

public:
    Ptr(T* p = nullptr)
        : obj(p)
    {
    }

    ~Ptr() { delete obj; }

    T& operator*() { return *obj; }
    T* operator->() { return obj; }
};

#include <memory>
// 1) shared_ptr: 참조 계수
// 2) unique_ptr: 복사 금지

int main()
{
    unique_ptr<Image> p { new Image };

    (*p).Draw();
    // (p.operator*()).Draw()

    p->Draw();
    // p.operator->()Draw()    <- 이런 형태이지만
    // p.operator->()->Draw(); <- 컴파일러는 이렇게 처리합니다.
}

#if 0
int main()
{
    Image* p = new Image;
    p->Draw();

    delete p;
}
#endif
