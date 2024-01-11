#include<iostream>
using namespace std;

class Number
{
    protected:
        int n;
    
    public:
        //tạo constructor mặc định
        Number(): n(0)
        {

        }

        //constructor với tham số
        Number(int num): n(num)
        {

        }

        //lấy giá trị của n
        int getN() const
        {
            return n;
        }

        //nạp chồng toán tử nhập
        friend istream& operator>> (istream& nhap, Number& num)
        {
            nhap>>num.n;
            return nhap;
        }

        //nạp chồng toán tử xuất
        friend ostream& operator<< (ostream& xuat, const Number& num)
        {
            int i= 0;
            int S= 0;
            while(S+ i< num.n)
            {
                i++;
                S+= i;
            }
            xuat<< i<< endl;
            return xuat;
        }
};

//tạo lớp KetQua được kế thừa từ lớp Number
class KetQua: public Number
{
    public:
        //thêm constructor mặc định zô
        KetQua(): Number()
        {

        }

        //tạo constructor với tham số
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
