#include <iostream>
using namespace std;

class CFraction {
private:

    int num;  
    int den; 

public:
    // Constructor
    CFraction(int n = 0, int d = 1) : num(n), den(d) {}

    // Overload operator+
    friend CFraction operator + (const CFraction& left_fraction, const CFraction& right_fraction)  {
        return CFraction(left_fraction.num * right_fraction.den + left_fraction.den * right_fraction.num, left_fraction.den * right_fraction.den);
    }

    // Overload operator-
    friend CFraction operator - (const CFraction& left_fraction, const CFraction& right_fraction)  {
        return CFraction(left_fraction.num * right_fraction.den - left_fraction.den * right_fraction.num, left_fraction.den * right_fraction.den);
    }

    // Overload operator*
    friend CFraction operator * (const CFraction& left_fraction, const CFraction& right_fraction)  {
        return CFraction(left_fraction.num * right_fraction.num, left_fraction.den * right_fraction.den);
    }

    // Overload operator/
    friend CFraction operator / (const CFraction& left_fraction, const CFraction& right_fraction)  {
        return CFraction(left_fraction.num * right_fraction.den, left_fraction.den * right_fraction.num);
    }

    // For printing the fraction
    void print()  {
        if(num % den == 0)
        {
            std::cout <<num/den<<std::endl;
        }else{
        std::cout << num << "/" << den << std::endl;
        }
    }

    void simplify() {
        int gcd = 1;
        int min = num < den ? num : den;
        for (int i = 2; i <= min; ++i) {
            if (num % i == 0 && den % i == 0) {
                gcd = i;
            }
        }
        num /= gcd;
        den /= gcd;
    }
};


int main() {

    int a, b, c, d;
    int choice = 0;
    CFraction result;
    do
    {
        cout<<"Nhap phan so thu nhat \n";
        cout<<"Tu so: ";
        cin>>a;
        cout<<"mau so: ";
        cin>>b;

        cout<<"Nhap phan so thu hai \n";
        cout<<"Tu so: ";
        cin>>c;
        cout<<"mau so: ";
        cin>>d;

    } while (b==0 && c==0);

    CFraction f1(a, b);
    CFraction f2(c, d);

    enum operation {
        
            add = 1,
            minus,
            div,
            mul
    };

    do{
    cout<<"Thuc hien phep tinh: (1): Phep cong  (2): Phep tru  (3): Phep chia  (4): Phep nhan\n ";
    cout<<"Your choice: ";
    cin>>choice;

    switch(choice)
    {
        case add:
            result = f1+f2;
            result.simplify();
            result.print();
            break;
        case minus:
            result = f1-f2;
            result.simplify();
            result.print();
            break;   
        case div:
            result = f1/f2;
            result.simplify();
            result.print();
            break;
        case mul:
            result = f1*f2;
            result.simplify();
            result.print();
            break;
        default:
            cout<<"Vui long nhap lai";
    }
    } while (choice > 4 || choice <1);
    return 0;
}

