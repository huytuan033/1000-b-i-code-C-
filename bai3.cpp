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
        virtual double tinh()=0;

        //hàm lấy giá trị của n
        int getN()
        {
            return n;
        }
};

//tạo lớp Sum kế thừa từ lớp tinh
class Sum: public Tinh
{
    public:
        //hàm khởi tạo
        Sum(int n= 0): Tinh(n)
        {

        }

        //nạ chồng toán tử cộng
        Sum operator+(const Sum& other)
        {
            int newSum= this->n +other.n;
            return Sum(newSum);
        }

        //ghi đè phương thức tinh
        double tinh()override
        {
            double sum= 0.0;
            for(int i= 1; i<= n; i++)
            {
                sum+= 1.0/i;
            }
            return sum;
        }
};


int main()
{
    int n; 
    cin>> n;

    //tạo đối tượng trong thuộc tính lớp
    Sum sum(n);
    cout<<sum.tinh()<<endl;
    return 0;
}