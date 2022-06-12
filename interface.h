
#include <string>
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <array>
#include <string.h>
#include <sstream>
#include <vector>
#include <algorithm>
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

std::vector <int> text_splitting_on_int(std::string s, char division_criterion)
{
    std::vector <int> branch_numbers_to_be_deleted;

    std::stringstream ss(s);

    std::string item;
    
    while(getline(ss,item, division_criterion))
    {
        branch_numbers_to_be_deleted.push_back(std::stoi(item));
    }
    return branch_numbers_to_be_deleted;
}

void select_branch_interval(std::vector <std::string> list,std::string number_text)
{
    std::vector <int> interval=text_splitting_on_int(number_text,'-');

    //std::sort(interval.begin(),interval.end(),interval.size());

    for(int i=0;i<list.size();i++)
    {
        if(interval[0]<=i && interval[1]>=i)
        {
            std::cout<<i<<" "<<"* "<<i << " "<<list[i]<<std::endl;
        }
        else
        {
            std::cout<<i<<" "<<list[i]<<std::endl;
        }
    }

}

bool check_points(std::string number_text, int iteration )
{
    bool check = false;
    std::vector <int> points =  text_splitting_on_int(number_text,',');

    for(int i = 0 ; i<points.size();i++)
    {
        if(points[i]==iteration)
        {
            check = true;
        }
    }
    return check;

}

void select_concrete_branches(std::string number_text, std::vector <std::string> list)
{

    //std::sort(points.begin(),points.begin(),points.size());

    for(int i=0;i<list.size();i++)
    {
        if(check_points(number_text,i))
        {
            std::cout<<"* "<<i << " "<<list[i]<<std::endl;
        }
        else
        {
            std::cout<<i<<" "<<list[i]<<std::endl;
        }
    }

}