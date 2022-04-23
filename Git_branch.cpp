
#include "gitbranches.h"



int main()
{
    
    vector <string> branches;

    string text;



    text = save_command("ls");

    branches = cut_line_branches(text);

    list_branches(branches);

    branches = add_git_branch(branches);

    //string branches[] = strtok(text , "\n");

    //std::cout<<text<<endl;

    

    for(int i = 0; i<branches.size();i++)
    {
        cout<< branches[i]<<endl;
    }
   // std::cout << returnCode << std::endl;

    return 0;
}