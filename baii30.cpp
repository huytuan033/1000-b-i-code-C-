// bài toán kiểm tra số hoàn hảo
//Cho một số n, nếu tổng của các ước số của n cộng vào bằng chính n

#include<iostream>
using namespace std;

//xây dựng lớp trừu tượng Number
class Number
{
    protected:
        int n;
    
    public:
        Number(int n= 0): n(n)
        {

        }
        //tạo phương thức ảo
        virtual void number()= 0;

        //hàm lấy giá trị của n
        int getN()
        {
            return n;
        }
};

//tạo lớp KetQua kế thừa lớp Number
class KetQua: public Number
{
    public:
        KetQua(int n= 0): Number(n)
        {

        }

        //nạp chồng toán tử cộng
        KetQua operator+ (const KetQua& other)
        {
            int ketQua= this -> n+other.n;
            return KetQua(ketQua);
        }

        void number() override
        {
            int sum= 0;
            for(int i= 1; i< n; i++)
            {
                if(n%i==0)
                {
                    sum+=i;
                }
            }
            if(sum== n)
            {
                cout<< n<<" la so hoan hao"<<endl;
            }
            else
            {
                cout<< n<<" khong la so hoan hao"<<endl;
            }
        }
};

int main()
{
    int n;
    cin>> n;
    KetQua ketQua(n);
    ketQua.number();
    return 0;
}