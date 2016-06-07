#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>

using namespace std;

int N;
bool seen[(int) 1e8 + 1];

int main() {
    freopen("in.txt", "r", stdin) && freopen("out.txt", "w", stdout);
    cin >> N;
    vector<int> ans;    queue<int> q;
    ans.push_back(0);   q.push(N);

    while (!q.empty()) {
        int u = q.front();  q.pop();
        for (int i = 1; i <= trunc(sqrt(u)); i++) {
            if (u % i == 0) {
                int x = i, y = u / i;
                if (x > y) swap(x, y);
                if ((x-1)*(y+1) == 0 || seen[(x-1)*(y+1)]) continue;
                q.push((x-1)*(y+1));    seen[(x-1)*(y+1)] = true;   ans.push_back((x-1)*(y+1));
            }
        }
    }

    sort(ans.begin(), ans.end());
    vector<int>::iterator it;
    it = unique(ans.begin(), ans.end());
    ans.resize(distance(ans.begin(), it));
    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); i++) cout << ans[i] << " ";

    return 0;
}
