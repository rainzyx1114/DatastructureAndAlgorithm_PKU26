#include <iostream>
#include <map>

using namespace std;

class cmp {
    public:
    bool operator() (const int& x, const int& y) const{
        return x > y;
    }
};
map<int, int, cmp> poly;

int main() {
    int n;
    cin >> n;
    while(n--) {
        poly.clear();
        int a;
        int p;
        while(cin >> a >> p && p >= 0) {
            poly[p] += a;
        }
        while(cin >> a >> p && p >= 0) {
            poly[p] += a;
        }
        for (auto it = poly.begin(); it != poly.end(); it++) {
            if (it->second == 0) {
                continue;
            }
            cout << "[ " << it->second << ' ' << it->first << " ] ";
        }
        cout << endl;
    }
}