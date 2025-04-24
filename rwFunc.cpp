#include "rwFunc.hpp"
#include <iostream>
#include <fstream>
#include <string>

// DO NOT FORGET THIS FOR STARS' SAKE
using namespace std;

int read_file(phone *ph, int *count) {

	ifstream in("data.db"); // ifstream - Input File STREAM

	// kinda magic? check if file exists by calling its .good value
	// if It Aint Good, don't proceed
	if (!in.good()) { 
		// cerr - prints to stderr. Internet Knowledge
		cerr << "barbeque bacon burger" << endl;
		return EXIT_FAILURE;
	}

	int i = 0;
	string input_string;
	size_t semicolon_position;
	size_t current_pos;
	string debug_output;

	while (getline(in, input_string)) {
		cout << "WHOLE STRING: " << input_string;
		
		// okay umm. oh stars.
		// because C++ is Very Good and Obviously The Best Language Ever
		// and because we cannot really iterate splitting the string
		// because of differing data types, we Stupidly ""Iterate""
		// through the string, effectively inflating a simple strtok
		// function into this mess.
		semicolon_position = input_string.find(";");
		ph[i].id = stoi(input_string.substr(0, semicolon_position));
		current_pos = semicolon_position;

		semicolon_position = input_string.find(";", current_pos);
		ph[i].make = input_string.substr(current_pos, semicolon_position - current_pos);
		current_pos = semicolon_position;

		semicolon_position = input_string.find(";", current_pos);
		ph[i].model = input_string.substr(current_pos, semicolon_position - current_pos);
		current_pos = semicolon_position;

		semicolon_position = input_string.find(";", current_pos);
		ph[i].in_stork = stoi(input_string.substr(current_pos, semicolon_position - current_pos));
		current_pos = semicolon_position;

		semicolon_position = input_string.find(";", current_pos);
		ph[i].type = stoi(input_string.substr(current_pos, semicolon_position - current_pos));
		current_pos = semicolon_position;

		semicolon_position = input_string.find(";", current_pos);
		ph[i].price = stoi(input_string.substr(current_pos, semicolon_position - current_pos));
		current_pos = semicolon_position;

		debug_output = to_string(ph[i].id) + " " + ph[i].make + " " + ph[i].model + " " 
					 + to_string(ph[i].in_stork) + " " + to_string(ph[i].type) + to_string(ph[i].price);
		cout << endl << debug_output << endl;
		i++;
	}

	// passing *count as NULL returns a nullptr which is. yeah
	*count = i; 
	in.close();

	return EXIT_SUCCESS;
}

int write_file(phone *ph, const int count) {

	/*
	 WARNING: DO NOT WRITE INTO ACTUAL FILE UNTIL YOU'RE 
	 400% SURE IT WON'T OVERWRITE THE DATA!!
	 or keep a backup of the data but like
	 are u ever like that.
	*/

	ofstream out("dataout.db");

	int i;

	if (!out.good()) {
		cerr << "Cabron. I need to see your BOSS." << endl
			 << "[ could not create output file. (What?) ]" << endl; 
		return EXIT_FAILURE;
	}

	string output_string;

	for (i = 0; i < count; i++) {
		// format is apparently quite new so it wont work in MSVS 2015. bummer
		output_string = ph[i].make + ";" + ph[i].model;
		out << output_string;
	}

	// count = i; // count is const. shouldn't redefine?
	// this probably shouldn't even be here tbh,, we'll see
	out.close();

	return EXIT_SUCCESS;
}