#include <iostream>

using namespace std;

class Sample{
    int x;
public :
    void set(int i){x = i;};
    void show();
};

void Sample::show(){
    cout << x << endl;
}

int main()
{
    Sample ob[3], *p_ob;
    ob[0].set(10);
    ob[1].set(20);
    ob[2].set(30);

    p_ob = &ob[0];

    for(int i = 0; i < 3; i++){
        p_ob++->show();
    }
    return 0;
}
