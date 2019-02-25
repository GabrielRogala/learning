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
    //cout buforowany, strumien stdout
    string s = "";
    int i = 0;
    double d = 0;
    cout << "set example text: string int double" << endl;
    // cin >> s >> i >> d;
    cout << "example {" << s << "," << i << "," << d << "}" << endl;
}

TEST(iostreamTEST, cerrTest)
{
    //cerr nie jest buforowany i strumieniem wyjscia jest stderr
    string s = "";
    int i = 0;
    double d = 0;
    cerr << "set example text: string int double" << endl;
    cerr << "example {" << s << "," << i << "," << d << "}" << endl;
}

TEST(iostreamTEST, clogTest)
{
    //clog to buforowany cerr
    string s = "";
    int i = 0;
    double d = 0;
    clog << "set example text: string int double" << endl;
    clog << "example {" << s << "," << i << "," << d << "}" << endl;
}
