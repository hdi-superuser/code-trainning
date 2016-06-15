// [Heading]

#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>

#define task "DHFRBUS"

using namespace std;

const long long INF = 2000000000000000000LL;

int N, M, K, s, t;

vector <int> C[100001];
vector <long long> P[100001];
long long dist[100001][6];
bool inQueue[100001][6];
queue <int> q1, q2;

void Push(int x, int y) {
   if (!inQueue[x][y]) {
      q1.push(x);
      q2.push(y);
   }
}

int main() {
   #ifndef ONLINE_JUDGE
      freopen(task".INP", "r", &_iob[0]);
      freopen(task".OUT", "w", &_iob[1]);
   #endif // ONLINE_JUDGE

   cin >> N >> M >> K >> s >> t;
   for (int i = 0; i < M; i++) {
      int u, v, w;
      cin >> u >> v >> w;
      C[u].push_back(v);
      P[u].push_back(w);

      C[v].push_back(u);
      P[v].push_back(w);
   }

   for (int x = 1; x <= N; x++)
      for (int y = 0; y <= K; y++) {
         dist[x][y] = INF;
         inQueue[x][y] = false;
      }

   q1.push(s);
   q2.push(K);
   dist[s][K] = 0;

   while (!q1.empty()) {
      int x = q1.front();  q1.pop();
      int y = q2.front();  q2.pop();
      inQueue[x][y] = false;

      for (int i = 0; i < C[x].size(); i++) {
         int xx = C[x][i];
         long long price = P[x][i];

         if (y) {
            int yy = y - 1;
            if (dist[xx][yy] > dist[x][y]) {
               dist[xx][yy] = dist[x][y];
               Push(xx, yy);
            }
         }

         int yy = y;
         if (dist[xx][yy] > dist[x][y] + price) {
            dist[xx][yy] = dist[x][y] + price;
            Push(xx, yy);
         }
      }
   }

   long long ans = INF;
   for (int kk = 0; kk <= K; kk++)
      if (dist[t][kk] < ans) ans = dist[t][kk];

   cout << ans << endl;
   cerr << ans << endl;

   return 0;
}
