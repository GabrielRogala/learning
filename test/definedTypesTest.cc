#include <gtest/gtest.h>
#include <iostream>
#include <string>

using namespace std;

#define SIZE_DEF 10;

TEST(definedTypesTEST, defineAndDeclarVariables)
{
    int i1;
    int i2();
    int i3(3);
    int i4{};
    int i5{5};
    int i6 = 1, i7 = i6, i8{8}, i9{i8};
    cout << "i1 \t= " << i1 << endl
         << "i2() \t= " << i2 << endl
         << "i3(3) \t= " << i3 << endl
         << "i4{} \t= " << i4 << endl
         << "i5{5} \t= " << i5 << endl
         << "i6=1 \t= " << i6 << endl
         << "i7=i6 \t= " << i7 << endl
         << "i8{8} \t= " << i8 << endl
         << "i9{i8} \t= " << i8 << endl;
}

TEST(definedTypesTEST, sizeOfVariable)
{
    long double ld = 0;
    string st = "Hermenegilda";
    short sh = 0;
    long *lo = 0;
    cout << "long double: " << sizeof ld << endl
         << "double     : " << sizeof(double) << endl
         << "float      : " << sizeof(float) << endl
         << "long long  : " << sizeof(long long) << endl
         << "long       : " << sizeof(long) << endl
         << "int        : " << sizeof(int) << endl
         << "short      : " << sizeof sh << endl
         << "char       : " << sizeof(char) << endl
         << "bool       : " << sizeof(bool) << endl
         << "string     : " << sizeof st << endl
         << "long*      : " << sizeof lo << endl;
}