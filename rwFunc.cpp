#include "rwFunc.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

// DO NOT FORGET THIS FOR STARS' SAKE
using namespace std;

int read_file(phone *ph, int *count) {

	ifstream in("device.db"); // ifstream - Input File STREAM

	// check if file exists by calling its .good value
	// if It Aint Good, don't proceed
	if (!in.good()) { 
		// cerr - prints to stderr
		cerr << "barbeque bacon burger" << endl;
		return EXIT_FAILURE;
	}

	int i = 0;
	string input_string;
	istringstream token;

	while (getline(in, input_string)) {
		// debug print (commenting out because it prints into terminal)
		// clog << "[CLOG] WHOLE STRING: " << input_string;
		
		token.str(input_string);

		// okay umm. oh stars.
		// because C++ is Very Good and Obviously The Best Language Ever
		// and because we cannot really iterate splitting the string
		// because of differing data types, we Stupidly ""Iterate""
		// through the string, effectively inflating a simple strtok
		// function into this mess. special props to int properties
		// being unwritable with this function because you NEED a std::string
		string temp;
		getline(token, temp, ';');  // I CHANGED MY MIND. I HATE C++
		ph[i].id = stoi(temp);
		getline(token, ph[i].make, ';');
		getline(token, ph[i].model, ';');
		getline(token, temp, ';');
		ph[i].in_stork = stoi(temp);
		getline(token, temp, ';');
		ph[i].type = stoi(temp);
		getline(token, temp, ';');
		ph[i].price = stoi(temp);

		i++;
	}

	// passing *count as NULL returns a nullptr which is. yeah
	//   (this is from debugging & lazy vixxy)
	*count = i; 
	in.close();

	clog << "[CLOG] he was running from a cop car (read file & wrote struct data)" << endl;

	return EXIT_SUCCESS;
}

int write_file(const phone *ph, const int count) {

	/*
	 WARNING: DO NOT WRITE INTO ACTUAL FILE UNTIL YOU'RE 
	 400% SURE IT WON'T OVERWRITE THE DATA!!
	 or keep a backup of the data but like
	 are u ever like that.
	*/

	ofstream out("dataout.db");

	if (!out.good()) {
		// probably never happens but oh well
		cerr << "Cabron. I need to see your BOSS." << endl
			 << "[ could not create output file. (What?) ]" << endl; 
		return EXIT_FAILURE;
	}

	string output_string;

	for (int i = 0; i < count; i++) {
		// format is apparently quite new so it wont work even in MSVS 2015. bummer
		output_string = to_string(ph[i].id) + ";" + ph[i].make + ";" + ph[i].model + ";"
			+ to_string(ph[i].in_stork) + ";" + to_string(ph[i].type) + ";" + to_string(ph[i].price) + ";";
		out << output_string << endl;
	}

	out.close();

	clog << "[CLOG] wrote file :] (probably)" << endl;

	return EXIT_SUCCESS;
}