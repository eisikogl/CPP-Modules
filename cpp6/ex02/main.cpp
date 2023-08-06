#include <fstream>
#include <iostream>

class Base
{
    public:
        virtual ~Base() {};
};

class A: public Base {};
class B: public Base {};
class C: public Base {};

Base *generate()
{
    Base *classes[] =
    {
        new A(),
        new B(),
        new C()
    };

    srand(time(NULL));
    size_t randomNumber = std::rand() % 3;

    for (size_t i = 0; i < 3; i++)
    {
        if (randomNumber == i)
            continue;
        delete classes[i];
    }
    
    return classes[randomNumber];
}

void identify(Base *p)
{
    if (dynamic_cast<A*>(p) == p)
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B*>(p) == p)
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C*>(p) == p)
        std::cout << "C" << std::endl;
    else
        std::cerr << "Invalid type!" << std::endl;
}

void identify(Base &p)
{
    try
    {
        A &a = dynamic_cast<A&>(p);
        (void)a;
        std::cout << "A" << std::endl;
    }
    catch(const std::exception &e) { }

    try
    {
        B &b = dynamic_cast<B&>(p);
        (void)b;
        std::cout << "B" << std::endl;
    }
    catch(const std::exception &e) { }

    try
    {
        C &c = dynamic_cast<C&>(p);
        (void)c;
        std::cout << "C" << std::endl;
    }
    catch(const std::exception &e) { }
}

int main()
{
    //Pointers
    {
        Base *base = generate();
        identify(base);
        delete base;
    }

    std::cout << std::endl;

    //Adresses
    {
        Base &base = *generate();
        identify(base);
        delete &base;
    }

    return 0;
}
