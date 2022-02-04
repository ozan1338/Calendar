#include<iostream>
#include "calender.h"
#include<string>
#include<conio.h>

using namespace std;

int calender::totaldate(int m, int y)
{
long unsigned td11 = 0;
for (int i = 1990; i<y; i++)
{
for (int m = 1; m <= 12; m++)
{
if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12)
td11 = td11 + 31;
if (m == 4 || m == 6 || m == 9 || m == 11)
td11 = td11 + 30;
if (m == 2)
{
if (i % 4 == 0)
td11 = td11 + 29;
else
td11 = td11 + 28;
}
}
}


for (int j = 1; j<m; j++)
{
if (j == 1 || j == 3 || j == 5 || j == 7 || j == 8 || j == 10 || j == 12)
td11 = td11 + 31;
if (j == 4 || j == 6 || j == 9 || j == 11)
td11 = td11 + 30;
if (j == 2)
{
if (y % 4 == 0)
td11 = td11 + 29;
else
td11 = td11 + 28;
}
}

return ((td11 + 1) % 7);
}

void calender::ShowCalender(int s, int m, int y)
{
int x[7][6];
int k;
if (s == 0)
k = 1;
if (s == 1)
k = 0;
if (s == 2)
k = -1;
if (s == 3)
k = -2;
if (s == 4)
k = -3;
if (s == 5)
k = -4;
if (s == 6)
k = -5;

for (int i = 0; i<6; i++)
{
for (int j = 0; j<7; j++)
{
x[j][i] = k++;
}
}

cout << "\n\t\t\t";
if (m == 1) cout << "Jan\t" << y;
if (m == 2) cout << "Feb\t" << y;
if (m == 3) cout << "March\t" << y;
if (m == 4) cout << "April\t" << y;
if (m == 5) cout << "May\t" << y;
if (m == 6) cout << "June\t" << y;
if (m == 7) cout << "July\t" << y;
if (m == 8) cout << "August\t" << y;
if (m == 9) cout << "Sep\t" << y;
if (m == 10) cout << "Oct\t" << y;
if (m == 11) cout << "Nov\t" << y;
if (m == 12) cout << "Dec\t" << y;

cout << "\n\n";
for (int i = 0; i<7; i++) {
cout << "\t";
if (i == 0) cout << "Sun\t";
if (i == 1) cout << "Mon\t";
if (i == 2) cout << "Tues\t";
if (i == 3) cout << "Wed\t";
if (i == 4) cout << "Thur\t";
if (i == 5) cout << "Fri\t";
if (i == 6) cout << "Sat\t";
if (x[i][0]>0) cout << x[i][0] << "\t"; else cout << "\t";
cout << x[i][1] << "\t" << x[i][2] << "\t" << x[i][3] << "\t";
if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12)
{
if (x[i][4] <= 31) cout << x[i][4] << "\t";
if (x[i][5] <= 31) cout << x[i][5];
}
else if (m == 4 || m == 6 || m == 9 || m == 11)
{
if (x[i][4] <= 30) cout << x[i][4] << "\t";
if (x[i][5] <= 30) cout << x[i][5];
}
else if (m == 2)
{
if (y % 4 == 0)
{
if (x[i][4] <= 29) cout << x[i][4] << "\t";
if (x[i][5] <= 29) cout << x[i][5];
}
else
{
if (x[i][4] <= 28) cout << x[i][4] << "\t";
if (x[i][5] <= 28) cout << x[i][5];
}
}
cout << "\n";
}
cout << "- Enter your command (NPCALDSRQ) = ";
}
