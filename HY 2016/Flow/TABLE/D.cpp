#include <bits/stdc++.h>

using namespace std;

ifstream f1("table.out");
ifstream f2("D.out");
ofstream f3("test.txt");

int main() {
    string s1, s2;
    int cnt = 0;
    while (f1 >> s1) {
        f2 >> s2;
        cnt++;
        if (s1 != s2) f3 << "Wrong answer on " << cnt << endl;
    }
    return 0;
}
