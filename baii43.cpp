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
            int dem = 0;
            int n1= num.n;
            if(num.n== 0)
            {
                cout<< 1<< endl;
            }
            while(n1!= 0)
            {
                dem+=1;
                n1/= 10;
            }
            out<< dem<< endl;
            return out;
        }

        //Hàm lấy giá trị của n
        int getN() const
        {
            return n;
        }
};

//lớp KetQua kế thừa từ lớp Number
class KetQua: public Number
{
    public:
        //thêm constructor mặc định vô
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
