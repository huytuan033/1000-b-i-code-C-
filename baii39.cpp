#include<iostream>
#include<cmath>
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

        //nạp chồng toán tử >>
        friend istream& operator>> (istream& nhap, Number& num)
        {
            nhap>> num.n;
            return nhap;
        }

        //nạp chồng toán tử <<
        friend ostream& operator<<(ostream& xuat, const Number& num)
        {
            int i;
            double S, M;
            i= 1;
            S= 0;
            M= 1;
            while(i<= num.n)
            {
                M*= i;
                S= pow((M+ S), 1.0/(i+1)); // Sửa từ S= pow((M+ S)*(1.0, 1.0/(i+1))) thành S= pow((M+ S), 1.0/(i+1))
                i++;
            }
            xuat<< S<<endl;
            return xuat;
        }

        //hàm getter dùng để lấy giá trị của n
        int getN() const
        {
            return n;
        }
};

//lớp KetQua được kế thừa từ lớp Number
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
        if(num.getN()< 1)
        {
            cout<< "Nhap lai"<<endl;
        }
    } while (num.getN()< 1);
    cout<<num<<endl;
    return 0;
    
}
