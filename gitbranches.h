#include <string>
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <array>
#include <string.h>
#include <sstream>
#include <vector>




using namespace std; // TODO - remove it.



std::string save_command(string command);

void delete_branches(int a, int b, vector<string>branches );

vector <string> cut_line_branches(string s);

vector <string> add_git_branch(int a, int b, vector<string> branches);

void list_branches(vector<string> branches);

void select_branches(int a, int b, vector<string> branches);

void delete_branch(vector <string> branches, int a, int b)


