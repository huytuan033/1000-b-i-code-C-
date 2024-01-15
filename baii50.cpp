#include<iostream>
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
        Number(int num): n(num)
        {

        }

        //hàm lấy giá trị của n
        int getN() const
        {
            return n;
        }

        //nạp chồng toán tử xuất
        friend istream& operator>> (istream& nhap, Number& num)
        {
            nhap>> num.n;
            return nhap;
        }

        //nạp chồng toán tử<<
        friend ostream& operator<< (ostream& xuat, const Number& num)
        {
            int temp = num.n;
            do
            {
                cout<< temp%10;
            } while (temp /= 10);
            return xuat;
        }
};

//lớp KetQua kế thừa lớp Number
class KetQua: public Number
{
    public:
        //thêm constructor mặc định vào
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
    } while (num.getN()< 0 && cout<< "Nhap lai!");
    cout<< num<<endl;
    return 0;
}
