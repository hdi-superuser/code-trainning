const fi='';
      fo='';
var f:text;
    a,b:longint;
begin
  assign(f,fi);
  reset(f);
  read(f,a,b);
  close(f);
  assign(f,fo);
  rewrite(f);
  write(f,a+b);
  close(f);
end.