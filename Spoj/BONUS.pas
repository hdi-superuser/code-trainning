const fi='';
      fo='';
var i,j,n,k: longint;
    a:array[1..1000,1..1000] of longint;
    l: array[0..1000,0..1000] of longint;
    d,maxl: longint;
    f: text;
procedure init;
 begin
  fillchar(l,sizeof(l),0);
  assign(f,fi);
  reset(f);
  readln(f,n,k);
  for i:=1 to n do
    for j:=1 to n do
     begin
      read(f,a[i,j]);
      l[i,j]:=l[i-1,j]+l[i,j-1]-l[i-1,j-1]+a[i,j];
     end;
    readln(f);
  close(f);
 end;
procedure process;
 begin
  d:=0; maxl:=0;
  for i:=k to n do
   for j:=k to n do
    begin
     d:=l[i,j]-l[i-k,j]-l[i,j-k]+l[i-k,j-k];
     if d>maxl then maxl:=d;
    end;
 end;
procedure printkq;
 begin
  assign(f,fo);
  rewrite(f);
  writeln(f,maxl);
  close(f);
 end;
BEGIN
 init;
 process;
 printkq;
END.

