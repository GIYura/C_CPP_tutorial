#include <iostream>

using namespace std;

class Animal{
    public:
    virtual void voice(){
        cout << "Animal make noise" << endl;
    }
};

class Cat : public Animal{
    public:
    void voice(){
        cout << "Cat says Mia-Mia" << endl;
    }
};

class Dog : public Animal{
    public:
    void voice(){
        cout << "Dog says Bao-Bao" << endl;
    }
};

class base
{
public:
    virtual void print ()
    { cout<< "print base class" <<endl; }

    //void show ()
    //{ cout<< "show base class" <<endl; }
};

class derived:public base
{
public:
    void print ()
    { cout<< "print derived class" <<endl; }

    //void show ()
    //{ cout<< "show derived class" <<endl; }
};



int main()
{
    Animal *a = new Animal();
    Cat *c = new Cat();
    Dog *d = new Dog();

    a->voice();
    c->voice();
    d->voice();

    base b;
    b.print();
    derived k;
    k.print();

    return 0;
}
