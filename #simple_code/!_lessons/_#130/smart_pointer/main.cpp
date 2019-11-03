#include <iostream>

using namespace std;

template <typename T>
class SmartPointer{
public:
    SmartPointer(T* ptr){
        this->ptr = ptr;
    }

    ~SmartPointer(){
        delete ptr;
    }

    T& operator*(){
        return *ptr;
    }

private:
    T* ptr;
};

int main()
{
    SmartPointer<int> pointer = new int(200);

    cout << *pointer << endl;

    SmartPointer<float> f_p = new float(2.33);

    cout << *f_p << endl;

    return 0;
}
