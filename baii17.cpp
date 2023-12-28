#include<iostream>
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
        virtual long tinhtoan()= 0;

        //hàm lấy giá trị của x và n
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

        //ghi đè phương thức tính toán
        long tinhtoan() override
        {
            long S= 0, T= 1, M= 1;
            for(int i= 1; i<= n; i++)
            {
                T = T * x;
                M = M * i;
                S = S + T/M;
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
        //n mà nhỏ hơn 1 thì nhập lại
        cin >> n;
    }
    cin >> x;

    Sum sum(n, x);
    cout<< sum.tinhtoan() << endl;
    return 0;    
}
