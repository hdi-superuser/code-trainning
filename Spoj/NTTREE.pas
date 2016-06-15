//NTTREE
const
   ip='';
   op='';
   max=20000;
   maxe=20000;
 
var
   n,i:longint;
   d:array[1..max+1] of longint;
   a:array[1..maxe] of longint;
   c:array[1..maxe] of int64;
   x,y:array[1..max] of longint;
   cost,con:array[1..max] of int64;
 
   res:int64;
 
   free:array[1..max] of boolean;
 
procedure Visit(u:longint);
 
   var
      i,v:longint;
      cost:int64;
 
   begin
 
      free[u]:=false;
 
      con[u]:=1;
 
      for i:=d[u]+1 to d[u+1] do
         begin
            v:=a[i];
            cost:=c[i];
 
            if free[v] then
               begin
                  Visit(v);
                  con[u]:=con[u]+con[v];
                  res:=res+cost*(con[v]*(n-con[v]));
               end;
         end;
 
   end;
 
begin
 
assign(input,ip);reset(input);
assign(output,op);rewrite(output);
 
readln(n);
 
for i:=2 to n do
   begin
      readln(x[i],y[i],cost[i]);
      inc(x[i]);
      inc(y[i]);
      inc(d[x[i]]);
      inc(d[y[i]]);
   end;
 
for i:=2 to n+1 do d[i]:=d[i]+d[i-1];
 
for i:=2 to n do
   begin
      a[d[x[i]]]:=y[i];
      c[d[x[i]]]:=cost[i];
      a[d[y[i]]]:=x[i];
      c[d[y[i]]]:=cost[i];
      dec(d[x[i]]);
      dec(d[y[i]]);
   end;
 
fillchar(free,sizeof(free),true);
 
Visit(1);
 
write(res);
 
close(input);close(output);
 
end.