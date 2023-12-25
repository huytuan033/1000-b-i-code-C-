#include<iostream>
using namespace std;

//lớp trừu tượng TinhToan
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
        virtual int tinhtoan()= 0;

        //hàm lấy giá trị n
        int getN()
        {
            return n;
        }
};

//tạo lớp Tong kế thừa từ TinhToan
class Tong: public TinhToan
{
    public:
        //hàm khởi tạo
        Tong(int n= 0): TinhToan(n)
        {

        }

        //nạp chồng toán tử cộng
        Tong operator+(const Tong& other)
        {
            int tongMoi= this->n +other.n;
            return Tong(tongMoi);
        }

        //ghi đè phương thức tinhtoan
        int tinhtoan() override 
        {
            int tong= 0;
            for (int i= 1; i<= n; i++)
            {
                tong+= i;
            }
            return tong;
        }
};

int main()
{
    int n;
    cin>> n;
    
    //tạo đối tượng trong thuộc lớp Tong
    Tong tong(n);
    cout<< tong.tinhtoan()<< endl;
    return 0;
}
