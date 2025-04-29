#include <iostream>
#include <string>

#include "random_value.h"
#include "high_scores.h"
#include "check_value.h"

int main(int argc, char* argv[]) {

	
	if (argc>1) {
		for (int i = 1; i < argc; i++) {
			std::string arg_value{ argv[i] };
			if (arg_value == "-table") {
				show_highscore_table();
				return 0;
			}
			else if ((arg_value == "-max") && (i != argc-1)) {
				check_value(std::stoi(argv[i+1]));
				return 0;
			}
			else if ((arg_value == "-level") && (i != argc-1)) {
				switch (std::stoi(argv[i+1])) {
					case 1:
						check_value(10);
						return 0;
					case 2:
						check_value(50);
						return 0;
					case 3:
						check_value(100);
						return 0;
					default:
						std::cout << "Wrong difficulty level: it should be from 1 to 3" << std::endl;
						return 1;
				}
			}
			else {
				std::cout << "Usage: guess_the_number [-table] [-max N] [-level N] \n \
				-table : shows highscore table \n \
				-max N: set the range of guessed numbers (from 0 to N) \n \
				-level N: set the difficulty level (N should be from 1 to 3)" << std::endl;
			}
		}
	}
	else {
		check_value();
	}

	return 0;

}
