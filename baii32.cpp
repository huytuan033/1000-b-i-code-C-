//kiểm tra số chính phương
//tạo một biến a, căn bậc 2 của a x căn bậc 2 của a= n thì oke

#include<iostream>
#include<math.h>
using namespace std;

//xây dựng tính đóng gói
class Number
{
    protected:
        int n; //đây là dữ liệu được đóng gói bên trong lớp

    public:
        //xây dựng tính trừu tượng
        Number() :n(n)
        {

        }

        Number(int num): n(num)
        {

        }

        //xây dựng tính đa hình
        friend istream& operator>>(istream& nhap, Number& num)
        {
            nhap>> num.n;
            return nhap;
        }

        friend ostream& operator<<(ostream& xuat, const Number& num)
        {
            if(sqrt(num.n)==(int)sqrt(num.n))
            {
                cout<< num.n<<" la so chinh phuong"<<endl;
            }
            else
            {
                cout<< num.n<<" khong la so chinh phuong"<<endl;
            }
            return xuat;
        }
        //lấy n từ lớp con
        int getN() const
        {
            return n;
        }
};

//Xây dựng lớp Sochinhphuong kế thừa lớp Number
class Sochinhphuong : public Number
{
    public:
        Sochinhphuong(int num): Number(num)
        {

        }
};

int main()
{
    Sochinhphuong num(0);
    do
    {
        cin>> num;
        if(num.getN() <= 0)
        {
            cout<< "Nhap lai"<<endl;
        }
    }while (num.getN() <= 0);
    cout<< num<<endl;
    return 0;
}