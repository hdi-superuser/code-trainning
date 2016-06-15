var a,b,n1a,n1b,n2a,n2b:array[0..10000]of integer;
    n,i,n1,n2:integer;
    sa,sb:longint;
procedure sortt(l,r:integer);
 var d,c,tam:integer;
     mid:real;
  begin
    d:=l;
    c:=r;
    mid:=n1b[(l+r) div 2];
    repeat
      while n1b[d]<mid do inc(d);
      while n1b[c]>mid do dec(c);
      if d<=c then
        begin
          tam:=n1b[d];n1b[d]:=n1b[c];n1b[c]:=tam;
          tam:=n1a[d];n1a[d]:=n1a[c];n1a[c]:=tam;
          inc(d); dec(c);
        end;
    until d>c;
    if l<c then sortt(l,c);
    if d<r then sortt(d,r);
  end;
procedure sortg(l,r:integer);
 var d,c,tam:integer;
     mid:real;
  begin
    d:=l;
    c:=r;
    mid:=n2b[(l+r) div 2];
    repeat
      while n2b[d]>mid do inc(d);
      while n2b[c]<mid do dec(c);
      if d<=c then
        begin
          tam:=n2b[d];n2b[d]:=n2b[c];n2b[c]:=tam;
          tam:=n2a[d];n2a[d]:=n2a[c];n2a[c]:=tam;
          inc(d); dec(c);
        end;
    until d>c;
    if l<c then sortg(l,c);
    if d<r then sortg(d,r);
  end;
begin
  readln(n);
  for i:=1 to n do read(a[i]);
  for i:=1 to n do
    begin
      read(b[i]);
      if a[i]<b[i] then
        begin
          n1:=n1+1;
          n1a[n1]:=i;
          n1b[n1]:=a[i];
        end else
          begin
            n2:=n2+1;
            n2a[n2]:=i;
            n2b[n2]:=b[i];
          end;
    end;
  sortt(1,n1);
  sortg(1,n2);
  sa:=a[n1a[1]]; sb:=a[n1a[1]]+b[n1a[1]];
  for i:=2 to n1 do
    begin
      sa:=sa+a[n1a[i]];
      if sa>=sb then sb:=sa+b[n1a[i]] else sb:=sb+b[n1a[i]];
    end;
  for i:=1 to n2 do
    begin
      sa:=sa+a[n2a[i]];
      if sa>=sb then sb:=sa+b[n2a[i]] else sb:=sb+b[n2a[i]];
    end;
  writeln(sb);
  for i:=1 to n1 do write(n1a[i],' ');
  for i:=1 to n2 do write(n2a[i],' ');
end.