#ifndef MEET_H
#define MEET_H
#include <iostream>
#include <vector>
#include <string>

class Meet
{
    private:
    std::string datemeet;
    std::string startmeet,endmeet;
    int year,mon,day;
    std::string namemeet;
    std::string notemeet;
     

    public:
    //book(string);
    Meet();
    void book(std::string&);
    void unbook(std::string&);
    void change_part1(std::string&);
    void change_part2(std::string&,Meet&);
    bool find(std::string&);
    void updateYMD();


    void print();

    std::string getData() const {return datemeet;}
    std::string getStartmeet() const {return startmeet;}
    std::string getEndmeet() const {return endmeet;}
    std::string getNamemeet() const {return namemeet;}
    std::string getNotemeet() const {return notemeet;}
    int getYear() const {return year;}
    int getMon() const {return mon;}
    int getDay() const {return day;}
    ~Meet();

};

#endif
