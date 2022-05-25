#include <iostream>
#include <vector>
#include <string>
class Foo
{
public:
    Foo()
    {
        std::cout << "Foo called !\n";
    }
};
class Bar{
public:
    Bar()
    {
        std::cout << "Bar called !\n";
    }
};
class Baz: Bar{
public:
    Foo* temp;
    Baz()
    {
        temp = new Foo[3];
    }
};
int main()
{
    Baz temp;
    return 0;
}
