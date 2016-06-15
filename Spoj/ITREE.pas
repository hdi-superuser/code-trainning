uses math;
const fi='';
      fo='';
      mn=100000;
type tuan=record
      v,w:longint;
      link:longint;
     end;
var f:text;
    a:array[1..mn] of real;
    adj:array[1..mn] of tuan;
    e,n:longint;
    head:array[1..mn] of longint;
    t:longint;
procedure dfs(u:longint);
 var v,i:longint;
     tmp:real;
  begin
    i:=head[u];
    while i>0 do
     begin
       v:=adj[i].v;
       dfs(v);
       tmp:=adj[i].w;
       if head[v]>0 then tmp:=min(tmp,a[v]);
       a[u]:=a[u]+tmp;
       i:=adj[i].link;
     end;
  end;
procedure init;
 begin
  e:=0;
  fillchar(head,sizeof(head),0);
  fillchar(a,sizeof(a),0);
//  fillchar(w,sizeof(w),0);
 end;
procedure them(u,v,c:longint);
 begin
  inc(E);
  adj[e].v:=v;
  adj[e].link:=head[u];
  head[u]:=e;
  adj[e].w:=c;
 end;
procedure input;
  var i,j,x,y,r:longint;
  begin
   assign(F,fi);
   reset(f);
   readln(f,t);
   for j:=1 to t do
    begin
     init;
     readln(f,n);
     for i:=2 to n do
      begin
        readln(f,x,r);
        them(x,i,r);
      end;
     dfs(1);
     writeln(a[1]:0:2);
   end;
  close(f);
 end;
begin
 input;
end.
