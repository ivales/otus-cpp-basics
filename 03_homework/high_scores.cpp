#include <iostream>
#include <fstream>


#include "high_scores.h"

std::map<std::string, size_t> load_highscore_table () {

	std::map<std::string, size_t> highscores_table;

	std::ifstream in_file{high_scores_filename};
	if (!in_file.is_open()) {
		std::cout << "Failed to open file for read: " << high_scores_filename << "!" << std::endl;
	}

	std::string username;
	int high_score = 0;
	while (true) {
		// Read the username first
		in_file >> username;
		// Read the high score next
		in_file >> high_score;
		// Ignore the end of line symbol
		in_file.ignore();

		if (in_file.fail()) {
			break;
		}
		// Save the information to the map
		highscores_table.insert_or_assign(username, high_score);
	}

	return highscores_table;
}


void save_highscore_table(std::map<std::string, size_t> highscore_table) {

	// open file with td::ios::in to flush it before saving the map to iy.
	std::ofstream out_file{high_scores_filename, std::ios::in};
	if (!out_file.is_open()) {
		std::cout << "Failed to open file for write: " << high_scores_filename << "!" << std::endl;
		return;
	}

	// Append new results from map to the table:
	for(auto item : highscore_table) {
		out_file << item.first << ' ';
		out_file << item.second;
		out_file << std::endl;
	}
}


// Read the high score file and print all results
void show_highscore_table() {
		std::ifstream in_file{high_scores_filename};
		if (!in_file.is_open()) {
			std::cout << "Failed to open file for read: " << high_scores_filename << "!" << std::endl;
			return;
		}

		std::cout << "High scores table:" << std::endl;

		std::string username;
		int high_score = 0;
		while (true) {
			// Read the username first
			in_file >> username;
			// Read the high score next
			in_file >> high_score;
			// Ignore the end of line symbol
			in_file.ignore();

			if (in_file.fail()) {
				break;
			}

			// Print the information to the screen
			std::cout << username << '\t' << high_score << std::endl;
		}
	}


