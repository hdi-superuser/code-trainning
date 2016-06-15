/***@authr Huynh Duy Idol
	@lang C++
   */

#include <iostream> // this is a line comment
#include <stdio.h>
#include <string.h>

#define task "CWAY"
#define maxN 1001
#define BASE 1000000007
#define DBG  0
#define MAXN  110
#define RADIX  1000000000
#define INF  1000000001

struct bigInt{
   int l, d[500];
   bigInt(int x = 0){
      memset(d, 0, sizeof d);
      l = 1; d[0] = x;
   }

   void add(int x){
      d[0] += x;
      for (int i = 0; i < l; i++) d[i+1] += d[i]/RADIX, d[i] %= RADIX;
      if(d[l]) l++;
   }

   void mul(int x){
      long long t = 0;
      for (int i = 0; i < l; i++) {
         t += (long long)(d[i])*x;
         d[i] = int(t % RADIX);
         t /= RADIX;
      }
      if(t) d[l++] = t;
   }

   void zprint(int x){
      char s[10];
      sprintf(s, "%d", x);
      for(int i = strlen(s); i < 9; i++) putchar('0');
      printf("%s", s);
   }

   void print(){
      printf("%d", d[l-1]);
      for(int i = l - 2; i >= 0; i--) zprint(d[i]);
   }

   void println(){
      printf("%d", d[l-1]);
      for (int i = l-2; i >= 0; i--) zprint(d[i]);
      putchar('\n');
   }
};

int main() {
	#ifndef ONLINE_JUDGE
        freopen(task".INP", "r", stdin);
        freopen(task".OUT", "w", stdout);
    #endif // ONLINE_JUDGE
    int n;
    scanf("%d", &n);
    bigInt res(1);
    for(int i = 1; i < n-1; i++) {
        res.mul(i);
        res.add(1);
    }
    res.println();
    return 0;
}

