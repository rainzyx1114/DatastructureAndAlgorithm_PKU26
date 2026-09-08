#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class model {
public:
    string name;
    char level;
    double num;

    model() = default;

    model(string fullName) {
        int i = 0;
        while (fullName[i] != '-') {
            name += fullName[i];
            i += 1;
        }
        level = fullName[fullName.size() - 1];
        string lef = fullName.substr(i + 1, fullName.size() - i - 2);
        num = stod(lef);
    }

    bool operator< (model m) {
        if (name != m.name) {
            return name < m.name;
        } else {
            if (level != m.level) {
                return level == 'M';
            } else {
                return num < m.num;
            }
        }
    }

};

int main() {
    int n;
    cin >> n;
    vector<model> models(n);
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        model m = model(s);
        models[i] = m;
    }
    sort(models.begin(), models.end());
    string lastName = "";
    for (model m : models) {
        if (m.name != lastName) {
            if (!lastName.empty()) cout << endl;
            lastName = m.name;
            cout << m.name << ": ";
        } else {
            cout << ", ";
        }
        cout << m.num << m.level;
    }
}