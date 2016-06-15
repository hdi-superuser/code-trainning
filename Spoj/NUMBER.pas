//NUMBER
const max=10000;
type new=record
     u,v:longint;
     end;
var n,m,t,i:longint;
    u,v:longint;
    a:array[1..max] of longint;
    c:array[1..max] of new;
    count:array[1..max] of longint;
    head:array[1..max+1] of longint;
    f:array[1..max] of boolean;
    res:longint;
procedure BFS(u:longint);
          var i,v:longint;
          begin
               f[u]:=false;
               for i:=head[u] to head[u+1]-1 do
                   begin
                        v:=a[i];
                        if f[v] then BFS(v);
                   end;
          end;
begin
read(n,m,t);
for i:=1 to m do
    begin
         read(c[i].v,c[i].u);
         inc(count[c[i].u]);
    end;
f[1]:=true;
head[1]:=1;
head[n+1]:=m+1;
for i:=2 to n do
    begin
         head[i]:=head[i-1]+count[i-1];
         f[i]:=true;
    end;
for i:=1 to m do
    begin
         u:=c[i].u;
         v:=c[i].v;
         dec(count[u]);
         a[head[u]+count[u]]:=v;
    end;
BFS(t);
for i:=1 to n do
    if f[i] then
       begin
            BFS(i);
            f[i]:=true;
       end;
for i:=1 to n do
    if f[i] then inc(res);
write(res);
end.