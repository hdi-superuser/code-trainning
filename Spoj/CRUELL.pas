const base=1000000000;
      pow=9;
      max=15000;
type int=qword;
     bignum=
     record
           l:longint;
           a:array[1..10000] of int;
     end;
var no,res,n,tmp:bignum;
    i,kk,m,p,k:longint;
    out:array[1..max] of longint;
procedure Nhan(x,y:bignum;var key:bignum);
          var i,j,k,tmp:longint;
          begin
               k:=0;
               key:=no;
               for i:=1 to x.l do
                   begin
                        for j:=1 to y.l do
                            begin
                                 tmp:=j+k;
                                 inc(key.a[tmp],x.a[i]*y.a[j]);
                                 inc(key.a[tmp+1],key.a[tmp] div base);
                                 key.a[tmp]:=key.a[tmp] mod base;
                            end;
                        inc(k);
                   end;
               if key.a[tmp+1]<>0 then inc(tmp);
               key.l:=tmp;
          end;
procedure Creat;
          var i,j:longint;
              l,n:longint;
              c:longint;
              f:array[1..pow] of longint;
          begin
               l:=res.l;
               c:=0;
               m:=0;
               n:=res.a[l];
               while n>0 do
                     begin
                          inc(c);
                          f[c]:=n mod 10;
                          n:=n div 10;
                     end;
               for i:=c downto 1 do
                   begin
                        inc(m);
                        out[m]:=f[i];
                   end;
               for i:=l-1 downto 1 do
                   begin
                        n:=res.a[i];
                        c:=0;
                        while n>0 do
                              begin
                                   inc(c);
                                   f[c]:=n mod 10;
                                   n:=n div 10;
                              end;
                        inc(m,pow-c);
                        for j:=c downto 1 do
                            begin
                                 inc(m);
                                 out[m]:=f[j];
                            end;
                   end;
          end;
begin
read(p,kk);
n.l:=1;
if p<base then n.a[1]:=p
else
    begin
         n.l:=2;
         n.a[1]:=p mod base;
         n.a[2]:=p div base;
    end;
no.l:=1;
res.l:=1;res.a[1]:=1;
{----}
k:=trunc(sqrt(kk));
dec(kk,k*k);
for i:=1 to k do Nhan(res,n,res);
tmp:=res;
for i:=1 to k-1 do Nhan(res,tmp,res);
for i:=1 to kk do Nhan(res,n,res);
Creat;
for i:=1 to m do
    begin
         write(out[i]);
         if i mod 70=0 then writeln;
    end;
end.