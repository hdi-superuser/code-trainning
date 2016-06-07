#include <iostream>
#include <cstdio>

#define print(key) { cout << key; return 0; }

using namespace std;

const int MAX = 1000001;

int Fa[MAX], Fb[MAX];

int main() {
    #ifndef ONLINE_JUDGE
        freopen("in.txt", "r", stdin);
        freopen("out.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    int N;
    cin >> N;
    for (int i = 1; i <= N; i++) {
        int x, y;
        cin >> x >> y;
        if (Fa[x] != Fb[y]) print("NO");
        Fa[x] = Fb[y] = i;
    }
    print("YES");

    return 0;
}
