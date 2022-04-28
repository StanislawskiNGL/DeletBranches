#include "gitbranches.h"




std::string save_command(string command)
{

   
    FILE* pipe = popen(command.c_str(), "r");
    std::array<char, 128> buffer;
    std::string result;
    if (!pipe)
    {
        
        return 0;

    }
    while (fgets(buffer.data(), 128, pipe) != NULL) {
      
        result += buffer.data();
    }

   
    
    
    auto returnCode = pclose(pipe);

    return result;


}

 void delete_branches(int a, int b, vector<string>branches )
 {
     for (int i; i<branches.size();i++)
     {
         
     }
 }
vector <string> cut_line_branches(string s)
{
    vector <string> branches;

    stringstream ss(s);

    string item;
    
    while(getline(ss,item,'\n'))
    {
        branches.push_back(item);
    }
    return branches;
}

vector <string> add_git_branch(int a, int b, vector<string> branches)
{

    for(int i = 0; i<branches.size();i++)
    {
        branches[i] = "git branch -d " + branches[i];
    }

    return branches;

}

void list_branches(vector<string> branches)
{
    for(int i = 0; i< branches.size();i++)
    {
        cout<<i<<" "<<branches[i]<<endl;
    }
}

void select_branches(int a, int b, vector<string> branches)
{
    for(int i=0;i<branches.size();i++)
    {
        if(a>=i && b<=i)
        {
            cout<<"* "<<i << " "<<branches[i]<<endl;
        }
        else
        {
            cout<<branches[i]<<endl;
        }
    }
}

