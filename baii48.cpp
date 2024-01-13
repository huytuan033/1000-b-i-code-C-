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

        //nạp chồng toán tử nhập >>
        friend istream& operator>> (istream& nhap, Number& num)
        {
            nhap>>num.n;
            return nhap;
        }

        //nạp chồng toán tử xuất <<
        friend ostream& operator<< (ostream& xuat, const Number& num)
        {
            int n1= num.n;
            int P= 1;
            if(n1== 0)
            {
                cout<< 1<< endl;
            }
            while(n1!= 0)
            {
                if(n1%2==1)
                {
                    P*= (n1%10);
                }
                n1/= 10;
            }
            xuat<< P<< endl;
            return xuat;
        }

        //Hàm lấy giá trị của n
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