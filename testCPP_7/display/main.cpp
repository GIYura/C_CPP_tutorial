#include <iostream>

using namespace std;

enum resolution{
    low,
    medium,
    high
};

class Display{
        int width;
        int hight;
        resolution res;
    public:
        void setDim(int w, int h) { width = w; hight = h; };
        void getDim(int &w, int &h) { w = width; h = hight; };
        void setRes(resolution r) { res = r; };
        resolution getRes(){ return res; };
};

char *getName(int);


int main()
{
    Display d[3];
    int W, H;

    d[0].setDim(640, 480);
    d[0].setRes(low);

    d[1].setDim(800, 600);
    d[1].setRes(medium);

    d[2].setDim(1600, 1200);
    d[2].setRes(high);

    for(int i = 0; i < 3; i++){
        cout << getName(i) << ": ";
        d[i].getDim(W, H);
        cout << W << "x" << H << endl;
    }
    return 0;
}

char *getName(int i){

    static char *n[] = {"low", "medium", "high"};
    return n[i];

}
