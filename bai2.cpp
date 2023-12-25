#include<iostream>
using namespace std;

//tạo lớp trừu tượng Tinh
class Tinh
{
    protected:
        int n;
    
    public:
        //hàm khởi tạo
        Tinh(int n= 0): n(n)
        {

        }

        //phương thức trừu tượng tinh
        virtual int tinh()= 0;

        //hàm lấy giá trị cho n
        int giatriN()
        {
            return n;
        }
};

//tạo lớp Sum kế thừa từ lớp Tinh
class Sum: public Tinh
{
    public: 
        //hàm khởi tạo
        Sum(int n= 0): Tinh(n)
        {

        }

        //nạp chồng toán tử cộng vào
        Sum operator+(const Sum& other)
        {
            int newSum= this->n+ other.n;
            return Sum(newSum);
        }

        //ghi đè phương thức tính
        int tinh() override
        {
            int sum= 0;
            for (int i= 1; i<= n; i++)
            {
                sum += i* i;
            }
            return sum;
        }
};


int main()
{
    int n;
    cin>> n;
    Sum sum(n);
    cout<<sum.tinh()<<endl;
    return 0;
}