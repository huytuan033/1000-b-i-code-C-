#include<iostream>
using namespace std;

//tạo lớp trừu tượng TinhToan
class TinhToan
{
    protected:
        int n;
    
    public:
        //hàm khởi tạo
        TinhToan (int n= 0): n(n)
        {

        }

        //phương thức trừu tượng tinhtoan
        virtual long tinhtoan()= 0;

        //hàm lấy giá trị của n
        int giatriN()
        {
            return n;
        }
};

//tạo lớp Tich kế thừa từ lớp TinhToan
class Tich: public TinhToan
{
    public:
        //hàm khởi tạo
        Tich(int n= 0): TinhToan(n)
        {

        }

        //nạp chồng toán tử nhân
        Tich operator*(const Tich& other)
        {
            long tichMoi= this-> n+ other.n;
            return Tich(tichMoi);
        }

        //ghi đè phương thức tichtoan
        long tinhtoan() override
        {
            long tich= 1;
            for(int i= 1; i<= n; i++)
            {
                tich*= i;
            }
            return tich;
        }
        
};

int main()
{
    int n;
    cin>> n;

    //tạo đối tượng trong thuộc lớp Tich
    Tich tich(n);
    cout<< tich.tinhtoan()<<endl;
    return 0;
}