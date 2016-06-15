USES    math;
CONST   maxn = 100000;
 
VAR     t,i,j,m : longint;
        a,f : array[0..maxn] of int64;
        n : array[1..maxn] of longint;
 
BEGIN
        readln(t);
        m := 0;
        for i := 1 to t do begin
                readln(n[i]);
                m := max(n[i],m);
        end;
        a[0] := 0;
        a[1] := 1;
        for i := 1 to m div 2 do begin
                a[2*i] := a[i];
                a[2*i+1] := a[i] + a[i+1];
        end;
        f[1] := 1;
        for i := 2 to m do
                f[i] := max(f[i-1],a[i]);
        for i := 1 to t do
                writeln(f[n[i]]);
 END.