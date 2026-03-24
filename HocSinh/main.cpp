#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

struct SV
{
    string HoTen;
    double toan;
    double van;
    double DTB;
};

// kiểm tra tên hợp lệ
bool KiemTraTen(string s)
{
    if (s.empty()) return false;

    for (int i = 0; i < s.length(); i++)
    {
        if (!(isalpha(s[i]) || s[i] == ' '))
            return false;
    }
    return true;
}

// kiểm tra điểm hợp lệ
bool KiemTraDiem(double x)
{
    return (x >= 0 && x <= 10);
}

void Xuat(SV a)
{
    cout << "DTB:" << endl;
    cout << fixed << setprecision(2) << a.DTB;
}

void NhapXuat(SV &a)
{
    // nhập tên
    do {
        cout << "Nhap ho ten: ";
        getline(cin, a.HoTen);

        if (!KiemTraTen(a.HoTen))
            cout << "Ten khong hop le! Nhap lai.\n";
    } while (!KiemTraTen(a.HoTen));

    // nhập điểm toán
    do {
        cout << "Nhap diem toan: ";
        cin >> a.toan;

        if (!KiemTraDiem(a.toan))
            cout << "Diem khong hop le (0-10)! Nhap lai.\n";
    } while (!KiemTraDiem(a.toan));

    // nhập điểm văn
    do {
        cout << "Nhap diem van: ";
        cin >> a.van;

        if (!KiemTraDiem(a.van))
            cout << "Diem khong hop le (0-10)! Nhap lai.\n";
    } while (!KiemTraDiem(a.van));

    a.DTB = (a.toan + a.van) / 2;

    Xuat(a);
}

int main()
{
    SV a;
    NhapXuat(a);
    return 0;
}

