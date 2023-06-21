// 14_동적메모리할당.cpp
#include <iostream>
using namespace std;

#include <cstdlib> // malloc, free

// 1. malloc / free
//  void* malloc(size_t size)
//  void free(void*)

// 2. malloc은 void*를 반환합니다.
//    명시적인 캐스팅이 필요합니다.

// 3. C++은 연산자를 통해 동적 메모리 할당 / 해지를 수행합니다.
//    new / delete

// 4. new 연산자는 타입을 전달하고, 타입의 포인터를 반환받기 때문에
//    별도의 캐스팅이 필요하지 않습니다.
// 5. delete 연산자를 통해 메모리를 해지할 수 있습니다.

// 6. 연속된 메모리를 해지할 때,
//    delete[] 연산자를 통해 메모리를 해지해야 합니다.

#if 0
int main()
{
    int* p1 = static_cast<int*>(malloc(sizeof(int)));
    free(p1);

    int* arr1 = static_cast<int*>(malloc(sizeof(int) * 10));
    free(arr1);

    int* p2 = new int;
    delete p2;

    int* arr2 = new int[10];
    delete[] arr2; // 주의가 필요합니다.
}
#endif

// 7. malloc은 초기화되지 않은 메모리를 반환합니다.
//   => calloc(100, sizeof(int));

// 8. new는 메모리를 할당할 때, 초기화가 가능합니다.
#if 0
int main()
{
    // int* p = static_cast<int*>(malloc(sizeof(int) * 100));
    // int* p = static_cast<int*>(calloc(100, sizeof(int)));

    // int* p = new int; // 초기화되지 않은 메모리
    // int* p = new int(42);
    int* p = new int { 42 };
    cout << *p << endl;

    int* arr = new int[3] { 10, 20, 30 };
    cout << arr[0] << endl;
    cout << arr[2] << endl;
    delete[] arr;
}
#endif

// 9. malloc/free는 객체를 대상으로 생성자와 소멸자가 호출되지 않습니다.
// 10. new/delete 객체를 대상으로 생성자와 소멸자가 호출됩니다.

// 11. free/delete는 nullptr을 대상으로 아무일도 일어나지 않습니다.
int main()
{
    int* p = nullptr;

    // nullptr을 대상으로 안전하게 사용할 수 있습니다.
    delete p;
    delete[] p;

    // 굳이 널 체크를 수행할 필요가 없습니다.
    if (p) {
        free(p); // 아무일도 수행하지 않습니다.
    }
}
