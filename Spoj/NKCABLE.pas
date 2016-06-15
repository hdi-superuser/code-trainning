uses math;
var i,n: longint;
    f,a: array[1..25000] of longint;
begin
 readln(n);
 for i:=1 to n do readln(a[i]);
 f[1]:=0;
 f[2]:=a[1];
 f[3]:=a[1]+a[2];
 for i:=4 to n do f[i]:=min(f[i-1]+a[i-1],f[i-2]+a[i-1]);
 writeln(f[n]);
end. 