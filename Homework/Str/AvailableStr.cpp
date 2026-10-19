#include <iostream>
#include <unordered_set>
#define MAXN 60
using namespace std;

string hw[MAXN];

string lower(const string& s) {
    string res(s);
    for (char& c: res) {
        if (c >= 'A' && c <= 'Z') {
            c = c - 'A' + 'a';
        }
    }
    return res;
}

bool match(const string& s, const string& str) {
    int index = 0;
    for (int i = 0; i < s.size(); ++i) {
        if (str[index] != '[') {
            if (s[i] != str[index]) {
                return false;
            }
        } else {
            unordered_set<char> tmp;
            index++;
            while (str[index] != ']') {
                tmp.insert(str[index]);
                index++;
            }
            if (tmp.find(s[i]) == tmp.end()) {
                return false;
            }
        }
        index++;
    }
    return index == str.size();
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> hw[i];
    }
    string str;
    cin >> str;
    str = lower(str);
    for (int i = 0; i < n; ++i) {
        if (match(lower(hw[i]), str)) {
            cout << i + 1 << " " << hw[i] << endl;
        }
    }
}