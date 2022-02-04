#pragma.once
#include<iostream>
#include<string>
#include<conio.h>
#include<ctime>
using namespace std;
class calender {
private:
	int id;
	int day;
	int month;
	int year;
	string description;
public:
calender() {
	}
	calender(int a,int b,int c,string _d,int e) {
	day = a;
	month = b;
	year = c;
	description = _d;
	id=b*10000+(a+31+e)*100+(c%100);
	}
	
   	void setID(int id_){id=id_;}
	void setDay(int a) { day = a; }
	void setMonth(int a) { month = a; }
	void setYear(int a) { year = a; }

	int getDay() { return day; }
	int getMonth() { return month; }
	int getYear() { return year; }
   	int getID(){return id;}

	void setDescription(string s) {description = s;}
	string getDescription() {return description;}
	
	int totaldate(int m, int y);
	void ShowCalender(int s, int m, int y);

};

