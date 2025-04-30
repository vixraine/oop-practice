#include "rwFunc.hpp"
#include "menu.hpp"
#include <iostream>

using namespace std;

int main() {
	int count = 0;
    int glorpy = 1; // debug read flag
	int dingus = 0; // debug write flag
	int gloopy = 1; // debug print flag
	const int item_amt = 20;

	phone phone_array[item_amt];

	// debug read
	if (glorpy) { 
		read_file(phone_array, &count);
	}

	// debug write; should only execute if ph isn't empty
	if (glorpy && dingus) { 
		write_file(phone_array, count);
	}

	// debug print. wacky ahh code
	if (glorpy && gloopy) {
		print_struct(phone_array, count);
	}

	cin.get();
	return 0;
}
