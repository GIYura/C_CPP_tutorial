// exception.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

void might_go_wrong(void);

int main()
{
	try
	{
		might_go_wrong();
	}
	catch (int ex)
	{
		cout << "Error code: " << ex << endl;
	}

	catch (char const* ex) {
		cout << "Error message:" << ex << endl;
	}

	catch (string& ex) {
		cout << "String error message:" << ex << endl;
	}

	cout << "Running..." << endl;

	return 0;
}

void might_go_wrong(void) {
	bool error1 = false;
	bool error2 = true;

	if (error1) {
		throw "Something went wrong";
	}

	if (error2) {
		throw string("Something else went wrong");
	}
}