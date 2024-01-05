#include<iostream>
#include<math.h>
using namespace std;

class Number
{
    protected:
        int n;
    
    public:
        //constructor mặc định
        Number(): n(0)
        {

        }

        //constructor với tham số
        Number(int num) : n(num)
        {

        }

        //nạp chồng toán tử >>
        friend istream& operator>>(istream& nhap, Number& num)
        {
            nhap >> num.n;
            return nhap;
        }

        //nạp chồng toán tử <<
        friend ostream& operator<<(ostream& xuat, const Number& num)
        {
            double S, M;
            int i;
            i= 1;
            M= 1;
            S= sqrt(0.0);
            while(i<= num.n)
            {
                M*= i;
                S= sqrt(M+ S);
                i++;
            }
            xuat<< S<< endl;
            return xuat;
        }

        //hàm getter để lấy giá trị của n
        int giatriN() const
        {
            return n;
        }
};

//lớp KetQUa kế thừa từ lớp Number
class KetQua: public Number
{
    public:
        //thêm constructor mặc định
        KetQua(): Number()
        {

        }

        //constructor với tham số
        KetQua(int num): Number(num)
        {

        }
};

int main()
{
    KetQua num;
    do
    {
        cin>> num;
        if(num.giatriN()< 1)
        {
            cout<< "Nhap lai"<<endl;
        }
    } while (num.giatriN()< 1);
    cout<< num<< endl;
    return 0;
}