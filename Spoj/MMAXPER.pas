const
  fi='';
  fo='';
var
  f:text;
  i,j,n:longint;
  a,b:array[1..1001]of longint;
  l:array[0..1001,0..3]of longint;

begin
  assign(f,fi);
  reset(F);
  readln(f,n);
  for i:=1 to n do readln(f,a[i],b[i]);
  close(f);

  l[1,1]:=b[1]; l[1,2]:=a[1];
  for i:=2 to n do
    begin
      if (l[i-1,1]+abs(a[i]-a[i-1])) > (l[i-1,2]+abs(a[i]-b[i-1])) then
        l[i,1]:=l[i-1,1]+abs(a[i]-a[i-1])+b[i]
      else l[i,1]:=l[i-1,2]+abs(a[i]-b[i-1])+b[i];
      if (l[i-1,1]+abs(b[i]-a[i-1])) > (l[i-1,2]+abs(b[i]-b[i-1])) then
        l[i,2]:=l[i-1,1]+abs(b[i]-a[i-1])+a[i]
      else l[i,2]:=l[i-1,2]+abs(b[i]-b[i-1])+a[i];
    end;

  assign(f,fo);
  rewrite(f);
  if l[n,1]>l[n,2] then writeln(f,l[n,1])
  else writeln(f,l[n,2]);
  close(f);
end.
