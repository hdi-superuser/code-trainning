#include <bits/stdc++.h>

using namespace std;

const string mod[7] = {"3241", "1324", "1234", "2341", "1243", "1342", "2153"};

int digit[10];

int main() {
    freopen("in.txt", "r", stdin);
    int x;
    scanf("%d\n", &x);
    while (x--) {
        string str, res = "";
        cin >> str;
        memset(digit, 0, sizeof digit);
        for (int i = 0; i < str.size(); i++) digit[str[i] - 48]++;
            for (int i = 1; i <= 4; i++) digit[i]--;
                int remain = 0;
                for (int i = 1; i <= 9; i++)
                    while (digit[i])
                        res += (char)(i+48),
                        remain = (remain*10 + i) % 7,
                        digit[i]--;

                remain = (remain*10000) % 7;
                remain = (7 - remain) % 7;
                res += mod[remain];
                while (digit[0])
                    res += '0',
                    digit[0]--;

                if (str.compare(res)) {
                    cout << res << endl;
                    continue;
                }

                remain = 0;
                res = "";
                for (int i = 9; i >= 1; i--)
                    while (digit[i])
                        res += (char)(i+48),
                        remain = (remain*10 + i) % 7,
                        digit[i]--;

                remain = (remain*10000) % 7;
                remain = (7 - remain) % 7;
                res += mod[remain];

                while (digit[0])
                    res += '0',
                    digit[0]--;
                    cout << res << endl;
                }
        return 0;
}

