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

        //nạp chồng toán tử nhập
        friend istream& operator>>(istream& nhap, Number& num)
        {
            nhap>> num.n;
            return nhap;
        }

        //nạp chồng toán tử xuất
        friend ostream& operator<<(ostream& xuat, const Number& num)
        {
            int temp= num.n;
            int soChuSo= static_cast<int>(log10(static_cast<float>(temp)))+ 1;
            int soNghichDao= 0;
            int temp2 = temp;
            while(temp2!= 0)
            {
                //lấy chữ số ra
                int chuSo= temp2% 10;
                //bỏ chữ số mà vừa lấy ra
                temp2/= 10;
                soNghichDao+= chuSo* pow(10.0,--soChuSo);
            }
            if(soNghichDao== temp)
            {
                xuat<< "So doi xung"<< endl;
            }
            else
            {
                xuat<< "So khong doi xung"<< endl;
            }
            return xuat;
        }

        //hàm lấy giá trị của n
        int getN()
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
        if(num.getN()<= 0)
        {
            cout<< "Nhap lai"<< endl;
        }
    } while (num.getN()<= 0);
    cout<< num<< endl;
    return 0;
}
