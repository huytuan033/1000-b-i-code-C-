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
            bool check= true;
            int temp= num.n;
            //lấy ra chữ số cuối
            int chuSoCuoi= temp% 10;
            temp/= 10;    
            while(temp!= 0)
            {
                int chuSoKeCuoi= temp% 10;
                temp/= 10;
                if(chuSoCuoi< chuSoKeCuoi)
                {
                    check= false;
                    break;
                }
                else
                {
                    //cập nhật lại chữ số cho lần so sánh kế tiếp
                    chuSoCuoi= chuSoKeCuoi;
                }
            }
            if(check)
            {
                xuat<<num.n<<" la so co cac chu so tang dan tu trai sang phai"<< endl;
            }
            else
            {
                xuat<<num.n<<" khong la so co cac chu so tang dan tu trai sang phai"<< endl;
            }  
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
        //thêm constructor mặc định
        KetQua(): Number()
        {

        }

        //constructor với tham số
        KetQua (int num): Number(num)
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