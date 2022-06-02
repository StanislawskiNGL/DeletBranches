

#include "gitbranches.h"


using namespace std;


Branches::Branches()
{
        std::string add_branches;

        add_branches = execute_command("git branch --merged") + execute_command("git branch --no-merged");

        size_merged_branches = text_splitting(execute_command("git branch --merged"),'\n').size();

        size_no_merged_branches = text_splitting(execute_command("git branch --no-merged"),'\n').size();

        branches = text_splitting(add_branches, '\n');

        swap_master();
}

std::string Branches::execute_command(std::string command)
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

std::vector <std::string> Branches::text_splitting(std::string s, char division_criterion)
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

void Branches::list_branches()
{

    for(int i = 0; i< branches.size();i++)
    {
        if (i<size_merged_branches)
        {
        std::cout<<i<<" "<<branches[i]<<std::endl;
        }
        else
        {
            std::cout<<i<<" "<<branches[i]<<" NO MERGED"<<std::endl;
        }
    }
}

void Branches::select_branches(int a, int b)
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

void Branches::delete_branch(int a, int b)
{

    bool flag = true;

    std:: string check_answer;

    for (int i = 0; i< branches.size();i++)
    {
        if(a<=i && b>=i)
        {
            if(i<size_no_merged_branches)
            {

            flag = false;

            }

            if(flag == true)
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

void Branches::swap_master()
{
    for(int i = 0 ; i < branches.size(); i++ )
    {
        if(branches[i]=="master" || branches[i]=="* master" )
        {
            branches[i].swap(branches[0]);
            break;
        }
    }

    
}

