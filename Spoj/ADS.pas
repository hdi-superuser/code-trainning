const fi='';
      fo='';

var f: text;
    i,u,v,n,m,d,last,first: longint;
    q: array[1..2000] of longint;
    t: array[1..2000] of boolean;
    c: array[1..2000,1..2000] of boolean;
procedure bfs(x: longint);
 begin
  last:=1; first:=1;
  q[1]:=x;
  t[x]:=false;
  repeat
   u:=q[first]; inc(first);
   for v:=1 to n do
    if c[u,v] and t[v] then
     begin
      inc(last);
      q[last]:=v;
      t[v]:=false;
     end;
   until first>last;
  end;
begin
 assign(f,fi); reset(f);
 readln(f,n,m);
 for i:=1 to m do
  begin
   readln(f,u,v);
   c[u,v]:=true;
   c[v,u]:=true;
  end;
 close(f);
 d:=0;
 fillchar(t,sizeof(t),true);
 for i:=1 to n do
  if t[i] then
   begin
    inc(d);
    bfs(i);
   end;
 assign(f,fo); rewrite(f);
 writeln(f,m-n+d);
 close(f);
end.