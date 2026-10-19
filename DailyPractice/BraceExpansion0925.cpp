#include<vector>
#include<iostream>
#include<set>
using namespace std;

class Solution {
public:
    string expr;
    int idx;
    // expr = term(, term)
    set<string> parseExpr() {
        set<string> res;
        while(true) {
            set<string> tmp = parseTerm();
            res.merge(tmp);
            if (idx < expr.size() && expr[idx] == ',') {
                idx++;
                continue;
            } else {
                break;
            }
        }
        return move(res);
    }
    // term = factor(factor...)
    set<string> parseTerm() {
        set<string> res = {""};
        while(true) {
            if (idx < expr.size() && (expr[idx] == '{' || isalpha(expr[idx]))) {
                set<string> sub = parseFactor();
                set<string> tmp;
                for (auto& left : res) {
                    for (auto& right : sub) {
                        tmp.insert(left + right);
                    }
                }
                res = move(tmp);
                continue;
            } else {
                break;
            }
        } 
        return move(res);
    }
    // factor = alpha | {expr}
    set<string> parseFactor() {
        set<string> res;
        if (isalpha(expr[idx])) {
            res.insert(string(1, expr[idx]));
            idx++;
        }else if (expr[idx] == '{') {
            idx++;
            res = parseExpr();
            idx++;
        }
        return move(res);
    }

    vector<string> braceExpansionII(string expression) {
        expr = expression;
        idx = 0;
        set<string> res = parseExpr();
        return vector<string>(res.begin(), res.end());
    }
};