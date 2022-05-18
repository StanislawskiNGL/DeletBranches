
#include "gitbranches.h"



int main()
{
    
    std::vector <std::string> no_merged_branches, copy_branches, merged_branches, branches;

    std::string text1,text2, not_split_branches;

    int select_first,select_end, size_of_no_merged_branches_vector,size_of_merged_branches_vector,size_of_branches_vector;

    text1 = execute_command("git branch --merge");

    text2 = execute_command("git branch --no-merge");

    not_split_branches = text1 + text2;

    merged_branches = text_splitting(text1, '\n');

    size_of_merged_branches_vector = merged_branches.size();

    no_merged_branches = text_splitting(text2, '\n');

    size_of_no_merged_branches_vector = no_merged_branches.size();

    branches = text_splitting(not_split_branches, '\n');

    size_of_branches_vector = branches.size();

    //Why it doesn't work, it just pops up an exception

   // no_merged_branches = text_splitting(execute_command("git branch --no-merged"), '\n');

   // merged_branches = text_splitting(execute_command("git branch --merged"), '\n');
  //  
  //  branches = add_vector(merged_branches, no_merged_branches );

    list_branches(branches,size_of_merged_branches_vector,size_of_no_merged_branches_vector);

    std::cout<<"select branches to be removed"<< std::endl;

    std::cin>> select_first >> select_end;

    delete_branch(select_first, select_end, branches, size_of_merged_branches_vector, size_of_no_merged_branches_vector);

    return 0;
}