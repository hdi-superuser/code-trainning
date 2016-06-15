const cmaxn=100010;
var n,dd,i,j,jj:longint;
np:array[0..600] of longint;
l:array[0..cmaxn] of int64;
BEGIN
readln(n);
if n = 0 then writeln(0)
else
begin
np[0]:=0;
dd:=1;
i:=0;
while np[i]<=n do
begin
i:=i+1;
jj:=(i+1) div 2 * dd;
dd:=-dd;
np[i]:=jj*(3*jj-1) div 2;
end;
l[0]:=1;
l[1]:=1;
for i:=2 to n do
begin
j:=1;
while (np[j]<=i) do
begin
case j mod 4 of
0,3:
l[i]:=l[i]+1000000000-l[i-np[j]];
1,2:
l[i]:=l[i]+l[i-np[j]];
end;
j:=j+1;
end;
l[i]:=l[i] mod 1000000000;
end;
writeln(l[n]);
end;
END.