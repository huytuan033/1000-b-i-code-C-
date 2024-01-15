#include <iostream>
using namespace std;

class Number
{
protected:
    int n;

public:
    // constructor mặc định
    Number() : n(0)
    {

    }

    // constructor với tham số
    Number(int num) : n(num)
    {
        
    }

    // nạp chồng toán tử nhập
    friend istream &operator>>(istream &in, Number &num)
    {
        in >> num.n;
        return in;
    }

    // nạp chồng toán tử xuất
    friend ostream &operator<<(ostream &out, const Number &num)
    {
        int i;
        int max = 0;
        int temp = num.n; // tạo biến tạm thời
        if (temp == 0)
        {
            max = 0;
        }
        do
        {
            i = temp % 10;
            if (i > max)
            {
                max = i;
            }
        } while (temp /= 10); // sử dụng biến tạm thời
        out << max << endl;
        return out;
    }

    // hàm lấy giá trị của n
    int getN() const
    {
        return n;
    }
};

// lớp KetQua kế thừa từ lớp Number
class KetQua : public Number
{
public:
    // thêm constructor mặc định
    KetQua() : Number()
    {

    }

    // constructor với tham số
    KetQua(int num) : Number(num)
    {

    }
};

int main()
{
    KetQua num;
    do
    {
        cin >> num;
    } while (num.getN() < 0 && cout << "Nhap lai!");
    cout << num << endl;
    return 0;
}
