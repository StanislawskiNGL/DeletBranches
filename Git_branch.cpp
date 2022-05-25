
#include "gitbranches.h"





int main()
{
   Branches program_git; 

   int select_first,select_end;
   
    program_git.list_branches();

    std::cout<<"select branches to be removed"<< std::endl;

    std::cin>> select_first >> select_end;

    program_git.delete_branch(select_first, select_end);

    return 0;
}
