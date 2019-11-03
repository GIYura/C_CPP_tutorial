//INHERETANCE
//PUBLIC
//PRIVATE
//PROTEXTED

#include <iostream>

using namespace std;

class A{
private:
    string private_msg = "Private Message";

protected:
    string protected_msg = "Protected Message";

public:
    string public_msg = "Public Message";
};

class B : protected A{
public:
    void show(){
        cout << protected_msg << endl;
        cout << public_msg << endl;
    };
};

int main()
{
    B b1;
    b1.show();

//    b1.public_msg = "MODIFY PUBLIC MSG";

//    b1.show();


    return 0;
}
