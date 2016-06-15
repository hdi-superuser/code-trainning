// COUNTPL
{$H+}
 
const
   ip='';
   op='';
   max=300;
 
var
   s:string;
   n:longint;
   c:array[1..max,1..max] of boolean;
 
procedure Creat_Way;
 
   var
      i,j:longint;
 
   begin
 
      for i:=n downto 1 do
         begin
 
            c[i,i]:=true;
 
            if i<n then
               if s[i]=s[i+1] then c[i,i+1]:=true;
 
            for j:=i+2 to n do
               if s[i]=s[j] then
                  if c[i+1,j-1] then c[i,j]:=true;
 
         end;
 
   end;
 
procedure Solve;
 
   var
      res:array[0..max] of longint;
      i,j:longint;
 
   begin
 
      res[0]:=0;
 
      for i:=1 to n do res[i]:=max;
 
      for i:=1 to n do
         for j:=1 to i do
            if c[j,i] then
               if res[i]>res[j-1]+1 then res[i]:=res[j-1]+1;
 
//      for i:=0 to n do write(res[i],' ');writeln;
 
      write(res[n]);
 
   end;
 
begin
 
assign(input,ip);reset(input);
assign(output,op);rewrite(output);
 
readln(s);
 
n:=length(s);
 
Creat_Way;
 
Solve;
 
close(input);close(output);
 
end.
 