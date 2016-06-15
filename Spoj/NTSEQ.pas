uses    math;
const   fi      =       '';
        fo      =       '';
        base       =       1000000007;
        maxn       =       100000;
type    matrix    =       record
                num,len:int64;
                end;
var     f,g     :       text;
        kq      :       qword;
        A       :       array[1..100001] of int64;
        B,cs     :       array[1..100001] of int64;
        T       :       array[1..100001] of matrix;
 
        i,j,k,n,key :       longint;
procedure        update(x:longint;tmp:matrix);
        Begin
                If (x>maxn) then exit;
                 If (T[x].num<tmp.num) then T[x]:=tmp else
                  if (T[x].num=tmp.num) then
 
                                T[x].len:=(T[x].len + tmp.len mod  base ) mod base;
                 x:=x+x and (-x);
                 update(x,tmp);
        end;
function        find(x:longint):matrix;
        var res:matrix;
        Begin
                res.num:=0;
                res.len:=0;
                While (x>0) do
                   Begin
                        If (res.num<T[x].num) then
 
                           res:=T[x]
                        else
                           If (res.num=T[x].num) then
                              res.len:=(res.len +T[x].len) mod base;
                        x:=x-x and (-x);
                   end;
                inc(res.num);
                If (res.len=0) then res.len:=1;
                exit(res);
        end;
 
procedure       QS(l,h:longint);
var     x,tg,i,j  :       longint;
begin
        i:=l;
        j:=h;
        x:=a[(l+h) div 2];
        repeat
                while a[i]<x do inc(i);
                while a[j]>x do dec(j);
                if i<=j then
                        begin
                                tg:=a[i];
                                a[i]:=a[j];
                                a[j]:=tg;
                                tg:=cs[i];
                                cs[i]:=cs[j];
                                cs[j]:=tg;
                                inc(i);
                                dec(j);
                        end;
                until   i>j;
        if i<h then QS(i,h);
        if j>L then QS(l,j);
end;
procedure       doc;
        Begin
 
                assign(f,fi); assign(g,fo);
                reset(f); rewrite(g);
                readln(f,n);
                for i:=1 to n do
                  read(f,A[i]);
                for i:=1 to n do cs[i]:=i;
                QS(1,n);
        end;
procedure       cbi;
        Begin
                fillchar(t,sizeof(t),0);
                key:=1; B[cs[1]]:=1;
                for i:=2 to n do
                  Begin
                        If (A[i]<>A[i-1]) then inc(key);
                        B[cs[i]]:=key;
                  end;
        end;
procedure       enter;
        var tmp:matrix;
        Begin
 
                for i:=1 to n do
                    Begin
                        tmp:=find(B[i]-1);
                        update(B[i],tmp);
                    end;
                tmp:=find(n);
                writeln(g,tmp.len);
                close(g);
        end;
Begin
        doc;
        cbi;
        enter;
end.
 