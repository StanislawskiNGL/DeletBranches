#include "interface.h"


int main()
{
    std::string get_comand;

    std::vector <std::string> list;

    char answear;
        
    int number_of_commas = 0;

    int where_is_char = 0;

    std::string get_text;

    bool flag= false;

    bool one_use_char_flag = true;

    get_comand = execute_command("git branch");


    list = text_splitting(get_comand, '\n'); 

    for(int i = 0; i<list.size();i++)
    {
        std::cout<<i<<" "<<list[i]<<std::endl;
    }

    while(1)
    {
        if(flag)
        {

        }

        
        std::cout<<"Select branches to delete" <<std::endl;

        std::cin>>get_text;

        for(;where_is_char<get_text.length();where_is_char++)
        {
            if(get_text[where_is_char] == '-' && where_is_char!=0)
            {
                select_branch_interval(list,get_text);
            }
        }

        for(where_is_char = 0;where_is_char<get_text.length();where_is_char++)
        {   
            if(get_text[where_is_char] == ',' && one_use_char_flag)
            {
                number_of_commas++;

                select_concrete_branches(get_text,list);

                one_use_char_flag = false;               
            }
        }

        std::cout<<"Do you want to make any changes?(Y/N) ";
        std::cin>>answear;
        if(answear == 'N' || answear =='n')
        {
            break;
        }
        else
        {
            flag = true;
        }

    }


    return 0;
}