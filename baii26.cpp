#include<iostream>
using namespace std;

class Number
{
    protected:
        int n;
    
    public:
        Number (int n= 0): n(n) {}

        virtual void number() = 0;

        int giatriN()
        {
            return n;
        }
};

class KetQua: public Number
{
    public:
        KetQua(int n= 0): Number(n) {}

        KetQua operator/ (const KetQua& other)
        {
            if (other.n == 0) {
                throw invalid_argument("Division by zero is not allowed.");
            }
            int ketQua= this -> n / other.n;
            return KetQua(ketQua);
        }

        void number() override
        {
            int sum= 1;
            for(int i= 1; i<= n; i++)
            {
                if(n%i==0 && i%2!=0)
                {
                    sum*=i;
                }
            }
            cout<< sum<<endl;
        }
};

int main()
{
    int n;
    cin>> n;
    KetQua ketqua(n);
    cout << "Tich cac uoc so le cua " << n << " la: ";
    ketqua.number();
    cout << endl;
    return 0;
}
