const maxN = trunc(1e5+1);
      maxM = trunc(1e6+1);
var parent,old: array[1..maxN] of longint;
    d: array[1..maxM] of record u,v,w,w2: longint end;
    m,n,q,test,t,k,u,v,c: longint;
 
function root(u: longint): longint;
begin
    while parent[u]>0 do u:=parent[u];
    exit(u);
end;
 
procedure union(u,v: longint);
var s: longint;
begin
    s:=parent[u]+parent[v];
    if parent[u]>parent[v] then
      begin
        parent[u]:=v;
        parent[v]:=s;
      end else
      begin
        parent[v]:=u;
        parent[u]:=s;
      end;
end;
 
procedure solve;
var i,j,r1,r2,t: longint;
begin
    for i:=1 to m do
     if d[i].w<d[k].w then
      begin
        r1:=root(d[i].u); r2:=root(d[i].v);
        if r1<>r2 then Union(r1,r2);
      end;
    if root(d[k].u)=root(d[k].v) then Writeln('YES') else Writeln('NO');
    for i:=1 to v do
      begin
        j:=old[i];
        t:=d[j].w; d[j].w:=d[j].w2; d[j].w2:=t;
      end;
end;
 
procedure enter_and_solve;
var i,j,t: longint;
begin
    readln(n,m,q);
    for i:=1 to m do with d[i] do readln(u,v,w);
    for i:=1 to q do
      begin
         fillchar(parent,sizeof(parent),255);
         read(k,v);
         for j:=1 to v do
           begin
             read(u,c);
             d[u].w2:=c;
             t:=d[u].w2; d[u].w2:=d[u].w; d[u].w:=t;
             old[j]:=u;
           end;
         solve;
      end;
end;
 
begin
    assign(input,''); reset(input);
    readln(Test);
    for t:=1 to test do enter_and_solve;
end.
