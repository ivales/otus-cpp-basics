#include <iostream>
#include <string>

#include "random_value.h"
#include "high_scores.h"
#include "check_value.h"

void check_value(int max_number) {

	const int target_value = gen_guessed_number(max_number);
	int current_value = 0;
	int player_tries = 1;
	std::string player_name;
	std::map<std::string, size_t> highscores_map = load_highscore_table();

	std::cout << "Welcome, stranger! Enter your name:" << std::endl;
	std::cin >> player_name;
	std::cout << "Enter your guess:" << std::endl;

	do {
		std::cin >> current_value;

		if (current_value < target_value) {
			std::cout << "Guessed number greater than " << current_value << std::endl;
			player_tries++;
		}
		else if (current_value > target_value) {
			std::cout << "Guessed number less than " << current_value << std::endl;
			player_tries++;
		}
		else {
			std::cout << "You win with " << player_tries << " tries!" << std::endl;
			break;
		}

	} while(true);

	if  (highscores_map.count(player_name)) {
		if (player_tries < highscores_map[player_name]) {
			highscores_map.insert_or_assign(player_name, player_tries);
			std::cout << "You've set a new record!" << std::endl;
		}
	}
	else highscores_map.insert_or_assign(player_name, player_tries);
	save_highscore_table(highscores_map);
	show_highscore_table();
}