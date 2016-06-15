uses    math;
const
        finp='';
        fout='';
        maxn=500010;
var
        f1,f2:text;
        a,h:array[0..maxn] of longint;
        d,c,g,i,n:longint;

procedure lam;
var i,top,luu:longint;
	kq:int64;
begin
        h[1]:=n; top:=1; kq:=0;
        for i:=n-1 downto 1 do
         begin

          d:=0;c:=top+1;
          while (c-d>1)do
           begin
             g:=(d+c)div 2;
             if (a[h[g]]<=a[i])then c:=g
             else d:=g;
           end;
          if d=0 then inc(kq,top)
          else inc(kq,top-d+1);
          while (top>0)and(a[h[top]]<a[i])do dec(top);
          inc(top);h[top]:=i;
         end;
        write(f2,kq);
end;

begin
        assign(f1,finp); reset(f1);
        assign(f2,fout); rewrite(f2);
        readln(f1,n);
        for i:=1to n do readln(f1,a[i]);
        lam;
        close(f1); close(f2);
end.