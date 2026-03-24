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

bool isLeapYear(int year)
{
    return (year % 400 == 0) || (year % 4 == 0 && year % 100 != 0);
}
// trả về số ngày trong tháng
int daysInMonth(int month, int year)
{
    switch(month)
    {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        return 31;
    case 4:
    case 6:
    case 9:
    case 11:
        return 30;
    case 2:
        return isLeapYear(year) ? 29 : 28;
    default:
        return 0;
    }
}

// kiểm tra ngày hợp lệ
bool isValidDate(Date a)
{
    if (a.year <= 0) return false;

    if (a.month < 1 || a.month > 12) return false;
    if (a.day < 1 || a.day > daysInMonth(a.month, a.year)) return false;
    return true;
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
    do
    {
        cout << "Nhap ngay (day month year): ";
        cin >> a.day >> a.month >> a.year;

        if (!isValidDate(a))
            cout << "Ngay khong hop le! Nhap lai.\n";

    }
    while (!isValidDate(a));

    Xuat(Add(a));
    return 0;
}
