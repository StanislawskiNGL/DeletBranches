#include <string>
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <array>
#include <sstream>
#include <vector>

std::string execute_command(std::string command);

std::vector <std::string> text_splitting(std::string s, char division_criterion);

std::vector <std::string> add_git_branch(int a, int b, std::vector <std::string> branches);

void list_branches(std::vector <std::string> branches);

void select_branches(int a, int b, std::vector<std::string> branches);

void delete_branch(int a, int b, std::vector<std::string> branches, std::vector <std::string> copy_branches);
