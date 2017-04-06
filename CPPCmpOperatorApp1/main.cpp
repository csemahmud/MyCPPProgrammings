#include <iostream>
#include<cmath>
#include<stdio.h>
#include<conio.h>

//   Mahmudul   Hasan   Khan   CE09003

using namespace std;

namespace ComplexNumberNamespace {

    class ComplexNumber {

        double real;
        double imaginary;

    public:

        ComplexNumber(double r, double i) {
            ComplexNumber();
            real = r;
            imaginary = i;
        }

        ComplexNumber() {

        }

        double getReal() {
            return real;
        }

        double getImaginary() {
            return imaginary;
        }

        char* toString() {
            char textBuffer[2000];
			sprintf(textBuffer, "(%.2lf %c %.2lfi)",
                real, (imaginary <0 ? '-' : '+'), abs(imaginary));
			return textBuffer;
        }

        /*ComplexNumber* operator+(ComplexNumber &y) {

            ComplexNumber *aComplexNumber
            = new ComplexNumber(real + y.getReal(),
                 imaginary + y.getImaginary());
            return aComplexNumber;

        }*/

        friend ComplexNumber* operator+(ComplexNumber &, ComplexNumber &);

        /*ComplexNumber* operator-(ComplexNumber &y) {

            ComplexNumber *aComplexNumber
            = new ComplexNumber(real - y.getReal(),
                 imaginary - y.getImaginary());
            return aComplexNumber;

        }*/

        friend ComplexNumber* operator-(ComplexNumber &, ComplexNumber &);

        ComplexNumber* operator*(ComplexNumber &y) {

            ComplexNumber *aComplexNumber
            = new ComplexNumber(
                    real * y.getReal() - imaginary * y.getImaginary(),
                    real * y.getImaginary() + y.getReal() * imaginary);
            return aComplexNumber;

        }

        //friend ComplexNumber* operator*(ComplexNumber &x, ComplexNumber &y);

    };

    ComplexNumber* operator+(ComplexNumber &x, ComplexNumber &y) {

        ComplexNumber *aComplexNumber
            = new ComplexNumber(x.getReal() + y.getReal(),
                                     x.getImaginary() + y.getImaginary());
        return aComplexNumber;

    }

    ComplexNumber* operator-(ComplexNumber &x, ComplexNumber &y) {

        ComplexNumber *aComplexNumber
            = new ComplexNumber(x.getReal() - y.getReal(),
                                     x.getImaginary() - y.getImaginary());
        return aComplexNumber;

    }

    /*ComplexNumber* operator*(ComplexNumber &x, ComplexNumber &y) {

        ComplexNumber *aComplexNumber
            = new ComplexNumber(
                x.getReal() * y.getReal() - x.getImaginary() * y.getImaginary(),
                x.getReal() * y.getImaginary() + y.getReal() * x.getImaginary());
        return aComplexNumber;

    }*/
}

int main()
{
    using namespace ComplexNumberNamespace;

    double realPart, imaginaryPart;

    cout<<"\n\n\n\tEnter the REAL part of complex number x: ";
    cin>>realPart;
    cout<<"\n\tEnter the IMAGINARY part of complex number x: ";
    cin>>imaginaryPart;

    ComplexNumber *x = new ComplexNumber(realPart, imaginaryPart);

    cout<<"\n\n\tEnter the REAL part of complex number y: ";
    cin>>realPart;
    cout<<"\n\tEnter the IMAGINARY part of complex number y: ";
    cin>>imaginaryPart;

    ComplexNumber *y = new ComplexNumber(realPart, imaginaryPart);

    cout <<"\n\n\t"<<x->toString();
    cout <<" + "<<y->toString();

    ComplexNumber *z1 = *x + *y;
    cout <<" = "<<z1->toString();

    cout <<"\n\t"<<x->toString();
    cout <<" - "<<y->toString();

    ComplexNumber *z2 = *x - *y;
    cout <<" = "<<z2->toString();

    cout <<"\n\t"<<x->toString();
    cout <<" * "<<y->toString();

    ComplexNumber *z3 = *x * *y;
    cout <<" = "<<z3->toString();

    delete z3;
    delete z2;
    delete z1;
    delete y;
    delete x;

    getch();

    return 0;
}
