#include "menu.hpp"
#include "rwFunc.hpp"
#include <iostream>

using namespace std;

int main()
{
    int count = 0;
    int glorpy = 0;          // debug read flag
    int dingus = 0;          // debug write flag
    int gloopy = 0;          // debug print flag
    const int item_amt = 10; // 10 is the constant required amt

    phone phone_array[item_amt];

    /*  commenting out because its debug code
	// debug read
	if (glorpy) { 
		read_file(phone_array, &count);
	}

	// debug write; should only execute if phone_array isn't empty
	if (glorpy && dingus) { 
		write_file(phone_array, count);
	}

	// debug print. wacky ahh code
	if (glorpy && gloopy) {
		print_struct(phone_array, count);
	}
	*/

    menu(phone_array, count);

    // debug pause before quit; unnecessary in prod
    // cin.get();
    // cin.get();
    return 0;
}
