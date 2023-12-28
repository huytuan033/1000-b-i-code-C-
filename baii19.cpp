#include<iostream>
#include<math.h>
using namespace std;

//tạo lớp trừu tượng TinhToan
class TinhToan
{
    protected:
        int n, x;

    public:
        //hàm khởi tạo
        TinhToan (int n= 0, int x= 0): n(n), x(x)
        {

        }

        //phương thức trừu tượng
        virtual double tinhtoan()= 0;

        //hàm lấy giá trị của n và x
        int giatriN()
        {
            return n;
        }
        int giatriX()
        {
            return x;
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
            int newN = this-> n + other.n;
            int newX = this-> x + other.x;
            return Sum(newN, newX);
        }

        //ghi đè phương thức tinhtoan
        double tinhtoan() override
        {
            double S = x;
            long M, N = 1;
            for(int i= 1; i<= n; i++)
            {
                double T = pow(x, (2 * i + 1));
                M = i * 2 + 1;
                N = N * M * (M - 1);
                S = S + T/N; 
            }
            return S;
        }
};

int main()
{
    int n, x;
    cin >> n;
    while (n < 1)
    {
        //n mà nhỏ hơn 1 thì phải nhập lại
        cin >> n;
    }
    cin >> x;

    Sum sum(n, x);
    cout<< sum.tinhtoan() << endl;
    return 0;    
}
