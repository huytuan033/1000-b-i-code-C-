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

        //tạo constructor với tham số
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
            bool CheckGiamDan= true;
            int themang= num.n;
            int themang2 = num.n; // biến mới để xuất ra
            //lấy ra chữ số cuối
            int ChuSoCuoi= themang% 10;
            themang/= 10;

            while(themang!= 0)
            {
                int ChuSoKeCuoi= themang% 10;
                themang/= 10;
                if(ChuSoKeCuoi< ChuSoCuoi)
                {
                    CheckGiamDan= false;
                    break;
                }
                else
                {
                    //cập nhật lại chữ số cho lần so sánh tiếp theo
                    ChuSoCuoi= ChuSoKeCuoi;
                }
            }
            if(CheckGiamDan)
            {
                xuat<< "Cac chu so cua "<< themang2<< " giam dan tu trai sang phai "<< endl;
            }
            else
            {
                xuat<< "Cac chu so cua "<< themang2<< " khong giam dan tu trai sang phai "<< endl;
            }
            return xuat;
        }

        //hàm lấy giá trị của n
        int getN() const
        {
            return n;
        }
};

//lớp KetQua kế thừa từ lớp Number
class KetQua: public Number
{
    public:
        //thêm constructor mặc định
        KetQua(): Number()
        {

        }

        //constructor mặc định
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
        if (num.getN()<= 0)
        {
            cout<< "Nhap lai"<< endl;
        }
        
    } while (num.getN()<= 0);
    cout<< num<< endl;
    return 0;   
}
