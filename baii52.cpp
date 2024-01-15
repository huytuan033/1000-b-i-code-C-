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
        int temp = num.n; // tạo biến tạm thời
        int min= temp% 10;
        if (temp == 0)
        {
            min = 0;
        }
        do
        {
            i = temp % 10;
            if (i < min)
            {
                min = i;
            }
        } while (temp /= 10); // sử dụng biến tạm thời
        out << min << endl;
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
