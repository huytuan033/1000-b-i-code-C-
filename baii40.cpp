#include<iostream>
#include<cmath>
using namespace std;

// Lớp cơ sở Number
class Number {
protected:
    float x;
    int n;
public:
    // Constructor
    Number(float x = 0, int n = 0) : x(x), n(n) {}

    // Đóng gói: các phương thức để thiết lập và lấy giá trị
    void setValues(float x, int n) {
        this->x = x;
        this->n = n;
    }

    float getX() const { return x; }
    int getN() const { return n; }

    // Tính trừu tượng: phương thức ảo để tính toán
    virtual float calculate() const = 0; // Pure virtual function

    // Nạp chồng toán tử nhập >>
    friend istream& operator>>(istream& in, Number& num) {
        num.setValues(0, 0); // Reset giá trị
        cout << "\nNhap x(x >= 0): ";
        do {
            in >> num.x;
            if(num.x < 0) {
                cout << "\nx khong hop le. Xin nhap lai !";
            }
        } while(num.x < 0);
        cout << "\nNhap n(n >= 1): ";
        do {
            in >> num.n;
            if(num.n < 1) {
                cout << "\nn khong hop le. Xin nhap lai !";
            }
        } while(num.n < 1);
        return in;
    }

    // Nạp chồng toán tử xuất <<
    friend ostream& operator<<(ostream& out, const Number& num) {
        out << "\nTong la " << num.calculate();
        return out;
    }
};

// Lớp dẫn xuất SqrtNumber
class SqrtNumber : public Number {
public:
    // Constructor
    SqrtNumber(float x = 0, int n = 0) : Number(x, n) {}

    // Kế thừa: Sử dụng constructor của lớp cơ sở

    // Đa hình: Ghi đè phương thức ảo calculate()
    float calculate() const override {
        float T = 1, S = 0;
        for(int i = 1; i <= getN(); i++) {
            T = T * getX();
            S = sqrt(T + S);
        }
        return S;
    }
};

int main() {
    SqrtNumber num;
    cin >> num;
    cout << num;
    return 0;
}
