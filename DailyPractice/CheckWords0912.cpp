#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

unordered_set<string> dict;
vector<string> words;

int main() {
    string s;
    while (true) {
        cin >> s;
        if (s == "#") break;
        dict.insert(s);
        words.push_back(s);
    }
    while (true) {
        cin >> s;
        if (s == "#") break;
        if (dict.find(s) != dict.end()) {
            cout << s << " is correct" << endl;
            continue;
        }
        cout << s << ":";
        unordered_set<string> similar;
        int len = s.size();
        for (int i = 0; i < len; i++) {
            string deleteStr = s.substr(0, i);
            if (i != len - 1) deleteStr.append(s.substr(i + 1));
            if (dict.find(deleteStr) != dict.end()) similar.insert(deleteStr);
        }
        for (int i = 0; i < len; i++) {
            string replaceStr = s;
            for (int j = 0; j < 26; j++) {
                replaceStr[i] = (char)('a' + j);
                if (dict.find(replaceStr) != dict.end()) similar.insert(replaceStr);
            }
        }
        for (int i = 0; i <= len; i++) {
            for (int j = 0; j < 26; j++) {
                string insertStr = s;
                if (i == len) {
                    insertStr.push_back((char)('a' + j));
                } else {
                    insertStr.insert(insertStr.begin() + i, (char)('a' + j));
                }
                if (dict.find(insertStr) != dict.end()) similar.insert(insertStr);
            }
        }
        for (string str: words) {
            if (similar.find(str) == similar.end()) continue;
            cout << " " << str;
        }
        cout << endl;
    }
}