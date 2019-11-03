//virtual functions

#include <iostream>

using namespace std;

class Weapon{

public:
    virtual void shoot(void) = 0;
    void foo(void){
        cout << "Something" << endl;
    }
};

class Gun : public Weapon{

public:

    void shoot(void) override{
        cout << "BANG!" << endl;
    }
};

class Submachinegun : public Gun{

public:

    void shoot(void) override{
        cout << "BANG! BANG! BANG!" << endl;
    }
};

class Bazuka : public Weapon{

public:

    void shoot(void) override{
        cout << "BADABUM!" << endl;
    }
};

class Knife : public Weapon{

public:
    void shoot(void) override{
        cout << "STAB!" << endl;
    }
};

class Player{

public:

    void shoot(Weapon* weapon){
        weapon->shoot();
    }
};

int main()
{
    Gun gun;
    Submachinegun sub_gun;
    Bazuka bazuka;
    Knife knife;

    Player* p;// = new Player();

    p->shoot(&gun);
    p->shoot(&sub_gun);
    p->shoot(&bazuka);
    p->shoot(&knife);

    gun.foo();
    sub_gun.foo();
    bazuka.foo();
    knife.foo();

    return 0;
}
