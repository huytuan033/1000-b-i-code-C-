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

        //nạp chồng toán tử nhập
        friend istream& operator>>(istream& nhap, Number& num)
        {
            nhap>> num.n;
            return nhap;
        }

        //nạp chồng toán tử xuất
        friend ostream& operator<<(ostream& xuat, const Number& num)
        {
            int i;
            int min= 1, dem= 0;
            int temp = num.n;
            do
            {
                i= temp % 10;
                if(i== min)
                {
                    dem++;
                }
                if(i< min)
                {
                    min= i;
                }
            } while (temp /= 10);
            xuat<< "Min= "<< min<< endl;
            xuat<< "So luong chu so nho nhat: "<< dem;  
            return xuat;           
        }

        //hàm lấy giá trị của n
        int getN() const
        {
            return n;
        }
};

//lớp KetQua được kế thừa từ lớp Number
class KetQua: public Number
{
    public:
        //thêm constructor mặc định vào
        KetQua(): Number()
        {
 
        }

        //thêm constructor với tham số
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
        if(num.getN()< 0)
        {
            cout<< "Nhap lai"<<endl;
        }
    } while (num.getN()< 0);
    cout<< num<< endl;
    return 0;
}
