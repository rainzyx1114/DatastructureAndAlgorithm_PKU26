#include <iostream>

using namespace std;

class Fraction {

public:
    int s;
    int m;
    Fraction(int a, int b) {
        s = a;
        m = b;
    }
    friend Fraction operator+ (Fraction left, Fraction right) {
        Fraction f = Fraction(left.s * right.m + right.s * left.m, left.m * right.m);
        simple(f);
        return f;
    }
    friend ostream& operator<< (ostream& out, Fraction f) {
        out << f.s;
        if (f.m != 1) out << '/' << f.m;
        return out;
    }
private:    
    static int findGcd(int a, int b) {
        while (b != 0) {
            int tmp = b;
            b = a % b;
            a = tmp;
        }
        return a;
    }

    static void simple(Fraction& f) {
        //must have abs wrapper in case of negative input value
        int gcd = findGcd(abs(f.m), abs(f.s));
        f.m /= gcd;
        f.s /= gcd;
    }

};

int main() {
    int a1, b1, a2, b2;
    cin >> a1 >> b1 >> a2 >> b2;
    Fraction f1 = Fraction(a1, b1);
    Fraction f2 = Fraction(a2, b2);
    Fraction sum = f1 + f2;
    cout << sum << endl;
}