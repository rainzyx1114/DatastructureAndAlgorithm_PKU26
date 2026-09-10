#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

unordered_map<string, int> nameToIndex;
unordered_map<int, string> indexToName;


int main() {

    int p;
    cin >> p;
    vector<vector<int>> dis(p, vector<int>(p, 100000));
    vector<vector<int>> firstNodeOnPath(p, vector<int>(p));
    for (int i = 0; i < p; i++) {
        string name;
        cin >> name;
        nameToIndex[name] = i;
        indexToName[i] = name;
        dis[i][i] = 0;
        firstNodeOnPath[i][i] = -1;
    }
    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        string a, b;
        int w;
        cin >> a >> b >> w;
        int aIndex = nameToIndex[a];
        int bIndex = nameToIndex[b];
        dis[aIndex][bIndex] = w;
        dis[bIndex][aIndex] = w;
        firstNodeOnPath[aIndex][bIndex] = bIndex;
        firstNodeOnPath[bIndex][aIndex] = aIndex;
    }

    for (int k = 0; k < p; k++) {
        for (int i = 0; i < p; i++) {
            for (int j = 0; j < p; j++) {
                if (dis[i][k] + dis[k][j] < dis[i][j]) {
                    dis[i][j] = dis[i][k] + dis[k][j];
                    firstNodeOnPath[i][j] = firstNodeOnPath[i][k];
                }
            }
        }
    }

    int r;
    cin >> r;
    while (r--) {
        string src, des;
        cin >> src >> des;
        int srcIndex = nameToIndex[src];
        int desIndex = nameToIndex[des];
        int index = srcIndex;
        while (true) {
            cout << indexToName[index];
            int tmp = index;
            index = firstNodeOnPath[index][desIndex];
            if (index == -1) break;
            cout << "->(" << dis[tmp][index] << ")->";
        }
        cout << endl;
    }
}
