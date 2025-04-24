#include "rwFunc.hpp"
#include "menu.hpp"
#include <iostream>

using namespace std;

int main() {
	int count = 0;
    int glorpy = 0;
	int dingus = 0;

	phone phone_array[10];

	// debug read
	if (glorpy) { 
		read_file(phone_array, &count);
		cout << count;
	}

	// debug write; should only execute if ph isn't empty
	if (glorpy && dingus) { 
	//	write_file(phone_array, count);
	}
	cin.get();
	return 0;
}
