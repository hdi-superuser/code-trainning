type  matrix=array[1..3,1..3] of int64;

const fi='';
      fo='';

var   f:text;
      a,b:matrix;
      n:int64;
      m:int64;
procedure input;
  begin
    assign(f,fi);
    reset(f);
    readln(f,n,m);
    close(f);
  end;

function nhan(a,b:matrix):matrix;
var c:matrix;
    k,u,v:longint;
  begin
    for u:=1 to 3 do
      for v:=1 to 3 do
        begin
          c[u,v]:=0;
          for k:=1 to 3 do
            c[u,v]:=(c[u,v]+a[u,k]*b[k,v])mod m;
        end;
    exit(c);
  end;

function luythua(a:matrix;k:int64):matrix;
var b:matrix;
  begin
    if k=1 then exit(a)
    else
      begin
        b:=luythua(a,k div 2);
        b:=nhan(b,b);
        if k mod 2 =1 then b:=nhan(b,a);
      end;
    exit(b);
  end;

procedure solve;
  begin
    a[1,1]:=0; a[1,2]:=1; a[1,3]:=0;
    a[2,1]:=0; a[2,2]:=0; a[2,3]:=1;
    a[3,1]:=1; a[3,2]:=1; a[3,3]:=1;
    b:=luythua(a,n-1);
  end;

procedure output;
  begin
    assign(f,fo);
    rewrite(f);
    case n of
      1: writeln(f,1);
      2: writeln(f,2 mod m);
      3: writeln(f,4 mod m);
    else
      begin
        solve;
        writeln(f,(b[1,1]+b[1,2]*2+b[1,3]*4)mod m);
      end;
    end;
    close(f);
  end;

BEGIN
  input;
  output;
END.
