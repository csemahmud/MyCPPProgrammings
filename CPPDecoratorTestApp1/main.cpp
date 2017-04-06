#include <iostream>
#include <string.h>
#include <conio.h>
#include <stdio.h>

using namespace std;

//   Mahmudul  Hasan  Khan   DIU   143-25-417

namespace BeveregeNamespace {

    class Beverage {

    protected:

        char description[5000];

    public:

        Beverage(char* description) {
            strcpy(this->description, description);
        }

        Beverage() {
            strcpy(this->description, "Unknown Beverage");
        }

        ~Beverage() {
            cout<<"\n\tBeverage has been deleted";
        }

        char* getDescription() {
            return description;
        }

        virtual double getCost() = 0;

        char* toString() {
            char textBuffer[5000];
            sprintf(textBuffer,
                    "\tBeverage [\n\t\tdescription=%s,\n\t\tgetCost()=$%.2lf\n\t];",
                    description, getCost());
            return textBuffer;
        }

    };

    class Expresso : public Beverage {

    public:

        Expresso() {
            strcpy(description, "Expresso");
        }

        ~Expresso() {
            cout<<"Expresso has been deleted";
        }

        double getCost() {
            return 1.99;
        }

    };

    class DarkRoast : public Beverage {

    public:

        DarkRoast() {
            strcpy(description, "DarkRoast");
        }

        double getCost() {
            return 0.99;
        }

    };

    class HouseBlend : public Beverage {

    public:

        HouseBlend() {
            strcpy(description, "HouseBlend");
        }

        double getCost() {
            return 0.89;
        }

    };

    class CondimentDecorator : public Beverage {

        char* generateDescription(Beverage* beverage, char* condimentName) {
            char description[5000];
            strcpy(description, beverage->getDescription());
            strcat(description, !strcmp(description, "Expresso")
                   || !strcmp(description, "DarkRoast")
                   || !strcmp(description, "HouseBlend")
                   ? " Coffee, " : ", ");
            strcat(description, condimentName);
            return description;
        }

    public:

        CondimentDecorator(Beverage* beverage, char* condimentName)
        : Beverage(generateDescription(beverage, condimentName)) {

        }

    };

    class Mocha : public CondimentDecorator {

        Beverage* beverage;

    public:

        Mocha(Beverage* beverage)
        : CondimentDecorator(beverage, "Mocha") {
            this->beverage = beverage;
        }

        double getCost() {
            return 0.20 + beverage->getCost();
        }

    };

    class Whip : public CondimentDecorator {

        Beverage* beverage;

    public:

        Whip(Beverage* beverage)
        : CondimentDecorator(beverage, "Whip") {
            this->beverage = beverage;
        }

        double getCost() {
            return 0.10 + beverage->getCost();
        }

    };

    class Soy : public CondimentDecorator {

        Beverage* beverage;

    public:

        Soy(Beverage* beverage)
        : CondimentDecorator(beverage, "Soy") {
            this->beverage = beverage;
        }

        double getCost() {
            return 0.15 + beverage->getCost();
        }

    };

}

int main() {

    using namespace BeveregeNamespace;


    Beverage *beverage1 = new Expresso();
    cout <<"\n\n\n"<< beverage1->toString();

    Beverage *beverage2 = new DarkRoast();
    beverage2 = new Mocha(beverage2);
    beverage2 = new Mocha(beverage2);
    beverage2 = new Whip(beverage2);
    cout <<"\n\n"<< beverage2->toString();

    Beverage *beverage3 = new HouseBlend();
    beverage3 = new Soy(beverage3);
    beverage3 = new Mocha(beverage3);
    beverage3 = new Whip(beverage3);
    cout <<"\n\n"<< beverage3->toString();
    cout<<"\n";

    delete beverage1;
    delete beverage2;
    delete beverage3;

    getch();

    return 0;
}
