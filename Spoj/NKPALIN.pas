uses    math;
const   fi='';
        nmax=2000;
var
        f:text;
        S:ansistring;
        L:array[0..nmax+1,0..nmax+1] of word;
        n:word;
 
procedure docfile;
begin
        assign(f,fi); reset(f);
        readln(f,s);
        close(f);
end;
 
procedure bpa;
var     i,j:word;
        kq:ansistring;
begin
        n:=length(s);
        for i:=0 to n do
                begin
                        L[i,n+1]:=0;
                        L[0,i]:=0;
                end;
        for i:=1 to n do
                for j:=n downto 1 do
                        if s[i]=s[j] then
                                L[i,j]:=L[i-1,j+1] + 1
                        else
                                L[i,j]:=max(L[i-1,j],L[i,j+1]);
        i:=n; j:=1;
        kq:='';
        while (i>0) and (j<n+1) do
                if s[i]=s[j] then
                        begin
                                kq:=kq+s[i];
                                dec(i); inc(j);
                        end
                else
                        if l[i,j]=l[i-1,j] then
                                dec(i)
                        else
                                inc(j);
        writeln(kq);
end; 
 
begin
        docfile;
        bpa;
end.