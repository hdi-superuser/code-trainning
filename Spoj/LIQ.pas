var l,a:array[1..1000] of longint;
d,max,n,i,j:longint;
begin
 
        readln(n);
        for i:=1 to n do
        begin
        read(a[i]);
        end;
        readln;
        for i:=1 to n do
        begin
        l[i]:=1;
        for j:=1 to i-1 do
        if (a[j]<a[i]) and (l[i]<l[j]+1) then
        l[i]:=l[j]+1;
        end;
 
        max:=l[1];
        for i:=2 to n do
        if l[i]>max then max:=l[i];
        write(max);
        readln
        end.
 