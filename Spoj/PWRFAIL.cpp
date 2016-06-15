#include <cstdio>
#include <cmath>

int n, m;
double dmax;
double px[1005], py[1005];
double d[1005][1005];
bool seen[1005];
double l[1005];

main() {
    int i, j, k, x, y;

    //freopen ("pwrfail.in", "r", stdin );
    //freopen ("pwrfail.out", "w", stdout );

    scanf ("%d %d", &n, &m);
    scanf ("%lf", &dmax );
    for (i = 0; i < n; i++ )
        scanf (" %lf %lf", &px[i], &py[i] );
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            d[i][j] = hypot (px[i]-px[j], py[i]-py[j]);
    for (i = 0; i < m; i++ ) {
        scanf (" %d %d", &x, &y );
        x--, y--;
        d[x][y] = d[y][x] = 0;
    }

    for (i = 1; i < n; i++ )
        l[i] = -1;
    while(!seen[n-1]) {
        x = -1;
        for (i = 0; i < n; i++ )
            if (!seen[i] && l[i] >= 0 && (x < 0 || l[i] < l[x]) )
                x = i;
        if (x < 0 ) break;
        seen[x] = true;
        for (i = 0; i < n; i++ )
            if (!seen[i] && d[x][i] <= dmax && (l[i] < 0 ||
                                l[x]+d[x][i] < l[i]) )
                l[i] = l[x]+d[x][i];
    }

    if (!seen[n-1])
        printf ("-1\n" );
    else printf ("%d\n", (int)(l[n-1]*1000) );
}
