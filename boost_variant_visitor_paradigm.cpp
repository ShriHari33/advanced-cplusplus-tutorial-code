/*
	Program to Demonstrate the Use of Boost variant and Visitor concept.
*/
#include<iostream>
#include <boost/variant.hpp>

using namespace std;

int main()
{
	cout << "Hello World" << endl;

	/* union allows datatypes of primitive type,
	if I want to use strings in union, it will throw an error.
	To solve this problem we can use boost::variant*/
	union
	{
		int i;
		float f;
		//string s;
	} u;



	/*
		Boost variant allow us to make union of arbitrary datatypes. :)
	*/

	boost::variant<int, string> u1;
	u1 = 2;	// u1 becomes an int here
	cout << u1 << endl;
	u1 = "a string";	// u1 becomes a string here
	cout << u1 << endl;

	
	string str = boost::get<string>(u1);
	u1 = "good string"; // u1 is a string 

	cout << u1 << endl;

	// If a function is taking a variant as a parameter, then we don't 
	// know which datatype the variant is holding in actual.
	// eg. void Double(boost::variant<int, string> x);
	// we use visitors to solve this problem
	// We use operator overloading inside Visitor class, so that each 
	// datatype gets a function for its own type.

	class DoubleVisitor : public boost::static_visitor<>
	{
	public:
		void operator()(int& i) const
		{
			i = i + i;
		}
		
		void operator()(string& i) const
		{
			i = i + i;
		}
	};

	u1 = 2;
	boost::apply_visitor(DoubleVisitor(), u1);	// 2 becomes 4
	cout << u1 << endl;

	u1 = "hello";
	boost::apply_visitor(DoubleVisitor(), u1);	// "hello" becomes "hellohello"
	cout << u1 << endl;

	
	getchar();
	return 0;
}
