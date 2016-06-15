const fi='';
      fo='';
      maxn=1000;
      maxm=1000;
type  point=record
        x,y:int64;
      end;
      poly=record
        p:array[1..maxn+1] of point;
        n:longint;
        s:int64;
        c:longint;
      end;
var   f:text;
      d:array[0..maxm] of poly;
      dem:array[0..maxm] of longint;
      kq:int64;
      m,k,i,j,max:longint;

procedure input;
  begin
    assign(f,fi);
    reset(f);
    readln(f,m,k);
    for i:=1 to m do
      begin
        read(f,d[i].n);
        read(f,d[i].c);
        for j:=1 to d[i].n do read(f,d[i].p[j].x,d[i].p[j].y);
        d[i].p[d[i].n+1].x:=d[i].p[1].x;
        d[i].p[d[i].n+1].y:=d[i].p[1].y;
        readln(f);
      end;
    close(f);
  end;

function tinhS(d:poly):int64;
var s:int64;
    var i:longint;
  begin
    s:=0;
    for i:=1 to d.n do
      s:=s+(d.p[i+1].x-d.p[i].x)*(d.p[i+1].y+d.p[i].y);
    exit(abs(s));
  end;

procedure sort(l,r: longint);
var i,j: longint;
    x:int64;
    y:poly;
  begin
    i:=l;
    j:=r;
    x:=d[(l+r) div 2].s;
    repeat
      while d[i].s<x do inc(i);
      while x<d[j].s do dec(j);
      if not(i>j) then
        begin
           y:=d[i];
           d[i]:=d[j];
           d[j]:=y;
           inc(i);
           j:=j-1;
        end;
    until i>j;
    if l<j then sort(l,j);
    if i<r then sort(i,r);
  end;

procedure solve;
  begin
    for i:=1 to m do
      d[i].s:=tinhS(d[i]);
    sort(1,m);
    for i:=1 to m do
      begin
        fillchar(dem,sizeof(dem),0);
        max:=0;
        for j:=i to m do
          begin
            inc(dem[d[j].c]);
            if max<dem[d[j].c] then max:=dem[d[j].c];
            if j-i+1-max<=k then
              if d[j].s-d[i-1].s>kq then kq:=d[j].s-d[i-1].s;
          end;
      end;
  end;

procedure output;
  begin
    assign(f,fo);
    rewrite(f);
    write(f,kq div 2);
    if kq mod 2 = 0 then write(f,'.',0)
    else write(f,'.',5);
    close(f);
  end;

begin
  input;
  solve;
  output;
end.
