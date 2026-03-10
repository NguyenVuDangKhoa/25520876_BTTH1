#include <iostream>
#include<string>
#include<iomanip>
using namespace std;
 struct SV
 {
     string HoTen;
     double toan;
     double  van;
     double DTB;
 };
 void Xuat(SV a)
 {
     cout<<fixed<<setprecision(2)<<a.DTB;
 }
 void NhapXuat(SV&a)
 {
     cin>>a.HoTen>>a.toan>>a.van;
     a.DTB=(a.toan+a.van)/2;
     Xuat(a);

 }

int main()
{
    SV a;
    NhapXuat(a);
    return 0;
}
