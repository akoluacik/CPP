// Inspired from https://www.geeksforgeeks.org/exception-handling-and-object-destruction-in-cpp/

#include <iostream>
using namespace std;

class Test1 {
private:
    int val;
public:
	// Constructor of the class
	Test1(int _val)
	{
        val = _val;
		cout << "Constructing an Object of " << val
			<< endl;
	}
	// Destructor of the class
	~Test1()
	{
		cout << "Destructing an Object of " << val
			<< endl;
	}
};

class Test2 {
private:
    int val;
public:
	// Following constructor throws
	// an integer exception
	Test2(int _val) // Constructor of the class
	{
        val = _val;
		cout << "Constructing an Object of " << val
			<< endl;
		throw 20;
	}
	// Destructor of the class
	~Test2()
	{
		cout << "Destructing the Object of " << val
			<< endl;
	}
};

int main()
{
	try {
		// Constructed and destructed
		Test1 t1(1);
        Test1 test1Arr[4] = {Test1(2), Test1(3), Test1(4), Test1(5)};
		// Partially constructed
		
        Test2 t2(6); // After this point, no destructors gets executed because exception is thrown.
        Test2 test2Arr[4] = {Test2(7), Test2(8), Test2(9), Test2(10)};
		
		Test1 t3(0); 
	}
	catch (int i) {
		cout << "Caught " << i << endl;
	}
}
