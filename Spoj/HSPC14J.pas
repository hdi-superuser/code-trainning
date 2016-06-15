const   fi='';
        nmax=1000;
 
type    data=longint;
 
var
        f:text;
        x,M:data;
        A:array[1..nmax] of boolean;
 
procedure xuli;
var     i,j,k:data;
 
begin
        for i:=1 to x do a[i]:=false;
        i:=2;
        k:=0;
        while i<=x do
                begin
                        if not a[i] then
                                begin
                                        for j:=1 to x div i do
                                                if not a[i*j] then
                                                        begin
                                                                inc(k);
                                                                if k=m then
                                                                        begin
                                                                                writeln(i*j);
                                                                                exit;
                                                                        end;
                                                                a[i*j]:=true;
                                                        end;
                                end;
                        inc(i);
                end;
end;
 
begin
        assign(f,fi); reset(f);
        while not eof(f) do
                begin
                        readln(f,x,m);
                        xuli;
                end;
end.