#include <iostream>
#include <stack>
#include <map>
#include <cstring>
using namespace std;

struct mat_ {
    int r, c; ///行, 列
};

map <char, mat_> mat;

char c;
string s;
int n;
int main () {
    cin >> n;
    for (int i = 0;i < n; ++ i) {
        cin >> c;
        cin >> mat[c].r >> mat[c].c;
    }

    while (cin >> s) {
        stack <mat_> sta;
        int ans = 0;
        bool is_bk = 0;
        for (int i = 0;i < s.size (); ++ i) {
            if (s[i] == '(') continue;
            if (s[i] == ')') {
                mat_ sed = sta.top(); sta.pop();
                mat_ fst = sta.top(); sta.pop(); ///这里千万别搞反
                if (fst.c != sed.r) {
                    cout << "error" << endl;
                    is_bk = 1;
                    break;
                }
                ans += fst.r * fst.c * sed.c;
                fst.c = sed.c;
                sta.push (fst);
            }
            else {
                sta.push(mat[s[i]]);
            }
        }
        if (!is_bk) {
            cout << ans <<endl;
        }
    }
    return 0;
}