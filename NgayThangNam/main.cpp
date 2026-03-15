#include<iostream>
using namespace std;
struct Date
{
    int day,month,year;
};
void Xuat(Date a)
{
    cout<<a.day<<"/"<<a.month<<"/"<<a.year<<endl;
}
Date Add(Date a)
{
    Date x=a;
    x.day++;
    switch(x.month)
    {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        if(x.day>31)
        {
            x.month++;
            x.day=1;
        }
        if(x.month>12)
        {
            x.month=1;
            x.year++;
        }
        break;
    case 4:
    case 6:
    case 9:
    case 11:
        if(x.day>30)
        {
            x.month++;
            x.day=1;
        }
        break;
    case 2:
        if(x.year%400==0)
        {
            if(x.day>29)
            {
                x.month++;
                x.day=1;
            }
        }
        else
        {
            if(x.day>28)
            {
                x.month++;
                x.day=1;
            }
        }
        break;
    }
    return x;





    }
int main()
{
    Date a;
    cin>>a.day>>a.month>>a.year;
    Xuat(Add(a));
    return 0;
}
