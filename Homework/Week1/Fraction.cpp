#include <iostream>

using namespace std;

class Fraction {
public:
    int s;
    int m;
    Fraction (int a, int b) {
        s = a;
        m = b;
    }
    friend Fraction operator+ (Fraction lef, Fraction rig) {
        Fraction sum = Fraction(lef.s * rig.m + rig.s * lef.m, lef.m * rig.m);
        simple(sum);
        return sum;
    }
    friend ostream& operator<< (ostream& out, Fraction f) {
        out << f.s;
        if (f.m != 1) out << '/' << f.m;
        return out;
    }
private:
    static int gcd (int x, int y) {
        while (y != 0) {
            int tmp = y;
            y = x % y;
            x = tmp;
        }
        return x;
    }
    static void simple(Fraction& f) {
        int g = gcd(abs(f.s), abs(f.m));
        f.s /= g;
        f.m /= g;
    }
};

int main() {
    int a1, b1, a2, b2;
    cin >> a1 >> b1 >> a2 >> b2;
    Fraction f1 = Fraction(a1, b1);
    Fraction f2 = Fraction(a2, b2);
    cout << (f1 + f2) << endl;
}