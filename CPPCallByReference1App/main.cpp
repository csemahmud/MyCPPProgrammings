#include<iostream>
#include<conio.h>
using namespace std;

namespace ReferenceTest {

	class TestClass {

		int testValue1;

	public:

		TestClass() {
			testValue1 = 0;
		}

		void setTestValue(int testValue1) {
			this->testValue1 = testValue1;
		}

		int getTestValue() {
			return testValue1;
		}

	};

}

void callBy_Value(int i) {
	i = 34;
}

void callBy_Reference(int &i) {
	i = 56;
}

void callBy_Obj(ReferenceTest::TestClass *testObj1) {
	testObj1->setTestValue(90);
}

void callBy_ObjValue(ReferenceTest::TestClass testObj) {
	testObj.setTestValue(180);
}

int main() {

	using namespace ReferenceTest;

	int testNum1 = 12;
	cout<<"\n\n\tBefore Calling callBy_Value() : "<<testNum1;
	callBy_Value(testNum1);
	cout<<"\n\n\tAfter Calling callBy_Value() : "<<testNum1;
	callBy_Reference(testNum1);
	cout<<"\n\n\tAfter Calling callBy_Reference() : "<<testNum1;

	TestClass *testObj1 = new TestClass();
	testObj1->setTestValue(12);
	cout<<"\n\n\tBefore Calling callBy_Obj() : "<<testObj1->getTestValue();
	callBy_Obj(testObj1);
	cout<<"\n\n\tAfter Calling callBy_Obj() : "<<testObj1->getTestValue();

	TestClass testObj2;
	testObj2.setTestValue(36);
	cout<<"\n\n\tBefore Calling callBy_ObjValue() : "<<testObj2.getTestValue();
	callBy_ObjValue(testObj2);
	cout<<"\n\n\tAfter Calling callBy_ObjValue() : "<<testObj2.getTestValue();

	delete testObj1;

	getch();

	return 0;
}
