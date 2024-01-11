#include<iostream>
using namespace std;

class Number
{
    protected:
        int n;
    
    public:
        //constructor mặc định
        Number(): n(n)
        {

        }

        //constructor với tham số
        Number(int num): n(num)
        {

        }

        //nạp chồng toán tử >> để nhập
        friend istream& operator>> (istream& nhap, Number& num)
        {
            nhap>>num.n;
            return nhap;
        }

        //nạp chồng toán tử << để xuất
        friend ostream& operator<<(ostream& xuat, const Number& num)
        {
            int i;
            double S;
            i= 0;
            S= 1;
            while(i<= num.n)
            {
                S= 1+ 1/S;
                i++;
            }
            xuat<< S<< endl;
            return xuat;
        }

        //hàm lấy giá trị của n
        int getN() const
        {
            return n;
        }
};

//tạo lớp KetQua kế thừa từ lớp Number
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
    cin>> num;
    cout<< num<< endl;
    return 0;
}