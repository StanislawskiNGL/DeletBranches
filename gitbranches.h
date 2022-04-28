#include <string>
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <array>
#include <string.h>
#include <sstream>
#include <vector>



//#include "gitbranches.cpp"



using namespace std;

/*

//std::string save_command(string command);

void delete_branches(int a, int b, vector<string>branches );

vector <string> cut_line_branches(string s);

vector <string> add_git_branch(int a, int b, vector<string> branches);

void list_branches(vector<string> branches);

void select_branches(int a, int b, vector<string> branches);

void delete_branch(vector <string> branches, int a, int b)


*/




std::string save_command(string command)
{
    FILE* pipe1 = popen("git checkout Master", "r");
    pclose(pipe1);
   
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

void delete_branch(int a, int b, vector<string> branches,vector<string> copy_branches)
{

    std::array<char, 128> buffer;
    std::string result;

    char check_answer[1];


    std::string check_merge ;



    for (int i = 0; i< branches.size();i++)
    {
        if(a<=i && b>=i)
        {
            FILE* pipe = popen(branches[i].c_str(), "r");

                while (fgets(buffer.data(), 128, pipe) != NULL) 
                {
      
                    result += buffer.data();
                }

                check_merge = "error: The branch " + branches[i] +"  is not fully merged.\nIf you are sure you want to delete it, run 'git branch -D testing'";

                if(result == check_merge)
                {
                    cout << "Do you want to delete: " << copy_branches[i]<<" (Y/N)"<<endl;

                    cin >> check_answer[0];

                    if (check_answer == "Y" || check_answer == "y" )
                    {
                        copy_branches[i] = "git branch -D " + copy_branches[i];

                        FILE* pipe1 = popen(copy_branches[i].c_str(), "r");

                        pclose(pipe1);

                    }

                }
   
            auto returnCode = pclose(pipe);
        }


    }

}
