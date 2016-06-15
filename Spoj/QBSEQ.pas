const fi='';
      fo='';
var
 a:array[1..1000] of longint;
 l: array[0..1000,0..50] of longint;
 n,k: longint;
procedure init;
 var f: text;
     i: longint;
 begin
  assign(f,fi);
  reset(f);
  readln(f,n,k);
  for i:=1 to n do read(f,a[i]);
  close(f);
 end;
function sub(x,y: longint): longint;
 var t: longint;
 begin
  t:=(x-y) mod k;
  if t>=0 then sub:=t
  else sub:=t+k;
 end;
procedure process;
 var i,t: longint;
 begin
  l[0,0]:=0;
  for t:=1 to k-1 do l[0,t]:=50;
  for i:=1 to n do
   for t:=0 to k-1 do
    if l[i-1,t]<l[i-1,sub(t,a[i])]+1 then
     l[i,t]:=l[i-1,t]
    else
     l[i,t]:=l[i-1,sub(t,a[i])]+1;
 end;
procedure printkq;
 var i,sum,t: longint;
     f: text;
 begin
  sum:=0;
  for i:=1 to n do sum:=sum+a[i];
  assign(f,fo);
  rewrite(f);
  write(f,n-l[n,sum mod k]);
  close(f);
 end;
BEGIN
 init;
 process;
 printkq;
END.
