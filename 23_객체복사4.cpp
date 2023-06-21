#include <iostream>
#include <atomic>
using namespace std;

// AOSP, Chromium, Webkit
class Resource {
    char name[32];
    // int ref; // 참조 계수에 의한 수명 관리
    atomic<int> ref;

public:
    Resource()
        : name("Tom")
        , ref(1)
    {
    }

    void AddRef() { ++ref; }
    void Release()
    {
        if (--ref == 0) {
            delete this;
        }
    }

private:
    ~Resource() { }
};

int main()
{
    Resource* resource = new Resource();

    Resource* other = resource;
    other->AddRef(); // 참조 계수 증가

    resource->Release();
    resource->Release();
}
