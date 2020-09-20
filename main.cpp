#include <iostream>
#include <set>
#include <test_h.h>

using namespace std;

// ±äÁ¿ÉùÃ÷
static int a, b;
static int c;
static float f;

int extern_int = 10;
int not_extern_int = 20;
int test_int = 100;

void staticMethod();

void setTestMethod();

//int main()
//{
//    return 0;
//}

void staticMethod()
{
    static int counter = 0;
    cout << counter << endl;
    counter++;
}

void externMethod()
{
//    cout << "Extern method!" << endl;
//    cout << "extern_int:" << extern_int << "  " << endl;
    cout << "extern_int:" << extern_int << "  " << "not_extern_int:" << not_extern_int << endl;
}

void setTestMethod() {
    set<int> s;
    s.insert(1);
    s.insert(2);
    cout << endl;
}
