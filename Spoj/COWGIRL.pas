// COWGIRL
type ma=array[1..30,0..31] of longint;
var m,n,i,j,c,b,t,it:longint;
    f:ma;
function Ok(x,y:longint):boolean;
         var t,bx,by,i,cb:longint;
         begin
              t:=-1;
              for i:=1 to b do
                  begin
                       cb:=x mod 2;
                       if (cb=y mod 2)and(cb=t) then
                          begin
                               Ok:=false;exit;
                          end;
                       if cb=y mod 2 then t:=cb
                       else t:=-1;
                       x:=x shr 1;y:=y shr 1;
                  end;
              Ok:=true;
         end;
procedure So(f:ma);
begin
readln(m,n);
if m>n then
   begin
        i:=m;m:=n;n:=i;
   end;
b:=m;
m:=1 shl m-1;
for i:=0 to m do f[1,i]:=1;
for i:=2 to n do
    for j:=0 to m do
        for c:=0 to m do
            if Ok(j,c) then inc(f[i,j],f[i-1,c]);
c:=0;
for i:=0 to m do inc(c,f[n,i]);
writeln(c);
end;
begin
readln(t);
for it:=1 to t do So(f);
end.