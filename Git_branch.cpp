
#include "gitbranches.h"



int main()
{
    
    std::vector <std::string> branches, copy_branches;

    std::string text;

    int select_first,select_end;

    text = execute_command("git branch");

    branches = text_splitting(text , '\n');

    copy_branches = branches;

    list_branches(branches);

    std::cout<<"select branches to be removed"<< std::endl;

    std::cin>> select_first >> select_end;

    select_branches(select_first, select_end, branches);


    branches = add_git_branch(select_first, select_end, branches);

    delete_branch(select_first, select_end, branches, copy_branches);

    return 0;
}