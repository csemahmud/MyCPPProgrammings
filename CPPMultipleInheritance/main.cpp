#include <iostream>
#include <conio.h>
using namespace std;

//   Mahmudul   Hasan   Khan   CE09003

class BaseX {
protected:
    int x;
public:
    BaseX(int x) {
        this->x = x;
    }
    int getX() {
        return x;
    }
//    void commonFunction() {
//        cout<<"\n\n\tcommonFunction() from BaseX";
//    }
};

class BaseY {
protected:
    int y;
public:
    BaseY(int y) {
        this->y = y;
    }
    int getY() {
        return y;
    }
//    void commonFunction() {
//        cout<<"\n\n\tcommonFunction() from BaseY";
//    }
};

class BaseZ {
protected:
    int z;
public:
    BaseZ(int z) {
        this->z = z;
    }
    int getZ() {
        return z;
    }
//    void commonFunction() {
//        cout<<"\n\n\tcommonFunction() from BaseZ";
//    }
};

class Derived: public BaseX, public BaseY, public BaseZ {
public:
    Derived(int x, int y, int z): BaseX(x), BaseY(y), BaseZ(z)
    {
    }
    int getLargestValue()
    {
        if((x>y)&&(x>z))
            return x;
        else if(y>z)
            return y;
        return z;
    }
};

int main()
{
    Derived *derivedPtr = new Derived(5,13,3);
    cout<<"\n\n\n\tX = "<<derivedPtr->getX();
    cout<<"\n\n\tY = "<<derivedPtr->getY();
    cout<<"\n\n\tZ = "<<derivedPtr->getZ();
    cout<<"\n\n\tThe Largest Value is : "<<derivedPtr->getLargestValue();
    //derivedPtr->commonFunction();
    delete derivedPtr;
    getch();
    return 0;
}
