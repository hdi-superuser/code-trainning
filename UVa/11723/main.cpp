#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <cctype>
#include <stack>
#include <queue>
#include <list>
#include <vector>
#include <map>
#include <sstream>
#include <cmath>
#include <bitset>
#include <utility>
#include <set>
#define pi acos(-1.0)
#define N 1000000
using namespace std;


int main ()
{
    int n, r;
    int cases = 0;

    while ( scanf ("%d %d", &r, &n) ) {
        if ( r == 0 && n == 0 ) break;

        bool printed = false;

        for ( int i = 1; i <= 27; i++ ) {
            if ( n * i >= r ) {
                printf ("Case %d: %d\n", ++cases, i - 1);
                printed = true;
                break;
            }
        }

        if ( !printed )
            printf ("Case %d: impossible\n", ++cases);
    }

    return 0;
}
