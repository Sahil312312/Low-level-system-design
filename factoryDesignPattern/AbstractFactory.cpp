#include <bits/stdc++.h>
using namespace std;

// Scenario

// We run an e -commerce platform.We have two regions :
//     1.Asia => Wooden + Truck
//     2. Europe => Bike + Plastic

// Each region has two products in its shipping system :
//      Vehicle(Bike, Truck)
//      Packaging(PlasticBox, WoodenBox)

// Product
class Vehicle
{
public:
    virtual void deliver() = 0;
    virtual ~Vehicle() {}
};
// Concrete Product
class Bike : public Vehicle
{
public:
    void deliver()
    {
        cout << "Delivery in bike" << endl;
    }
};
// Concrete Product
class Truck : public Vehicle
{
public:
    void deliver()
    {
        cout << "Delivery in Truck" << endl;
    }
};
// Product

class Packing
{
public:
    virtual void pack() = 0;
    virtual ~Packing() {}
};

// Concrete Product
class woodenPacking : public Packing
{
public:
    void pack() override { cout << "Packing in Wooden Box\n"; };
};
// Concrete Product
class PlasticPacking : public Packing
{
public:
    void pack() override { cout << "Packing in Plastic Box\n"; };
};

// Creator
class ShippingFactory
{
public:
    virtual Vehicle *createVehicle() = 0;
    virtual Packing *createPacking() = 0;
};
// Concrete Creator
class asiaFactory : public ShippingFactory
{
public:
    Vehicle *createVehicle() { return new Truck(); }
    Packing *createPacking() { return new woodenPacking(); }
};
// Concrete Creator
class europeFactory : public ShippingFactory
{
public:
    Vehicle *createVehicle() { return new Bike(); }
    Packing *createPacking() { return new PlasticPacking(); }
};

// Client
class orderProcessing
{
    ShippingFactory *factory;

public:
    orderProcessing(ShippingFactory *f) : factory(f) {}

    void processOrder()
    {
        Vehicle *vehicle = factory->createVehicle();
        Packing *packing = factory->createPacking();

        vehicle->deliver();
        packing->pack();

        delete vehicle;
        delete packing;
    }
};

int main()
{

    cout << "=== Asia Order ===\n";
    ShippingFactory *AFactory = new asiaFactory();
    orderProcessing asiaOrder(AFactory);
    asiaOrder.processOrder();
    delete AFactory;

    cout << "=== Europe Order ===\n";
    ShippingFactory *EFactory = new europeFactory();
    orderProcessing europeOrder(EFactory);
    europeOrder.processOrder();
    delete EFactory;

    return 0;
}
