uses    math;
const   finp='';
        fout='';
var     fi,fo:text;
        i,n:longint;
        a,b,cs,luu,tree:array[0..300005]of longint;
procedure qs(d,c:longint);
        var i,j,g,g1,tg:longint;
        begin
            i:=d;j:=c;
            g:=(d+c) div 2;g1:=b[g];g:=a[g];
            repeat
                while (a[i]<g)or((a[i]=g)and(b[i]<g1)) do i:=i+1;
                while (a[j]>g)or((a[j]=g)and(b[j]>g1)) do j:=j-1;
                if i<=j then
                   begin
                      tg:=a[i];a[i]:=a[j];a[j]:=tg;
                      tg:=b[i];b[i]:=b[j];b[j]:=tg;
                      tg:=cs[i];cs[i]:=cs[j];cs[j]:=tg;
                      i:=i+1;j:=j-1;
                   end;
            until i>j;
            if i<c then qs(i,c);
            if j>d then qs(d,j);
        end;
function tv(x:longint):longint;
        var t:longint;
        begin
            t:=0;
            while x>0 do
                begin
                    t:=t+tree[x];
                    x:=x-x and(-x);
                end;
            exit(t);
        end;
procedure up(x:longint);
        begin
             while x<=100000 do
                begin
                   tree[x]:=tree[x]+1;
                   x:=x+x and (-x);
                end;
        end;
procedure lam;
        var i,j,d:longint;
        begin
            d:=0;
            for i:=1 to n do
                begin
                    if i=1 then d:=0 else
                    if (a[i]=a[i-1])and(b[i]=b[i-1]) then d:=d+1 else d:=0;
                    luu[cs[i]]:=tv(b[i])-d;
                    up(b[i]);
                end;
            for i:=1 to n do writeln(fo,luu[i]);
        end;
begin
        assign(fi,finp);reset(fi);
        assign(fo,fout);rewrite(fo);
        readln(fi,n);
        for i:=1 to n do
           begin
              readln(fi,a[i],b[i]);
              cs[i]:=i;
           end;
        qs(1,n);
        lam;
        close(fi);close(fo);
end.
 
 
