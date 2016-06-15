// [Heading]

#include <iostream>
#include <cstdio>
#include <algorithm>

#define task "spoj"

using namespace std;

const int maxN = 20001;
struct entry {
   short h, w;

   bool operator < (const entry &o) const {
      if (h != o.h) return h > o.h;
      return w < o.w;
   }
};

entry d[maxN];

bool cmp_w(entry a, entry b) {
   return a.w < b.w;
}

int main() {
   #ifndef ONLINE_JUDGE
      freopen(task".txt", "r", &_iob[0]);
   #endif // ONLINE_JUDGE

   int Case;
   cin >> Case;

   while (Case--) {
      int N;
      cin >> N;

      for (int i = 0; i < N; i++) cin >> d[i].w >> d[i].h;
      sort(d, d+N);

      int res = N;
      entry* last = d;

      for (int j = 0; j < N; j++) {
         entry *it = upper_bound(d, last, d[j], cmp_w);
         if (it != last) {
            res--;
            it -> w = d[j].w;
         } else *(last++) = d[j];
      }

      cout << res << endl;
   }

   return 0;
}
