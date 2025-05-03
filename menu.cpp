#include "menu.hpp"
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

int print_struct(const phone *ph, const int count) {

    string output;

	for (int i = 0; i < count; i++) {
        output = to_string(ph[i].id) + " " + ph[i].make + " " + ph[i].model + " "
			+ to_string(ph[i].in_stork) + " " + to_string(ph[i].type) + " " + to_string(ph[i].price);
        cout << output << endl;
	}

	clog << "[CLOG] why he so gloopy (printed struct contents)" << endl;

	return EXIT_SUCCESS;

}

void print_info() {

    cout << "About:" << endl
         << "Vixia Raine made this" << endl
         << "(replace!!)" << endl;

}

int menu(phone *phone_array, int count) {

	int pressed_key = 0;
	string user_input;
	clog << "[CLOG] menu init." << endl;

	while (1) {
		// REMINDER: cin.get() should be used twice when intending
		// to pause the terminal because it always outputs "\n"
        if (pressed_key != '\n') {

            // use this instead of system cls for portability
            cout << "\033[2J\033[H";
            // [?] doesn't clear the screen in w10 terminal preview, odd

			cout << endl
                << " ====  Menu  ====" << endl
				<< " 1. Read file (device.db)" << endl
				<< " 2. Write file (wip)" << endl
				<< " 3. Print data" << endl
                << " 4. About" << endl
                << " 5. Quit" << endl;

			cin >> user_input;
			// clog << "[CLOG] user_input = " << user_input << endl;

			switch (user_input[0]) {
				case '1':
					read_file(phone_array, &count);
					break;
				case '2':
					write_file(phone_array, count);
					break;
				case '3':
					print_struct(phone_array, count);
					cin.get();
					cin.get();
					break;
                case '4':
                    print_info();
                    cin.get();
                    cin.get();
                    break;
                case '5':
					exit(EXIT_SUCCESS);
			}
		}

		else {
			pressed_key = 0;
		}
	}

	return EXIT_SUCCESS;

}
