/*
 * Dummy program to demonstrate the use of const with functions in c++
 */
#include<iostream>
#include<string>

using namespace std;

class Dog
{
    int age;
    string name;

public:
    Dog()
    {
        age = 10;
        name = "dummy";
    }

    /*
     * const parameters
     * We pass a constant reference to a variable so that the function setAge
     * cannot modify the value of the variable a being passed.
     */
    void setAge(const int& a)
    {
        age = a;
    }

    /*
     * const return value
     * although we can simply return the name by value, but we prefer to return
     * it by reference to avoid create unnecessary copies and improve program efficency
     * Also, we don't want main function to modify the name variable of any Dog instance
     * and hence returning it as a const reference.
     */
     const string& getName()
     {
         return name;
     }
};


int main()
{
    Dog d;
    int i = 9;
    d.setAge(i);

    const string& name = d.getName(); // name cannot be modified
    cout<<name<<endl;

    return 0;
}
