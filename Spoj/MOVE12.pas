const
        tfi='';//move12.inp';
        tfo='';//move12.out';
 
var
        fi,fo:text;
        n,nh:longint;
        a,b,h,pos,c,t,v:array[0..10000]of longint;
 
procedure nhap;
        var i:longint;
        begin
                read(fi,n);
                for i:=1 to n do read(fi,c[i],t[i]);
        end;
 
 
procedure swap(var x,y:longint);
        var tg:longint;
        begin
                tg:=x;
                x:=y;
                y:=tg;
        end;
 
procedure upheap(i:longint);
        var j:longint;
        begin
                j:=i div 2;
                if (i>1) and (b[h[i]]<b[h[j]]) then
                        begin
                                swap(h[i],h[j]);
                                upheap(j);
                        end;
        end;
 
procedure downheap(i:longint);
        var j:longint;
        begin
                j:=i+i;
                if (j>nh) then exit;
                if (j<nh) and (b[h[j]]>b[h[j+1]]) then inc(j);
                if b[h[i]]>b[h[j]] then
                        begin
                                swap(h[i],h[j]);
                                downheap(j);
                        end;
        end;
 
procedure push(x:longint);
        begin
                inc(nh);
                h[nh]:=x;
                upheap(nh);
        end;
 
 
function pop:longint;
        begin
                pop:=h[1];
                h[1]:=h[nh];
                dec(nh);
                downheap(1);
        end;
 
procedure sort(l,r:longint);
        var i,j,key:longint;
        begin
                i:=l;
                j:=r;
                key:=a[l+random(r-l+1)];
                repeat
                        while a[i]<key do inc(i);
                        while a[j]>key do dec(j);
                        if i<=j then
                                begin
                                        swap(a[i],a[j]);
                                        swap(b[i],b[j]);
                                        inc(i);
                                        dec(j);
                                end;
                until i>j;
                if i<r then sort(i,r);
                if l<j then sort(l,j);
        end;
 
function check(x:longint):boolean;
        var i,j,u:longint;
        begin
                nh:=0;
                for i:=1 to  n do
                        begin
                                a[i]:=c[i]-(x div t[i]);
                                b[i]:=c[i]+(x div t[i]);
                        end;
                sort(1,n);
                i:=0;
                j:=1;
                for i:=1 to n do
                begin
                while (a[j]<=i)  and (j<=n) do
                        begin
                                push(j);
                                inc(j);
                        end;
                        if nh>0 then u:=pop else u:=0;
                        if b[u]<i then exit(false);
                end;
                exit(true);
        end;
 
 
procedure xuli;
        var l,r,mid,res:longint;
        begin
 
                l:=0;
                r:=10000*10000;
                while l<=r do
                        begin
                                mid:=(l+r) div 2;
                                if check(mid) then
                                        begin
                                                res:=mid;
                                                r:=mid-1;
                                        end
                                else l:=mid+1;
                        end;
                writeln(fo,res);
        end;
 
 
begin
        assign(fi,tfi);
        assign(fo,tfo);
        reset(fi);
        rewrite(fo);
        nhap;
        xuli;
        close(fo);
end.