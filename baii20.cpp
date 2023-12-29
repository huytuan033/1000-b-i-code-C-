#include<iostream>
using namespace std;

// Tạo lớp trừu tượng Number
class Number
{
    protected:
        int n;
    
    public:
        // Hàm khởi tạo
        Number (int n= 0): n(n) {}

        // Phương thức trừu tượng
        virtual void number() = 0;

        // Hàm lấy giá trị n
        int giatriN()
        {
            return n;
        }
};

// Tạo lớp KetQua được kế thừa từ lớp Number
class KetQua: public Number
{
    public:
        // Hàm khởi tạo
        KetQua(int n= 0): Number(n) {}

        // Nạp chồng toán tử chia
        KetQua operator/ (const KetQua& other)
        {
            if (other.n == 0) {
                throw invalid_argument("Division by zero is not allowed.");
            }
            int ketQua= this -> n / other.n;
            return KetQua(ketQua);
        }

        // Ghi đè phương thức number
        void number() override
        {
            for(int i= 1; i<= n; i++)
            {
                if(n%i==0)
                {
                    cout<<" "<< i;
                }
            }
        }
};

int main()
{
    int n;
    cin>> n;

    // Tạo đối tượng thuộc lớp KetQua
    KetQua ketqua(n);
    cout << "Cac uoc so cua " << n << " la: ";
    ketqua.number();
    cout << endl;
    return 0;
}
