#include<iostream>
#include<cmath>
using namespace std;

class Number
{
protected:
    int n;

public:
    // Constructor mặc định
    Number() : n(0) {}

    // Constructor với tham số
    Number(int num) : n(num) {}

    // Nạp chồng toán tử >>
    friend istream& operator>>(istream& nhap, Number& num)
    {
        nhap >> num.n;
        return nhap;
    }

    // Nạp chồng toán tử <<
    friend ostream& operator<<(ostream& xuat, const Number& num)
    {
        float S = sqrt(2.0f);
        for(int i = 2; i <= num.n; i++)
        {
            S = sqrt(2 + S);
        }
        xuat << S << endl;
        return xuat;
    }

    // Hàm getter để lấy giá trị của n
    int getN() const
    {
        return n;
    }
};

// Lớp KetQua kế thừa từ lớp Number
class KetQua : public Number
{
public:
    // Thêm constructor mặc định
    KetQua() : Number() {}

    // Constructor với tham số
    KetQua(int num) : Number(num) {}
};

int main()
{
    KetQua num;
    do
    {
        cin >> num;
        if(num.getN() < 1)
        {
            cout << "Nhap lai" << endl;
        }
    } while(num.getN() < 1);
    cout << num << endl;
    return 0;
}
