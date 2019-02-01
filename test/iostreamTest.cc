#include <gtest/gtest.h>
#include <iostream>
#include <string>

using namespace std;

TEST(iostreamTEST, coutTest)
{
    cout << "cout example text" << endl;
}

TEST(iostreamTEST, cinTest)
{
    string s = "";
    int i = 0;
    double d = 0;
    cout << "set example text: string int double" << endl;
    // cin >> s >> i >> d;
    cout << "example {" << s << "," << i << "," << d << "}" << endl;
}
