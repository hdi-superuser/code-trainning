// MATCH2
const max=200;
      oo=1000000000;
var n,i,u,v,r:longint;
    f,s:longint;
    p:array[1..max] of longint;
    fx,fy,mx,my:array[1..max] of longint;
    a:array[1..max,1..max] of longint;
    c:array[1..max,1..max] of longint;
    t:array[1..max] of longint;
function fmin(x,y:longint):longint;
         begin
              if x<y then fmin:=x else fmin:=y;
         end;
function TS(x,y:longint):longint;
         begin
              TS:=c[x,y]-fx[x]-fy[y];
         end;
procedure Find;
          var q:array[1..max] of longint;
              i:longint;
              first,last:longint;
              u,v:longint;
          begin
               for i:=1 to n do t[i]:=0;
               first:=1;last:=1;
               q[1]:=s;
               repeat
                     if first>last then
                        begin
                             exit;
                        end;
                     u:=q[first];inc(first);
                     for v:=1 to n do
                         if t[v]=0 then
                            if TS(u,v)=0 then
                               begin
                                    t[v]:=u;
                                    if my[v]=0 then
                                       begin
                                            f:=v;exit;
                                       end;
                                    inc(last);q[last]:=my[v];
                               end;
               until false;
          end;
procedure Xoay;
          var i,u,v,del:longint;
              vx,vy:set of byte;
          begin
               vx:=[s];
               vy:=[];
               for i:=1 to n do
                   if t[i]<>0 then
                      begin
                           vx:=vx+[my[i]];
                           vy:=vy+[i];
                      end;
               del:=oo;
               for u:=1 to n do
                   if u in vx then
                      for v:=1 to n do
                          if not(v in vy) then del:=fmin(del,TS(u,v));
               for i:=1 to n do
                   begin
                        if i in vx then inc(fx[i],del);
                        if i in vy then dec(fy[i],del);
                   end;
          end;
procedure IncMatch;
          var x,next:longint;
          begin
               repeat
                     if f=0 then exit;
                     x:=t[f];
                     next:=mx[x];
                     mx[x]:=f;
                     my[f]:=x;
                     f:=next;
               until false;
          end;
procedure Solve;
          var i:longint;
          begin
               for i:=1 to n do
                   if mx[i]=0 then
                      begin
                           s:=i;
                           f:=0;
                           repeat
                                 Find;
                                 if f=0 then Xoay;
                           until f<>0;
                           IncMatch;
                      end;
          end;
begin
{assign(input,'in.dat');reset(input);}
readln(n);
for u:=1 to n do
    for v:=1 to n do c[u,v]:=oo;
repeat
      readln(u,v,c[u,v]);
until eof;
for u:=1 to n do
    begin
         fx[u]:=oo;
         for v:=1 to n do fx[u]:=fmin(fx[u],c[u,v])  
    end;
for u:=1 to n do
    begin
         fy[u]:=oo;
         for v:=1 to n do fy[u]:=fmin(fy[u],c[u,v]-fx[u]); 
    end;
{-- tim cap ghep cuc dai trong so cuc tieu}
Solve;
for u:=1 to n do
    begin
         v:=mx[u];
         if c[u,v]<oo then inc(r,c[u,v]);
    end;
writeln(r);
for u:=1 to n do
    begin
         v:=mx[u];
         if c[u,v]<oo then writeln(u,' ',v);
    end;
end.
