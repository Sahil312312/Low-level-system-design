There basically three types of factory patterns :

1. Simple Factory:
    a.Centralizes object creation in one method	
    b. Voliates Open/Close Princple.
    c. To hide the new keyword and centralize object creation logic.

2. Factory Method:
    a. Lets subclasses decide the object creation.
    b. Here we can extend the products/concrete class without voliating Open/Close princple.
    c. 

3. Abstract Factory:
    a. Provide an interface to create families of related objects without specifying their concrete classes.Basically we can create factory of factories.
    b. When to use :  You need multiple products that should work together