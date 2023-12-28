#include<iostream>
#include<math.h>
using namespace std;

//tạo lớp trừu tượng TinhToan
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

        //phương thức trừu tượng
        virtual long tinhtoan()= 0;

        //hàm lấy giá trị của x và n
        int gitriX()
        {
            return x;
        }
        int giatriN()
        {
            return n;
        }
};

//tạo lớp Sum được kế thừa từ lớp TinhToan
class Sum: public TinhToan
{
    public:
        //hàm khởi tạo
        Sum(int n= 0, int x= 0): TinhToan(n, x)
        {

        }

        //nạp chồng toán tử cộng
        Sum operator+(const Sum& other)
        {
            long newSum= this-> x+other.x;
            int newN= this-> n > other.n ? this-> n:other.n;
            return Sum(newN, newSum);
        }

        //ghi đè phương thức tính toán
        long tinhtoan() override
        {
            long S= 0, T= 1;
            for(int i= 1; i<= n; i++)
            {
                T = pow(x, (2 * i ));
                S = S + T;
            }
            return S;
        }
};

int main()
{
    int n, x;
    cin>> x >> n;
    while (n< 1)
    {
        //n mà nhỏ hơn 1 thì nhập lại
        cin>> n;
    }

    Sum sum(n, x);
    cout<<sum.tinhtoan()<<endl;
    return 0;    
}