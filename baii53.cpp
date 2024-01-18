/*bài 53/1000: xem số n nhập vào thì chữ số nào lớn nhất và nó xuất hiện bao nhiêu lần */

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
            int max= 0, dem= 1;
            int temp = num.n;
            do
            {
                i= temp % 10;
                if(i== max)
                {
                    dem++;
                }
                if(i> max)
                {
                    max= i;
                    dem = 1;
                }
            } while (temp /= 10);
            xuat<< "Max= "<< max<< endl;
            xuat<< "So luong chu so lon nhat: "<< dem;  
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
