#ifndef BRANCHES_H
#define BRANCHES_H
#include <string>
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <array>
#include <string.h>
#include <sstream>
#include <vector>

class Branches
{
public:

    Branches();
    
    std::vector<std::string> get_branches();
    void list_branches();
    void delete_branch(int a, int b);
    
private:
    std::vector <std::string> text_splitting(std::string s, char division_criterion);
    std::vector <std::string> add_git_branch(int a, int b, std::vector <std::string> branches);
    void select_branches(int a, int b, std::vector<std::string> branches);
    void swap_master();    
    std::string execute_command(std::string command);

    std::vector<std::string> branches;
    int size_merged_branches,size_no_merged_branches;


};

#endif

