#include<iostream>
#include "calender.h"
#include<conio.h>
#include<ctime>
#include<fstream>
#include<vector>
#include<string>
#include<sstream>

using namespace std;

int main()
{	
	calender calender_;
	vector<calender> events;
	int m, y, d;
	int n, p, c;
	int d_,m_,y_;
	string des;
	time_t t=time(0);
	struct tm*now=localtime(&t);
	y=now->tm_year+1900;
	m=now->tm_mon+1;
	d=now->tm_mday;
	  
	d = calender_.totaldate(m,y);
	calender_.ShowCalender(d,m,y);
	char z;
	do
	{
	z = cin.get();
	switch (z)
	{
	case 'n':
	case 'N':{
    if (++m>12) { ++y; m = 1; }
	d = calender_.totaldate(m,y);
	calender_.ShowCalender(d,m,y);
	break;
   	}
  
	case 'p':
	case 'P':{
    if (--m<1) { --y; m = 12; }
	d = calender_.totaldate(m,y);
	calender_.ShowCalender(d,m,y);
    break;
   	}
	case 'c':
    case 'C':{
    	
        cout<<"\n\tEnter month : ";
        cin>>m_;
        cout<<"\n\tEnter year : ";
        cin>>y_;
        m=m_;
        y=y_;
        d = calender_.totaldate(m,y);
		calender_.ShowCalender(d,m,y);
break;
       }
case 'a':
    case 'A':{
        cout<<"\n\tEnter day : ";
        cin>>d_;
        cout<<"\n\tEnter month : ";
        cin>>m_;
        cout<<"\n\tEnter year : ";
        cin>>y_;
        cout<<"\n\tEnter description : ";
        cin.ignore();
       getline(cin,des);
       
        calender event(d_,m_,y_,des,events.size());
        events.push_back(event);
        cout<<"\n\tCurrent EVENT id is "<<event.getID()<<endl;
           calender_.ShowCalender(d,m,y);
           break;
       }
case 'l':
    case 'L':{
   
        for(int i=0;i<events.size();i++){
            calender evnt=events[i];
            cout<<"\nEvent ID : "<<evnt.getID();
            cout<<"\t\tDate : "<<evnt.getDay()<<"-"<<evnt.getMonth()<<"-"<<evnt.getYear()<<endl;
            cout<<"\nDescription : "<<evnt.getDescription()<<endl;
		   }      
        calender_.ShowCalender(d,m,y);
           break;
       }
case 'd':
    case 'D':{
           cout<<"\n\tEnter event ID : ";
        int id;
        cin>>id;
        int ind=-1;
        for(int i=0;i<events.size();i++){
            calender evnt=events[i];
            if(id==evnt.getID()){
                ind=i;
                break;
               }
           }
       
        if(events.size()>ind && id>=0){
              events.erase(events.begin()+ind,events.begin()+ind+1);
              cout<<"\n\tEvent deleted\n";
           }
           else{
           cout<<"\n\tEvent not found\n";
           }
           calender_.ShowCalender(d,m,y);
           break;
       }
    case 's':
    case 'S':{
        cout<<"\n\tEnter File Name : ";
       string file;
       cin>>file;
         
       ofstream out;
         
       out.open(file.c_str());
         
       if(out.fail()){
          cout<<"\n\tFile error.";
       }
       else{
              for(int i=0;i<events.size();i++){
                  calender event=events[i];
                  out<<event.getDay()<<" "<<event.getMonth()<<" "<<event.getYear()<<" "<<event.getID();
                  out<<endl;
                  out<<event.getDescription();
                  out<<"\n";
           }  
             
           out.close();
             
           cout<<"\n\tData save in file "<<file<<endl<<endl;   
           }
   calender_.ShowCalender(d,m,y);
           break;
       }
    case 'r':
    case 'R':{
    cout<<"\n\tEnter File Name : ";
       string file;
       cin>>file;
      
       ifstream in;
         
       in.open(file.c_str());
         
       if(in.fail()){
          cout<<"\n\tFile not found.\n\n";
       }
       else{
         
          int a,b,c,id;
          string l;
         
          while(!in.eof()){
              getline(in,l);
              stringstream ss;
              ss<<l;
              ss>>a;
              ss>>b;
              ss>>c;
              ss>>id;
               getline(in,l);
                 
               calender event(a,b,c,des,0);
               event.setID(id);
                 
               events.push_back(event);
           }

               int ind=events.size()-1;
               events.erase(events.begin()+ind,events.begin()+ind+1);
          in.close();
         
       cout<<"\n\tData load from file "<<file<<endl<<endl;   
       }
calender_.ShowCalender(d,m,y);
           break;
       }
case 'q':
      case 'Q':
exit(0);

}
} while (z != 'e');
return 0;
}

