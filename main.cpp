#include <bits/stdc++.h> 
#include <fstream>
#include "Meet.cpp"

void BOOKmeet(Meet&meet, std::vector <Meet>&meets,std::string&str,bool canprint,bool mergeinfo)
{
    meet.book(str);
    bool canadd=true;
    for(int i=0;i<meets.size()&&meets.size()>=1;i++)
    {
        if(((meets[i].getData()==meet.getData())
        &&((meet.getStartmeet()<meets[i].getEndmeet() && meet.getStartmeet()>=meets[i].getStartmeet())
        || (meet.getEndmeet()<=meets[i].getEndmeet() && meet.getEndmeet()>meets[i].getStartmeet())
        || (meet.getStartmeet()<=meets[i].getStartmeet() && meet.getEndmeet()>=meets[i].getEndmeet())))
        
        ||meet.getStartmeet()>=meet.getEndmeet())
        {
            if(canprint)
            {
                std::cout<<"You can't add this meeting!\n";
                //std::cout<<meets[i].getData()<<" -. "<<meet.getData()<<"\n";
            }
            if(mergeinfo)
            {
                std::cout<<"Should we replace the existing meeting with this:\n";
                meet.print();
                std::cout<<"\nInput 'yes/no'\n";
                std::string in;
                for(;;)
                {
                    std::cout<<">_ ";
                    std::cin>>in;
                    if(in=="yes")
                    {
                        auto it=meets.begin();
                        for(int j=0;j<meets.size()&&meets.size()>=1;j++,it++)
                        {
                            if(((meets[j].getData()==meet.getData())
                            &&((meet.getStartmeet()<meets[j].getEndmeet() && meet.getStartmeet()>=meets[j].getStartmeet())
                            || (meet.getEndmeet()<=meets[j].getEndmeet() && meet.getEndmeet()>meets[j].getStartmeet())
                            || (meet.getStartmeet()<=meets[j].getStartmeet() && meet.getEndmeet()>=meets[j].getEndmeet())))
                                
                            ||meet.getStartmeet()>=meet.getEndmeet())
                            {
                                meets.erase(it);
                                it=meets.begin();
                                j=0;
                            }
                        }
                        meets.push_back(meet);
                        break;
                    }
                    else if(in=="no")
                    {
                        canadd=false;
                        break;
                    }
                    else
                        std::cout<<"Input 'yes/no'\n";
                }
            }
            canadd=false;
            break;
        }
        
    }
    if(canadd)
    {
        std::cout<<"Meet addes successful!\n";
        meets.push_back(meet);
    }
    return;
}

void UNBOOKmeet(Meet&meet, std::vector <Meet>&meets,std::string&str)
{
    meet.unbook(str);
    int i=0;
    for(auto it=meets.begin();it<meets.end();it++,i++)
    {
        if(meets[i].getData()==meet.getData()
        && meets[i].getStartmeet()==meet.getStartmeet()
        && meets[i].getEndmeet()==meet.getEndmeet())
        {
            meets.erase(it);
            return;
        }
    }
    return;
}

void AGENDAmeet(std::vector <Meet>&meets,std::string&str)
{
    std::vector <Meet> agandameets;
    int i=0;
    for(auto it=meets.begin();it<meets.end();it++,i++)
    {
        if(meets[i].getData()==str)
            agandameets.push_back(meets[i]);
    }
    i=0;
    for(auto it=agandameets.begin();it<agandameets.end()-1;it++,i++)
    {
        int j=i+1;
        for(auto jt=it+1;jt<agandameets.end();jt++,j++)
        {
            if(agandameets[i].getStartmeet() > agandameets[j].getStartmeet())
            std::swap(agandameets[i],agandameets[j]);
        }
    }

    for(int i=0;i<agandameets.size();i++)
    agandameets[i].print();
    return;
}

void CHANGEmeet(std::vector <Meet>&meets,Meet&meet,std::string&str)
{
    meet.change_part1(str);
    for(int i=0;i<meets.size();i++)
    {
        if(meet.getData() == meets[i].getData()
        && meet.getStartmeet() == meets[i].getStartmeet())
        {
            meets[i].change_part2(str,meet);
            break;
        }
    }
    return;
}

void FINDmeet(std::vector <Meet>&meets,std::string&str)
{
    for(int i=0;i<meets.size();i++)
    {
        if(meets[i].find(str))
            meets[i].print();
    }
    return;
}

void HOLIDAYS(std::vector <std::string>&holidays,std::string&str)
{
    holidays.push_back(str);
    return;
}

void BUSYDAYS(std::vector <Meet>&meets,std::string&str)
{
    std::vector <std::string> busyD;
    std::vector <int> minbusy;
    size_t searchpos=str.find(" ");
    std::string start;
    start=str.substr(0,searchpos);

    int yearS=0,monS=0,dayS=0;
    yearS=((int(str[0])-'0')*1000 +
          (int(str[1])-'0')*100 +
          (int(str[2])-'0')*10 +
          (int(str[3])-'0'));
    monS=((int(str[5])-'0')*10 +
          (int(str[6])-'0'));
    dayS=((int(str[8])-'0')*10 +
          (int(str[9])-'0'));
    str.erase(0,searchpos+1);

    int yearF=0,monF=0,dayF=0;
    yearF=((int(str[0])-'0')*1000 +
          (int(str[1])-'0')*100 +
          (int(str[2])-'0')*10 +
          (int(str[3])-'0'));
    monF=((int(str[5])-'0')*10 +
          (int(str[6])-'0'));
    dayF=((int(str[8])-'0')*10 +
          (int(str[9])-'0'));
    bool go=true;

    while(go)
    {
        for(int i=0;i<meets.size();i++)
        {
            if(yearS==meets[i].getYear() && monS==meets[i].getMon() && dayS==meets[i].getDay())
            {
                bool added=true;
                int pos=-1;
                for(int j=0;j<busyD.size();j++)
                {
                    if(busyD[j]==meets[i].getData())
                    {
                        added=false;
                        pos=j;
                    }
                }
                if(added)
                {
                    busyD.push_back(meets[i].getData());
                    minbusy.push_back(0);
                    pos=minbusy.size()-1;
                }
                int minS=0,minF=0;
                std::string S=meets[i].getStartmeet();
                std::string E=meets[i].getEndmeet();
                minS=((int(S[0])-'0')*600 +
                       (int(S[1])-'0')*60 +
                       (int(S[3])-'0')*10 +
                       int(S[4])-'0');

                minF=((int(E[0])-'0')*600 +
                       (int(E[1])-'0')*60 +
                       (int(E[3])-'0')*10 +
                       int(E[4])-'0');
                minbusy[pos]+=(minF-minS);
            }
        }

        //next day
        dayS++;
        if(dayS==32 && (monS==1||monS==3||monS==5||monS==7||monS==8||monS==10||monS==12))
        {
            dayS=1;
            if(monS==12)
            {
                monS=1;
                yearS++;
            }
            else
            monS++;
        }
        else if(dayS==31 && (monS==4||monS==6||monS==9||monS==11))
        {
            dayS=1;
            monS++;
        }
        else 
        {
            if(monS==2)
            {
                int max=28;
                if(yearS%4==0)
                max++;
                if(dayS==max+1)
                {
                    dayS=1;
                    monS++;
                }
            }
        }

        if(yearF==yearS && monF==monS && dayF==dayS)
        go=false;
    }
    for(int i=0;i<minbusy.size()-1;i++)
    {
        for(int j=i+1;j<minbusy.size();j++)
        {
            if(minbusy[i]>=minbusy[j])
            {
                std::swap(minbusy[i],minbusy[j]);
                std::swap(busyD[i],busyD[j]);
                if(busyD[i]>busyD[j] && minbusy[i]==minbusy[j])
                {
                    std::swap(minbusy[i],minbusy[j]);
                    std::swap(busyD[i],busyD[j]);
                }
            }
        }
    }
    for(int i=0;i<busyD.size();i++)
    {
        std::cout<<busyD[i]<<" "<<minbusy[i]/60<<" hours "<<minbusy[i]%60<<" min\n";
    }
    return;
}

void sortmeets(std::vector <Meet>&meets)
{
    for(int i=0;i<meets.size()-1;i++)
    {
        for(int j=i+1;j<meets.size();j++)
        {
            if(meets[i].getData()>=meets[j].getData())
            {
                std::swap(meets[i],meets[j]);
                if(meets[i].getStartmeet()>meets[j].getStartmeet()
                    && meets[i].getData()==meets[j].getData())
                {
                    std::swap(meets[i],meets[j]);
                }
            }
        }
    }
}

void FINDSLOT(std::vector <Meet>&meets,std::string&str)
{
    sortmeets(meets);
    int searchpos=str.find(" ");
    std::string data=str.substr(0,searchpos);
    str.erase(0,searchpos+1);
    int time=((int(str[0])-'0')*600 +
              (int(str[1])-'0')*60 +
              (int(str[3])-'0')*10 +
              int(str[4])-'0');
    
    bool can=false;
    bool firstmeet=true;
    bool datanotfound=true;
    for(int i=0;i<meets.size();i++)
    {
        if(data==meets[i].getData())
        {
            datanotfound=false;
            std::string endmeet;
            endmeet=meets[i].getEndmeet();
            bool havenext=false;
            int left;
            int right;
            if(firstmeet)
            {
                left=8*60;
                std::string startmeet=meets[i].getStartmeet();
                right=((int(startmeet[0])-'0')*600 +
                    (int(startmeet[1])-'0')*60 +
                    (int(startmeet[3])-'0')*10 +
                    int(startmeet[4])-'0');
                if(right-left>=time)
                {
                    if(!can)
                        std::cout<<"You can add a meeting within:\n";
                    can=true;
                    std::cout<<"08:00 - ";
                    left=right-time;
                    if(left/60<10)
                        std::cout<<"0";
                    std::cout<<left/60<<":";
                    if(left%60<10)
                        std::cout<<"0";
                    std::cout<<left%60<<"\n";
                }
                firstmeet=false;
            }
            left=((int(endmeet[0])-'0')*600 +
                    (int(endmeet[1])-'0')*60 +
                    (int(endmeet[3])-'0')*10 +
                    int(endmeet[4])-'0');
            if(i+1<meets.size())
            {
                if(data==meets[i+1].getData())
                {                
                    havenext=true;
                    std::string startmeet=meets[i+1].getStartmeet();
                    right=((int(startmeet[0])-'0')*600 +
                        (int(startmeet[1])-'0')*60 +
                        (int(startmeet[3])-'0')*10 +
                        int(startmeet[4])-'0');
                }
                if(!havenext)
                right=17*60;
            }
            else
                right=17*60;
            
            if(right-left>=time)
            {
                if(!can)
                    std::cout<<"You can add a meeting within:\n";
                can=true;
                std::cout<<meets[i].getEndmeet()<<" - ";
                left=right-time;
                if(left/60<10)
                    std::cout<<"0";
                std::cout<<left/60<<":";
                if(left%60<10)
                    std::cout<<"0";
                std::cout<<left%60<<"\n";
                
            }
        }
    }
    if(!can && !datanotfound)
        std::cout<<"You can't add a meeting with duration "<<str<<" on "<<data<<"!\n";
    if(datanotfound)
        std::cout<<"This whole day is free!\n";
    return;
}

void FINDSLOTwith(std::vector <Meet>&meets,std::string&str)
{
    std::string calendar=str,dataSearch;
    int pos=calendar.find(" ");
    dataSearch=calendar.substr(0,pos);
    calendar.erase(0,pos+1);
    pos=calendar.find(" ");    
    calendar.erase(0,pos+1);
    pos=str.find(calendar);
    str.erase(pos-1,str.size()-pos+1);
    //std::cout<<"|"<<dataSearch<<"|"<<calendar<<"|\n";
    std::fstream file (calendar);
    if (file.is_open())
    {
        std::string str;
        Meet meet;
        while ( getline (file,str) )
        {
            int searchspace=str.find(" ");
            std::string _data;
            _data=str.substr(0,searchspace);
            //std::cout<<_data<<"!\n";
            if(_data==dataSearch)
                BOOKmeet(meet,meets,str,false,false);
        }
        file.close();
    }
    FINDSLOT(meets,str);
}

void MERGE(std::vector <Meet>&meets,std::string&calendar)
{
    std::fstream file(calendar);
    if (file.is_open())
    {
        std::string str;
        Meet meet;
        while ( getline (file,str) )
        {
            BOOKmeet(meet,meets,str,false,true);
        }
        file.close();
    }
}

void OPEN(std::vector <Meet>&meets,std::string&namefile)
{
    std::fstream file (namefile);
    if (file.is_open())
    {
        std::string str;
        Meet meet;
        while ( getline (file,str) )
        {
            BOOKmeet(meet,meets,str,false,false);
        }
        file.close();
    }
    else
    {
        std::ofstream createFile(namefile);
    }
    std::cout<<"Successfully opened "<<namefile<<"\n";
    return;
}

void SAVE(std::vector <Meet>&meets,std::string&namefile)
{
    std::ofstream safefile (namefile);
    for(int i=0;i<meets.size();i++)
    {
        safefile<<meets[i].getData()<<" "<<meets[i].getStartmeet()<<" "<<meets[i].getEndmeet()<<" "<<meets[i].getNamemeet()<<" "<<meets[i].getNotemeet()<<"\n";
    }
    return;
}

void SAVEas(std::vector <Meet>&meets,std::string&str)
{
    SAVE(meets,str); 
    std::cout<<"Successfully saved another "<<str<<"!\n";
    return;
}
int main ()
{
    std::vector <Meet> meets;
    std::vector <std::string> holidays;
    Meet meet;
    bool CAnWork=false;
    std::string namefile;
    for(;;)
    {
        std::string str;
        std::string command;
        std::cout<<">_ ";
        std::cin>>command;

        std::getline(std::cin,str);
        str.erase (0,1);
        if(command == "book" && CAnWork)
            BOOKmeet(meet,meets,str,true,false);
        
        else if(command == "unbook" && CAnWork)
            UNBOOKmeet(meet,meets,str);

        else if(command == "agenda" && CAnWork)
            AGENDAmeet(meets,str);

        else if(command == "change" && CAnWork)
            CHANGEmeet(meets,meet,str);

        else if(command == "find" && CAnWork)
            FINDmeet(meets,str);

        else if(command == "holiday" && CAnWork)
            HOLIDAYS(holidays,str);

        else if(command == "busydays" && CAnWork)
            BUSYDAYS(meets,str);

        else if(command == "findslot" && CAnWork)
            FINDSLOT(meets,str);

        else if(command == "findslotwith" && CAnWork)
            FINDSLOTwith(meets,str);

        else if(command == "merge" && CAnWork)
        {
            std::cout<<"|"<<str<<"|\n";
            MERGE(meets,str);
        }




        else if(command == "open")
        {
            if(!CAnWork)
            {
                namefile=str;
                OPEN(meets,namefile);
                CAnWork=true;
            }
            else
            std::cout<<"You already have an open file!\n";
        }
        else if(command == "close" && CAnWork)
        {
            CAnWork=false;
            meets.clear();
            holidays.clear();
            std::cout<<"Successfully closed "<<namefile;
        }

        else if(command == "save" && CAnWork)
        {
            SAVE(meets,namefile);    
            std::cout<<"Successfully saved "<<namefile<<"\n";
        }

        else if(command == "saveas" && CAnWork)
            SAVEas(meets,str);

        else if(command == "help")
        {
            std::cout<<"\nThe following commands are supported:\nopen <file>	opens <file>\nclose			closes currently opened file\nsave			saves the currently open file\nsaveas <file>	saves the currently open file in <file>\nhelp			prints this information\nexit			exists the program\n";
        }

        else if(command == "exit")
        {
            std::cout<<"Exiting the program...\n\n";
            break;
            //return 0;
        }

        else
            std::cout<<"Command not found or you are not opened file!";
        std::cout<<"\n";
        if(meets.size()>1)
        sortmeets(meets);
    }




    /*for(int i=0;i<meets.size();i++)
    meets[i].print();*/
    /*for(int i=0;i<holidays.size();i++)
        std::cout<<holidays[i]<<"\n";*/
    return 0;
}
