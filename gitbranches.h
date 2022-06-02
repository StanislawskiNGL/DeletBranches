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
    private:

    std::vector<std::string> branches;

    int size_merged_branches,size_no_merged_branches;


    public:

    Branches();
    

    std::vector<std::string> get_branches();

    std::string execute_command(std::string command);

    std::vector <std::string> text_splitting(std::string s, char division_criterion);

    std::vector <std::string> add_git_branch(int a, int b);

    void list_branches();

    void select_branches(int a, int b);

    void delete_branch(int a, int b);

    void swap_master();

};

#endif

