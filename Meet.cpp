#include <iostream>
#include <string>
#include <vector>
#include "Meet.h"

Meet::Meet() //default
{
    
}

void Meet::book(std::string& str) //default
{
    size_t searchpos;
    year=mon=day=0;

    //get meet DATA
    searchpos = str.find(" ");
    datemeet = str.substr(0,searchpos);
    str.erase (0,searchpos+1);
    this->updateYMD();
    /*year=((int(datemeet[0])-'0')*1000 +
          (int(datemeet[1])-'0')*100 +
          (int(datemeet[2])-'0')*10 +
          (int(datemeet[3])-'0'));
    mon=((int(datemeet[5])-'0')*10 +
          (int(datemeet[6])-'0'));
    day=((int(datemeet[8])-'0')*10 +
          (int(datemeet[9])-'0'));*/

    
    //get meet START
    searchpos = str.find(" ");
    startmeet = str.substr(0,searchpos);
    str.erase (0,searchpos+1);

    //get meet END
    searchpos = str.find(" ");
    endmeet = str.substr(0,searchpos);
    str.erase (0,searchpos+1);
    

    //get meet NAME    
    searchpos = str.find(" ");
    namemeet = str.substr(0,searchpos);
    str.erase (0,searchpos+1);

    //get meet NOTE
    notemeet = str.substr(0,str.size());
    str.erase (0,str.size());

    return;
}

void Meet::unbook(std::string& str)
{    
    size_t searchpos;

    //get meet DATA
    searchpos = str.find(" ");
    datemeet = str.substr(0,searchpos);
    str.erase (0,searchpos+1);

    
    //get meet START
    searchpos = str.find(" ");
    startmeet = str.substr(0,searchpos);
    str.erase (0,searchpos+1);

    //get meet END
    endmeet = str.substr(0,str.size());
    str.erase (0,str.size());

    return;
}

void Meet::change_part1(std::string& str)
{
    size_t searchpos;

    searchpos = str.find(" ");
    datemeet = str.substr(0,searchpos);
    str.erase (0,searchpos+1);

    searchpos = str.find(" ");
    startmeet = str.substr(0,searchpos);
    str.erase (0,searchpos+1);
}

void Meet::change_part2(std::string& str,Meet&meet)
{
    size_t searchpos;

    searchpos = str.find(" ");
    std::string option=str.substr(0,searchpos);
    if(option == meet.datemeet)
    {
        str.erase (0,searchpos+1);
        datemeet = str;
    }
    else if(option == meet.startmeet)
    {
        str.erase (0,searchpos+1);
        startmeet = str;
    }
    else if(option == meet.endmeet)
    {
        str.erase (0,searchpos+1);
        endmeet = str;
    }
    else if(option == meet.namemeet)
    {
        str.erase (0,searchpos+1);
        namemeet = str;
    }
    else
    {
        searchpos = str.find(notemeet);
        if(searchpos==0)
        {
            str.erase(0,notemeet.size()+1);
            notemeet=str;
        }
        else
        std::cout<<"Someting is go wrong!\n";
    }
    this->updateYMD();///Year Mon Day
}

void Meet::updateYMD()
{
    year=((int(datemeet[0])-'0')*1000 +
        (int(datemeet[1])-'0')*100 +
        (int(datemeet[2])-'0')*10 +
        (int(datemeet[3])-'0'));

    mon=((int(datemeet[5])-'0')*10 +
        (int(datemeet[6])-'0'));

    day=((int(datemeet[8])-'0')*10 +
        (int(datemeet[9])-'0'));
}

bool Meet::find(std::string& str)
{
    size_t pos;
    pos = namemeet.find(str);
    if(pos <= namemeet.size())
        return true;
    pos = notemeet.find(str);
    if(pos <= notemeet.size())
        return true;
    return false;    
}

void Meet::print()
{
    std::cout<<"\nName: "<<namemeet<<"\n"
             <<"Note: "<<notemeet<<"\n"
             <<"Data: "<<datemeet<<"\n"
             <<startmeet<<" - "<<endmeet<<"\n";
             //<<year<<":"<<mon<<":"<<day<<"\n";
}



Meet::~Meet() //destructor
{

}
