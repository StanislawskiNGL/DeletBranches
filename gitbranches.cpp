

#include "gitbranches.h"
#include <string>
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <array>
#include <string.h>
#include <sstream>
#include <vector>

using namespace std;


std::string execute_command(std::string command)
{
   
    FILE* pipe = popen(command.c_str(), "r");
    array <char, 512> buffer;
    std::string result;
    if (!pipe)
    {
        
        return 0;

    }
    while (fgets(buffer.data(), 512, pipe) != NULL) 
    {
      
        result += buffer.data();
    }
    
    auto returnCode = pclose(pipe);
   

    return result;


}

std::vector <std::string> text_splitting(std::string s, char division_criterion)
{
    std::vector <std::string> branches;

    std::stringstream ss(s);

    std::string item;
    
    while(getline(ss,item, division_criterion))
    {
        branches.push_back(item);
    }
    return branches;
}

std::vector <std::string> add_vector(std::vector <std::string> merged_branch, std::vector <std::string>  no_merged_branch)
{
    std::vector <std::string> branches;

    for(int i = 0; i< merged_branch.size();i++)
    {
        branches.push_back(merged_branch[i]);
    }

    for(int i = 0; i< merged_branch.size();i++)
    {
        branches.push_back(no_merged_branch[i]);
    }

    return branches;
}

void list_branches(std::vector <std::string> branches, int size_m_b, int size_n_m_b)
{

    for(int i = 0; i< branches.size();i++)
    {
        if (i<size_m_b)
        {
        std::cout<<i<<" "<<branches[i]<<std::endl;
        }
        else
        {
            std::cout<<i<<" "<<branches[i]<<" NO MERGED"<<std::endl;
        }
    }
}

void select_branches(int a, int b, std::vector <std::string> branches)
{
    for(int i=0;i<branches.size();i++)
    {
        if(a>=i && b<=i)
        {
            std::cout<<"* "<<i << " "<<branches[i]<<std::endl;
        }
        else
        {
            std::cout<<branches[i]<<std::endl;
        }
    }
}

void delete_branch(int a, int b, std::vector<std::string> branches, int size_m_b, int size_n_m_b)
{

    bool flag = true;

    std:: string check_answer;

    for (int i = 0; i< branches.size();i++)
    {
        if(a<=i && b>=i)
        {
            if((i-size_m_b)==(size_n_m_b-1))
            {

            flag = false;

            }

            if(flag)
            {
                execute_command("git  branch -d " + branches[i]);
            }


            else
                {
                    std::cout << "Do you want to delete: " << branches[i]<<" (Y/N)"<<std::endl;

                    std::cin >> check_answer;

                    if (check_answer == "Y" || check_answer == "y")
                    {
                        
                        execute_command("git branch -D" + branches[i]);

                    }

                }
            
        }


    }

}


