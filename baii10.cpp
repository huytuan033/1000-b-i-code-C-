#include<iostream>
#include<math.h>
using namespace std;

//lớp trừu tượng TinhToan
class TinhToan
{
    protected:
        int n;
        int x;
    
    public:
        //hàm khởi tạo
        TinhToan (int n= 0, int x= 0): n(n), x(x)
        {

        }
        //phương thức trừu tượng tính toán
        virtual long tinhtoan()= 0;

        //hàm lấy giá trị của x và n
        int giatriX()
        {
            return x;
        }
        int giatriN()
        {
            return n;
        }
};

//tạo lớp SoMu kế thừa từ lớp TinhToan
class SoMu: public TinhToan
{
    public:
        //hàm khởi tạo
        SoMu(int n= 0, int x= 0): TinhToan(n, x)
        {

        }

        //nạp chồng toán tử nhân
        SoMu operator*(const SoMu& other)
        {
            long ketQua= this-> n* other.n;
            return SoMu(ketQua);
        }

        //ghi đè phương thức tinhtoan
        long tinhtoan() override
        {
            long soMu= pow(x, n);
            return soMu;
        }
};

int main()
{
    int x, n;
    cin>> x >>n;
    SoMu soMu(x, n);
    cout<< soMu.tinhtoan()<< endl;
    return 0;
}