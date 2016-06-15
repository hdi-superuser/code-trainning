Uses math;
Const input='';
      output='';
      MaxN=100001;
 
Var fi,fo:text;
    n:longint;
    b,res:int64;
    p,c:array[1..MaxN] of int64;
 
Procedure Scanf;
var i:longint;
begin
    readln(fi,n,b);
    for i:=1 to n do readln(fi,p[i],c[i]);
end;
 
Procedure Swap(var u,v:int64);
var temp:int64;
begin
      temp:=u;
      u:=v;
      v:=temp;
end;
 
 
Procedure Qsort(l,r:longint);
var i,j:longint;
    mid:int64;
begin
   i:=l;
   j:=r;
 
   mid:=p[(l+r) div 2];
 
   repeat
       while p[i]<mid do inc(i);
       while p[j]>mid do dec(j);
 
       if i<=j then
        begin
             Swap(p[i],p[j]);
             Swap(c[i],c[j]);
             inc(i);
             dec(j);
        end;
   until i>j;
 
   if (i<r) then qsort(i,r);
   if (j>l) then qsort(l,j);
end;
 
Procedure process;
var i:longint;
    j:int64;
begin
    res:=0; Qsort(1,n);
 
    for i:=1 to n do
     begin
         j:=min(b div p[i],c[i]);
         if j=0 then exit;
         inc(res,j);
         dec(b,j*p[i]);
     end;
end;
 
Procedure Printf;
begin
      writeln(fo,res);
end;
 
BEGIN
      assign(fi,input);
      reset(fi);
 
      assign(fo,output);
      rewrite(fo);
 
      Scanf;
      Process;
      Printf;
 
      close(fi);
      close(fo);
END.