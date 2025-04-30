#include "menu.hpp"
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

int print_struct(const phone *ph, const int count) {

	string debug_output;

	cout << "why he so gloopy" << endl;

	for (int i = 0; i < count; i++) {
		debug_output = to_string(ph[i].id) + " " + ph[i].make + " " + ph[i].model + " "
			+ to_string(ph[i].in_stork) + " " + to_string(ph[i].type) + " " + to_string(ph[i].price);
		cout << debug_output << endl;
	}
	return EXIT_SUCCESS;

}