#ifndef RWFUNC_HPP
#define RWFUNC_HPP
// iostream is required for std::string
#include <iostream>

typedef struct {
	int id;
	std::string make;
	std::string model;
	int in_stork; // keep "stork" for now lol
	int type;
	int price; // remember: price probably shouldnt exceed 65k
} phone;

int read_file(phone *ph, int *count);
int write_file(const phone *ph, const int count);

#endif
