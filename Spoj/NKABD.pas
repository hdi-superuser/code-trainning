program bt;
const   fi='';
        fo='';
var
        f:text;
        a,b:longint;
 
 
function check(n:longint):boolean;
var     i:longint;
        S:longint;
begin
        s:=1;       
        for i:=2 to trunc(sqrt(n)) do
                if n mod i = 0 then
                	begin     
                        	inc(s,i);
                        	if i<>n div i then
                        		inc(s,n div i);
                        	if s>n then exit(true);	
                        end;                 
        exit(s>n);
end;
 
procedure xuli;
var     i:longint;
        dem:longint;
begin
        dem:=0;
        for i:=a to b do
                if check(i) then
                        inc(dem);
 
        writeln(f,dem);
 
end;
 
 
begin
        assign(f,fi); reset(f);
        readln(f,a,b);
        close(f);
 
        assign(f,fo); rewrite(f);
        xuli;
        close(f);
end.