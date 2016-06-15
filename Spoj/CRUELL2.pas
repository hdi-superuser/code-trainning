// CRUELL2
{$N+}
const min=0.000005;
      oo=1000000;
var d,i,r:longint;
    t:extended;
    a:array[0..11] of extended;
function f(x:extended):extended;
         var t,r:extended;
             i,j:longint;
         begin
              r:=0;
              for i:=0 to d do
                  begin
                       t:=a[i];
                       for j:=1 to i do t:=t*x;
                       r:=r+t;
                  end;
              f:=r;
         end;
function Find(l,r,fl,fr:extended):extended;
         var m,t:extended;
         begin
              m:=(l+r)/2;
              if r-l<=min then
                 begin
                      Find:=m;
                      exit;
                 end;
              t:=f(m);
              if t*fl<0 then Find:=Find(l,m,fl,t)
              else Find:=Find(m,r,t,fr);
         end;
begin
readln(d);
for i:=0 to d do readln(a[i]);
t:=Find(-oo,+oo,f(-oo),f(+oo))*1000;
r:=trunc(t);
writeln(r);
end.