// May 17 2016
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <map>
#include <vector>

#define task "UVa11212"
#define id first
#define ls second

using namespace std;

typedef pair< int, vector<int> > ivi;
const int MAX = 10;

vector<ivi> permu;
vector<int> x;
int A[MAX], fr[MAX], dist_t[362881], dist_s[362881];
int cnt, N;

void pre_process(bool op) {
    if (!op) return;
    #ifndef ONLINE_JUDGE
        freopen(task".INP", "r", stdin);
        freopen(task".OUT", "w", stdout);
    #endif // ONLINE_JUDGE
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
}

void next_permu(int i) {
    for (int j = 1; j <= N; j++)
        if (!fr[j]) {
            x[i] = j;
            if (i == N-1) {
                permu.push_back(ivi(++cnt, x));
                return;
            }
            fr[j] = 1;
            next_permu(i+1);
            fr[j] = 0;
        }
}

void bfs(int op) {

}

int main() {
    pre_process(true);

    cin >> N;
    for (int i = 1; i <= N; i++) cin >> A[i];
    x.assign(N, 0);
    next_permu(0);
    for (int i = 0; i < permu.size(); i++) {
        cout << permu[i].id << ") ";
        for (int j = 0; j < permu[i].ls.size(); j++) cout << permu[i].ls[j] << " ";
        cout << endl;
    }

    return 0;
}
