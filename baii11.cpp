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
        virtual long tinhtoan()= 0;

        //hàm lấy giá trị của n
        int giatriN()
        {
            return n;
        }
};

//tạo lớp Sum được kế thừa từ TinhToan
class Sum: public TinhToan
{
    public:
        //hàm khởi tạo
        Sum(int n= 0): TinhToan(n)
        {

        }

        //nạp chồng toán tử cộng
        Sum operator+(const Sum& other)
        {
            long newSum= this-> n+ other.n;
            return Sum(newSum);
        }

        //ghi đè phương thức tinhtoan
        long tinhtoan() override
        {
            long S= 0, P= 1;
            for(int i= 1; i<= n; i++)
            {
                P*= i;
                S+= P;
            }
            return S;
        }
};

int main()
{
    int n;
    cin>> n;
    while (n< 1)
    {
        //nếu n< 1 thì bắt nhập lại
        cin>>n;
    }

    Sum sum(n);
    cout<<sum.tinhtoan()<<endl;
    return 0;
    
}