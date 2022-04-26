
#include "gitbranches.h"



int main()
{
    
    vector <string> branches;

    string text;

    int select_start,select_end;



    text = save_command("ls");

    branches = cut_line_branches(text);

    list_branches(branches);

    branches = add_git_branch(select_start, select_end, branches);

    

    

    for(int i = 0; i<branches.size();i++)
    {
        cout<< branches[i]<<endl;
    }
   

    return 0;
}