#include <string>
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <array>
#include <string.h>
#include <sstream>
#include <vector>

std::string execute_command(std::string command);
/*{
   
    FILE* pipe = popen(command.c_str(), "r");
    std::array<char, 128> buffer;
    std::string result;
    if (!pipe)
    {
        
        return 0;

    }
    while (fgets(buffer.data(), 128, pipe) != NULL) 
    {
      
        result += buffer.data();
    }
    
    auto returnCode = pclose(pipe);

    return result;


}*/

std::vector <std::string> text_splitting(std::string s, char division_criterion);
/*{
    std::vector <std::string> branches;

    std::stringstream ss(s);

    std::string item;
    
    while(getline(ss,item, division_criterion))
    {
        branches.push_back(item);
    }
    return branches;
}
*/
std::vector <std::string> add_git_branch(int a, int b, std::vector <std::string> branches);
/*{

    for(int i = 0; i<branches.size();i++)
    {
        branches[i] = "git branch -d " + branches[i];
    }

    return branches;

}
*/
void list_branches(std::vector <std::string> branches);
/*{
    for(int i = 0; i< branches.size();i++)
    {
        std::cout<<i<<" "<<branches[i]<<std::endl;
    }
}
*/
void select_branches(int a, int b, std::vector<std::string> branches);
/*{
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
*/
void delete_branch(int a, int b, std::vector<std::string> branches, std::vector <std::string> copy_branches);
/*{

    std::string result;

    char check_answer[1];

    std::string check_merge ;

    std::vector <std::string> check_error ;



    for (int i = 0; i< branches.size();i++)
    {
        if(a<=i && b>=i)
        {

            check_merge =  execute_command(branches[i]);

            check_error = text_splitting(check_merge, ' ');


            if("error" == check_error[1])
                {
                    std::cout << "Do you want to delete: " << copy_branches[i]<<" (Y/N)"<<std::endl;

                    std::cin >> check_answer[0];

                    if (check_answer == "Y" || check_answer == "y" )
                    {
                        copy_branches[i] = "git branch -D " + copy_branches[i];

                        execute_command(copy_branches[i]);

                    }

                }
            
        }


    }

}
*/
