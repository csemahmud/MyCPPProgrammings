#include<iostream>
#include<stdio.h>
#include<conio.h>
#include<string.h>
using namespace std;

//   Mahmudul   Hasan   Khan   CE09003

namespace AssociationNamespace {

	class BPart {

		int number1;
		char text1[1000];

	public:

		/**
		 * @return the number1
		 */
		int getNumber1() {
			return number1;
		}

		/**
		 * @param number1 the number1 to set
		 */
		void setNumber1(int number1) {
			this->number1 = number1;
		}

		/**
		 * @return the text1
		 */
		char* getText1() {
			return text1;
		}

		/**
		 * @param text1 the text1 to set
		 */
		void setText1(char* text1) {
			strcpy(this->text1,text1);
		}

		/**
		 *
		 */
		BPart() {
			// TODO Auto-generated constructor stub
		}

		char* toString() {
			char textBuffer[2000];
			sprintf(textBuffer, "\n\tBPart : [number1=%d, text1=%s]",number1,text1);
			return textBuffer;
		}
	};

	class AWhole {

		BPart *bPart1;
		BPart *bPart2;

	public:

		/**
		 *
		 */
		AWhole(BPart *bpartPrm) {
			// TODO Auto-generated constructor stub

			bPart1 = bpartPrm;   //   Aggregation

			bPart2 = new BPart();   //   Composition

			bPart2->setNumber1(500);
			bPart2->setText1("Pakistan");

		}

		AWhole() {
			// TODO Auto-generated constructor stub

			bPart2 = new BPart();   //   Composition

			bPart2->setNumber1(500);
			bPart2->setText1("Pakistan");
		}

		void changeBPart2(int number, char* text) {
			bPart2->setNumber1(bPart2->getNumber1() + number);
			bPart2->setText1(strcat(bPart2->getText1(),text));
		}

		char* getStringBPart1() {
			return bPart1->toString();
		}

		char* getStringBPart2() {
			return bPart2->toString();
		}

		static char* determineOddEven(BPart *bpart) {

			//   Dependency

			if(bpart->getNumber1()%2) {
				return "This BPart has ODD number .";
			}
			return "This BPart has EVEN number .";
		}

		~AWhole() {
			delete bPart2;
			cout<<"\n\n\tBPart2 has been deleted .";
		}

	};
}

int main() {

	using namespace AssociationNamespace;

    BPart *aBPartObj = new BPart();
    aBPartObj->setNumber1(3);
    aBPartObj->setText1("Mahmud");

    AWhole *aAWholeObj = new AWhole(aBPartObj);
	cout<<"\n\n"<<aAWholeObj->getStringBPart1();

    aBPartObj->setNumber1(5);
    aBPartObj->setText1("Super-Man");

    cout<<"\n"<<aAWholeObj->getStringBPart1();

    cout<<"\n"<<aAWholeObj->getStringBPart2();

    aAWholeObj->changeBPart2(100, " Cricket Team");
    cout<<"\n"<<aAWholeObj->getStringBPart2();

    BPart *tempBObj1 = new BPart();
    tempBObj1->setNumber1(50);
	cout<<"\n\n\t"<<AWhole::determineOddEven(tempBObj1);

	delete tempBObj1;
	delete aAWholeObj;
	delete aBPartObj;

	getch();

	return 0;
}
