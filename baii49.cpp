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

        //nạp chồng toán tử xuất >>
        friend istream& operator>> (istream& nhap, Number& num)
        {
            nhap>>num.n;
            return nhap;
        }

        //nạp chồng toán tử nhập
        friend ostream& operator<< (ostream& xuat, const Number& num)
        {
            int n1= num.n;
            int i;
            do
            {
                i= n1% 10;
            } while (n1/= 10);
            xuat<< i<< endl;
            return xuat;
        }

        //hàm lấy giá trị của n
        int getN() const
        {
            return n;
        }
};

//lớp KetQua kế thừa từ lớp Number
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
    } while (num.getN()< 0);
    cout<< num<< endl;
    return 0;
}