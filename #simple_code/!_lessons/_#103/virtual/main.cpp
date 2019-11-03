//virtual functions

#include <iostream>

using namespace std;

class Gun{

public:

    virtual void shoot(void){
        cout << "BANG!" << endl;
    }
};

class Submachinegun : public Gun{

public:

    void shoot(void) override{
        cout << "BANG! BANG! BANG!" << endl;
    }
};

class Bazuka : public Gun{

public:

    void shoot(void) override{
        cout << "BADABUM!" << endl;
    }
};

class Player{

public:

    void shoot(Gun* gun){
        gun->shoot();
    }
};

int main()
{
    Gun gun;
    Submachinegun sbgun;
    Bazuka bazuka;

    Player p;
    p.shoot(&gun);
    p.shoot(&sbgun);
    p.shoot(&bazuka);

    return 0;
}
