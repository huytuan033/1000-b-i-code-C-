// bài toán kiểm tra số nguyên tố
// nhập n vào và nó là snt khi chia hết cho 1 và nó

#include <iostream>
#include <cmath>
using namespace std;

// tạo lớp trừu tượng Number
class Number
{
protected:
    int n;

public:
    Number(int n = 0) : n(n)
    {
    }

    // phương thức ảo
    virtual void number() = 0;

    // hàm lấy giá trị của n
    int giatriN()
    {
        return n;
    }
};

// tạo lớp KetQua kế thừa lớp Number
class KetQua : public Number
{
public:
    KetQua(int n = 0) : Number(n)
    {
    }

    // nạp chồng toán tử chia
    KetQua operator/(const KetQua &other)
    {
        int ketQua = this->n / other.n;
        return KetQua(ketQua);
    }

    void number() override
    {
        bool check = true;
        for (int i = 2; i <= sqrt(n); i++)
        {
            if (n % i == 0)
            {
                check = false;
                break;
            }
        }
        if (check)
            cout << n << " la so nguyen to." << endl;
        else
            cout << n << " khong phai la so nguyen to." << endl;
    }
};

int main()
{
    int n;
    do
    {
        cin >> n;
        if (n <= 0)
        {
            cout << "khong phai so nguyen duong, nhap lai" << endl;
        }
        else
        {
            KetQua kq(n);
            kq.number();
            break;
        }
    } while (true);
    return 0;
}
