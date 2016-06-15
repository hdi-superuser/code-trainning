uses    math;
const   maxn = 2154434;
        fi   = '';
        fo   = '';

var     a, b, c: array[1..1000] of qword;
        i, j, na, nb, nc: longint;
        x: qword;
        dp: array[0..1001, 0..1001] of longint;
        p: array[1..maxn] of boolean;

function check(x: qword): boolean;
 var    k: qword;
 begin
        k := trunc(sqrt(x));
        if (sqr(k) = x) then exit(true);

        k := round(exp(ln(x)/3));
        if k*k*k <> x then exit(false);
        if not p[k] then exit(false);

        exit(true);
 end;

BEGIN
        assign(input, fi);        reset(input);
        assign(output, fo);       rewrite(output);

        fillchar(p, sizeof(p), true);
        p[1]:=false;
        i:=2;
        while i <= trunc(sqrt(maxn)) do
          begin
                while p[i]=false do inc(i);
                for j:=2 to maxn div i do p[i*j]:=false;
                inc(i);
          end;

        while (not(seekeoln(input))) do
         begin
                read(x);
                if (check(x)) then
                 begin
                        inc(na);
                        a[na] := x;
                 end;
         end;
        readln;
        while (not(seekeoln())) do
         begin
                read(x);
                if (check(x)) then
                 begin
                        inc(nb);
                        b[nb] := x;
                 end;
         end;

        for i:=1 to na do
         for j:=1 to nb do
                if (a[i] = b[j]) then dp[i][j] := dp[i-1][j-1] + 1
                else dp[i][j] := max(dp[i-1][j], dp[i][j-1]);

        writeln(dp[na][nb]);

        close(input);           close(output);
END.

