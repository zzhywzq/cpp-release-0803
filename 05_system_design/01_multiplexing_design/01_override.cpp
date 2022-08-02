#include <iostream>
using namespace std;

class Animal {
public:
    virtual void speak() { cout << "Animal speak" << endl; }
	void eat() { cout << "Animal eat"  << endl; }
};

class Dog : public Animal {
public:
    virtual void speak() { cout << "Dog speak" << endl; }
	void eat() { cout << "Dog eat"  << endl; }
};

class Cat : public Animal {
public:
    virtual void speak() { cout << "Cat speak" << endl; }
	void eat() { cout << "Cat eat"  << endl; }
};

int main() {
	Animal *animal;

    animal = new Dog();
    animal->speak(); // polymorphic
    animal->eat();
    delete animal;

    animal = new Cat();
    animal->speak(); // polymorphic
    animal->eat();
    delete animal;

	return 0;
}