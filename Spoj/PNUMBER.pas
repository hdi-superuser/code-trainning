const fi='';
      fo='';
var f: text;
    x,y: longint;
procedure init;
 begin
  assign(f,fi);
  reset(f);
  readln(f,x,y);
  close(f);
 end;
function pnum(k: longint): boolean;
 var i: longint;
 begin
  if k=1 then exit(false);
  pnum:=true;
  for i:=2 to trunc(sqrt(k)) do
   if (k mod i)=0 then exit(false);
 end;
procedure process;
 var i: longint;
 begin
  for i:=x to y do
   if pnum(i) then writeln(f,i);
 end;
BEGIN
 init;
 assign(f,fo);
 rewrite(f);
 process;
 close(f);
END.
