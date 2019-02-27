#include <gtest/gtest.h>
#include <iostream>
#include <string>

using namespace std;

/////////////////////////////////////////////////////////////////
class Person5
{
  protected:
    int m_id;
    char *m_name;

  public:
    void printInfo() const
    {
        cout << "\t" << m_id << ": " << m_name << endl;
    }
    void setName(char *name)
    {
        cout << "setName\n";
        strcpy(m_name, name);
    }

    ~Person5()
    {
        cout << "dtor\n";
        if (m_name != 0)
            delete[] m_name;
    }

    Person5()
        : m_id(0), m_name(strcpy(new char[7], "noname"))
    {
        cout << "ctor\n";
    }

    Person5(int id, char *name)
        : m_id(id), m_name(strcpy(new char[strlen(name) + 1], name))
    {
        cout << "over ctor\n";
    }

    Person5(const Person5 &obj)
        : m_id(obj.m_id), m_name(strcpy(new char[strlen(obj.m_name) + 1], obj.m_name))
    {
        cout << "copy ctor\n";
    }

    Person5 &operator=(const Person5 &obj)
    {
        cout << "copy assignment\n";
        return *this = Person5(obj);
    }

    Person5(Person5 &&obj) noexcept //bez tego uruchomi sie copy ctor
        : m_id(obj.m_id), m_name(strcpy(new char[strlen(obj.m_name) + 1], obj.m_name))
    {
        cout << "move ctor\n";
    }

    Person5 &operator=(Person5 &&obj) noexcept // bez tego nieskonczona petla kopiowania
    {
        cout << "move assignment\n";
        m_id = obj.m_id;
        strcpy(m_name, obj.m_name);
        return *this;
    }
};
/////////////////////////////////////////////////////////////////
class SpecialPerson5 : public Person5
{
    int m_power;

  public:
    SpecialPerson5()
    {
        m_power = 0;
        cout << "specia ctor\n";
    }
    SpecialPerson5(int id, char *name, int power)
        : Person5(id, name), m_power(power)
    {
        cout << "specia ctor\n";
    }
    ~SpecialPerson5()
    {
        cout << "specia dtor\n";
    }
    void printInfo()
    {
        cout << "\t" << m_id << ": " << m_name << " power=" << m_power << endl;
    }
};
/////////////////////////////////////////////////////////////////

void printPersonInfo(const Person5 &p)
{
    p.printInfo();
}

TEST(moveSemantic, test_no1)
{
    Person5 p0;
    Person5 p1(100, "Adam"); //over ctor
    p1.printInfo();
    cout << "\n\n";

    Person5 p2(p1); //copy ctor
    p1.printInfo();
    p2.printInfo();
    cout << "\n\n";

    p2.setName("Tomasz");
    p1.printInfo();
    p2.printInfo();
    cout << "\n\n";

    Person5 p3; //ctor
    p1.printInfo();
    p2.printInfo();
    p3.printInfo();
    cout << "\n\n";

    p3 = p2; //copy assignment; copy ctor; move assignment; dtor
    p1.printInfo();
    p2.printInfo();
    p3.printInfo();
    cout << "\n\n";

    p3.setName("Kamil");
    p1.printInfo();
    p2.printInfo();
    p3.printInfo();
    cout << "\n\n";

    swap(p2, p3); //move ctor; 2x move assignment; dtor
    p1.printInfo();
    p2.printInfo();
    p3.printInfo();
    cout << "\n\n";

    p3.setName("Janusz");
    p1.printInfo();
    p2.printInfo();
    p3.printInfo();
    cout << "\n\n";

    Person5 &&p4 = Person5(200, "Andrzej"); //over ctor
    p4.printInfo();
    cout << "\n\n";

    printPersonInfo(Person5(300, "Mikolaj")); //over ctor
    cout << "\n\n";

    SpecialPerson5 sp0;
    sp0.printInfo();
    cout << "\n\n";

    SpecialPerson5 sp1(500, "Krzysztof", 123);
    sp1.printInfo();
    cout << "\n\n";

    SpecialPerson5 sp2;
    sp2 = sp1; 
    sp1.printInfo();
    sp2.printInfo();
    cout << "\n\n";
}