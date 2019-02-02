#include <gtest/gtest.h>
#include <iostream>
#include <string>

using namespace std;

#define SIZE_DEF 10;

TEST(preprocTEST, defineTest)
{
    int size = SIZE_DEF;
    cout << "defined size = " << size << endl;
}

#define int double
TEST(preprocTEST, changedDefinedTypes)
{
    int i = 0.5;
    cout << "#define int double = " << i << endl;
}
#undef int

#define ifdeftest
TEST(preprocTEST, ifDefTest)
{
// #if defined ifdeftest
#ifdef ifdeftest
    cout << "ifdeftest is defined" << endl;
#else
    cout << "ifdeftest is not defined" << endl;
#endif

#ifndef ifndeftest
    cout << "ifndeftest is not defined" << endl;
#else
    cout << "ifndeftest is defined" << endl;
#endif
}

TEST(preprocTEST, macroTest)
{
#ifdef __cplusplus
    cout << "__cplusplus is defined" << endl;
#else
    cout << "__cplusplus is not defined" << endl;
#endif

#ifdef __GNUC__
    cout << "__GNUC__ is defined" << endl;
#else
    cout << "__GNUC__ is not defined" << endl;
#endif

#ifdef __GNUG__
    cout << "__GNUG__ is defined" << endl;
#else
    cout << "__GNUG__ is not defined" << endl;
#endif

#ifdef __WIN32
    cout << "__WIN32 is defined" << endl;
#else
    cout << "__WIN32 is not defined" << endl;
    // #error __WIN32 is not defined
#endif
}

void predefPrint()
{
    cout << "File:    " << __FILE__ << endl
         << "Data:    " << __DATE__ << endl
         << "Line:   " << __LINE__ << endl
         << "Time:    " << __TIME__ << endl
         << "Function: " << __FUNCTION__ << endl;
}

TEST(preprocTEST, predefMacroTest)
{
    predefPrint();
}