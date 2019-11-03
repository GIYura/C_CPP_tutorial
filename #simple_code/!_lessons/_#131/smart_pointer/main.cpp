#include <iostream>
#include <memory>

using namespace std;

template <typename T>
class SmartPointer{
public:
    SmartPointer(T* ptr){
        this->ptr = ptr;
        cout << "Constructor" << endl;
    };

    ~SmartPointer(){
        cout << "Destructor" << endl;
        delete ptr;
    };

    T& operator*(){
        return *ptr;
    };

private:
    T* ptr;
};

int main()
{
    auto_ptr<int> apl1(new int(2));
    auto_ptr<int> apl2(apl1);

//    SmartPointer<int> p1 = new int(5);
//    SmartPointer<int> p2 = p1;
    return 0;
}
