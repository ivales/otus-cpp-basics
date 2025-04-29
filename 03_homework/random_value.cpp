#include <iostream>
#include <cstdlib>
#include <ctime>

#include "random_value.h"

	int gen_guessed_number(int max_value) {


		std::srand(std::time(nullptr)); // use current time as seed for random generator

		return std::rand() % max_value;

	}
