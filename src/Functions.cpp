#include <string>
#include <iomanip>
#include <iostream>

bool checkValidLetterInput(char tester)
{
	//try-cathc to validate input
	try {
		if (tester == tolower('A')) {
			return false;
		}
		else if (tester == tolower('B')) {
			return false;
		}
		else if (tester == tolower('C')) {
			return false;
		}
		else if (tester == tolower('D')) {
			return false;
		}
		else {
			return true;
		}
	}
	catch (std::invalid_argument& e) {
		//prompt user for valid input/continue loop
		return true;
	}
	return false;
	
}