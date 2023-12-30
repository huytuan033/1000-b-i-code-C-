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
            int i, max;
            do
            {
                if (n<= 0)
                {
                    cout<<"Nhap lai"<<endl;
                }           
            } while (n<= 0);
            i= 1;
            max= 1;
            while (i<= n)
            {
                if((n%i==0) && (i&2!=0))
                {
                    if(i> max)
                    {
                        max= i;
                    }
                }
                i++;
            }
            cout<< max<<endl;
        }
};

int main()
{
    int n;
    cin>> n;
    KetQua ketqua(n);
    cout<<"Uoc so le lon nhat cua "<< n<<" la: ";
    ketqua.number();
    cout<< endl;
    return 0;
}