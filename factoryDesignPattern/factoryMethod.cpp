#include <bits/stdc++.h>
using namespace std;

class Burger
{
public:
    virtual void prepare() = 0;
    // virtual ~Burger() = 0;
};

class standardBurger : public Burger
{
public:
    void prepare() override
    {
        cout << "Prepare stadard Burger";
    }
};

class normieBurger : public Burger
{
    void prepare() override
    {
        cout << "Prepare normie Burger";
    }
};

class premiumBurger : public Burger
{
    void prepare() override
    {
        cout << "Prepare premiuim Burger";
    }
};

class BurgerFactory
{
public:
    Burger *createBurger(Burger*){

    }
};

int main()
{
    BurgerFactory *factory = new BurgerFactory();
    string type = "premium";

    Burger *burger = factory->createBurger(type);
    burger->prepare();

    return 0;
}