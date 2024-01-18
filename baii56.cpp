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
        friend istream& operator>> (istream& out, Number& num)
        {
            out>> num.n;
            return out;
        }

        //nạp chồng toán tử xuất
        friend ostream& operator<< (ostream& in, const Number& num)
        {
            int temp= num.n;
            bool check= true;
            while (temp/= 10)
            {
                if((temp%10)% 2== 0)
                {
                    check= false;
                    break;
                }
            }
            if(check== true)
            {
                in<<num.n << " la so ma cac chu so deu la le! "<< endl;
            }
            else
            {
                in<< num.n << " khong la so ma cac chu so deu la le! "<< endl;
            }
            return in;
        }

        //hàm lấy giá trị của n
        int getN() const
        {
            return n;
        }
};

//tạo lớp KetQua được kế thừa từ lớp Number
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
        if(num.getN()< 0)
        {
            cout<< "Nhap lai"<< endl;
        }
    } while (num.getN()< 0);
    cout<< num<< endl;
    return 0;
}
