#include <gtest/gtest.h>
#include <iostream>
#include <string>

using namespace std;

class Person
{
  public:
    int age;
    int height;
    char *name;

    Person()
    {
        cout << "C_person\n";
    }
    Person(int age, int height, const char *name)
        : age(age), height(height), name(strcpy(new char[strlen(name) + 1], name))
    {
        cout << "O_C_person\n";
    }
    Person(const Person &person)
        : Person(person.age, person.height, person.name)
    {
        cout << "C_C_person\n";
    }

    ~Person()
    {
        printf("remove %s\n", name);
        delete[] name;
    }

    void printInfo()
    {
        printf("%s : %d l - %d cm\n", name, age, height);
    }

    int getValue(int a){
        return a*height/age;
    }
};

TEST(pointerTest, test_no1)
{
    Person p1;
    Person p2(20, 180, "Tomek");
    Person p3(p2);
    // Person p4{};
    Person p5{30, 170, "Daniel"};
    Person *p_p6 = new Person(p5);

    p1.printInfo();
    p2.printInfo();
    p3.printInfo();
    // p4.printInfo();
    p5.printInfo();
    p_p6->printInfo();

    delete p_p6;
}

TEST(pointerTest, test_no2)
{
    Person p5{30, 170, "Daniel"};
    Person *p_p6 = new Person(p5);

    int Person::*wsk;
    wsk = &Person::age;

    printf("%d \n", p5.*wsk);
    printf("%d \n", p_p6->*wsk);

    // int (Person::*wsk_f)(int);
    // wsk_f = Person::getValue;

    // printf("%d\n",(p5.*wsk_f)(2));
    // printf("%d\n",(p_p6->*wsk_f)(3));

    delete p_p6;
}