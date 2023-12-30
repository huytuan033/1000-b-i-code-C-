#include<iostream>
using namespace std;

//tạo lớp trừu tượng Number
class Number
{
    protected:
        int n;
    
    public:
        Number(int n= 0): n(n)
        {

        }

        virtual void number() =0;

        //hàm lấy giá trị của n
        int giatriN()
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

        //nạp chồng toán tử chia
        KetQua operator/ (const KetQua& other)
        {
            if(other.n== 0)
            {
                throw invalid_argument("n phai khac 0");
            }
            int ketQua= this -> n/other.n;
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
            cout<< sum<< endl;
        }
};

int main()
{
    int n;
    cin>> n;
    KetQua ketqua(n);
    cout<<"Tong cua cac uoc so nho hon "<< n<<" la: ";
    ketqua.number();
    cout<< endl;
    return 0;
}