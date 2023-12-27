#include <iostream>
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

        //tạo phương thức trừu tượng tinhtoan
        virtual double tinhtoan()= 0;

        //hàm lấy giá trị của n
        int giatriN()
        {
            return n;
        }
};

//tạo lớp Sum kế thừa từ lớp TinhToan
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
            double newSum= this-> n+ other.n;
            return Sum(newSum);
        }

        //ghi đè phương thức tinhtoan
        double tinhtoan() override
        {
            double sum= 0.0f;
            for(int i= 0; i<= n; i++)
            {
                sum+= ((2*(float)i) +1)/((2*(float)i) +2);
            }
            return sum;
        }
};

int main()
{
    int n;
    cin>> n;

    //tạo đối tượng trong thuộc lớp Sum
    Sum sum(n);
    cout<< sum.tinhtoan()<<endl;
    return 0;
}