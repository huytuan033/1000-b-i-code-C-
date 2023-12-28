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

        //phương thức trừu tượng
        virtual float tinhtoan()= 0;

        //hàm lấy giá trị của n
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
        Sum(int n= 0): TinhToan(n)
        {

        }

        //nạp chồng toán tử cộng
        Sum operator+(const Sum& other)
        {
            float newSum= this-> n +other.n;
            return Sum( newSum);
        }

        //ghi đè phương thức tính toán
        float tinhtoan() override
        {
            float S= 0, T= 0;
            for(int i= 1; i<= n; i++)
            {
                T+= i;
                S+= 1.0/T;
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
        //n mà nhỏ hơn 1 thì nhập lại
        cin>> n;
    }

    Sum sum(n);
    cout<<sum.tinhtoan()<<endl;
    return 0;    
}
