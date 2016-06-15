var     a,b:word;
 
function UCLN(a,b:longint):word;
var     r:word;
begin
        while a mod b <>0 do
                begin
                        r:=a mod b;
                        a:=b;
                        b:=r;
                end;
        exit(b);
end;
 
function sodao(n:word):longint;
var     tam:longint;
begin
        tam:=0;
        while N<>0 do
                begin
                        tam:=tam*10 + (n mod 10);
                        n:=n div 10;
                end;
        exit(tam);
 
end;
 
procedure xuli;
var     i:word;
        s:int64;
begin
        s:=0;
        for i:=a to b do
                if ucln(i,sodao(i))=1 then
                                inc(s); 
        writeln(s);
 
end;
 
begin
        readln(a,b);
        xuli;
end.
