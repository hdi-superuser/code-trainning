const fi='';
      fo='';
var s,st,x: ansistring;
    i,a,n: longint;
    f: text;
procedure init;
 begin
  assign(f,fi);
  reset(f);
  readln(f,n);
  close(f);
 end;
procedure process;
 begin
  s:='';
  for i:=1 to n do
   begin
    str(i,s);
    st:=st+s;
   end;
  str(n,x);
  a:=pos(x,st);
 end;
procedure printkq;
 begin
  assign(f,fo);
  rewrite(f);
  write(f,a);
  close(f);
 end;
BEGIN
 init;
 process;
 printkq;
END.

