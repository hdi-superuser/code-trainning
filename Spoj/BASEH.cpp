#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>

using namespace std;

const int maxN = 10001;

int main() {
        //freopen("debug.txt", "r", stdin);

        int K;
        cin >> K;

        string s;

        while (K) {
                int k = (K % 2);
                K /= 2;
                s = (char)(k + 48) + s;
        }

        cout << s;

        return 0;
}
