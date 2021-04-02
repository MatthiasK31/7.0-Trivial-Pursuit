#include <string>
#include <iomanip>
#include <iostream>

bool checkValidNumInput(char tester)
{
	//try-cathc to validate input
	try {
		if (tester != tolower('a') || tester != tolower('b') || tester != tolower('c') || tester != tolower('d')) {
			return true;
		}
	}
	catch (std::invalid_argument& e) {
		//prompt user for valid input/continue loop
		return true;
	}
	return false;
}