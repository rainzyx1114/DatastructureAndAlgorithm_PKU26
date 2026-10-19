#include <iostream>
#include <cstring>
#define MAXN 1000005

using namespace std;

int nex[MAXN];
void generate_next_array(const string& s) {
    nex[0] = -1;
    nex[1] = 0;
    int j = 0;
    int i = 2;
    while (i <= s.size()) {
        if (s[i-1] == s[j]) {
            nex[i++] = ++j;
        } else if (j > 0) {
            j = nex[j];
        } else {
            nex[i++] = 0;
        }
    }
}
char str[MAXN];

int main() {
    while (scanf("%s", str) == 1 && strcmp(str, ".") != 0) {
        string s(str);
        generate_next_array(s);
        int loopLen = s.size() - nex[s.size()];
        if (s.size() % loopLen == 0) {
            printf("%d\n", s.size() / loopLen);
        } else {
            printf("1\n");
        }
    }
}