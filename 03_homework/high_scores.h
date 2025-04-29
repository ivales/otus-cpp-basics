#include <map>
#include <string>


#ifndef HIGH_SCORES_H
#define HIGH_SCORES_H

const std::string high_scores_filename = "../high_scores.txt";
std::map<std::string, size_t> load_highscore_table();
void save_highscore_table(std::map<std::string, size_t>);
void show_highscore_table();


#endif