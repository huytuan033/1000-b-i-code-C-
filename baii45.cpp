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
        friend istream& operator>> (istream& in, Number& num)
        {
            in>> num.n;
            return in;
        }

        //nạp chồng toán tử xuất <<
        friend ostream& operator<< (ostream& out, const Number& num)
        {
            int n1= num.n;
            int P= 1;
            while(n1 != 0)
            {
                P= P * (n1 % 10);
                n1 = n1 / 10;
            }
            out<< P<< endl;
            return out;
        }

        //hàm lấy giá trị của n
        int getN() const
        {
            return n;
        }
};

//Lớp KetQua kế thừa từ lớp Number
class KetQua: public Number
{
    public:
        //constructor mặc định
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
