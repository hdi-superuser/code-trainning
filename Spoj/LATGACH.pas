const   fi='';
var
        f:text;
        T:byte;
        A:array[0..100] of ansistring;
 
 
function cong(a,b:ansistring):ansistring;
var     c:ansistring;
        i,du,carry:word;
begin
        while length(a)<length(b) do
                a:='0'+a;
        while length(b)<length(a) do
                b:='0'+b;
 
        du:=0; c:='';
        for i:=length(a) downto 1 do
                begin
                        carry:=ord(a[i])+ord(b[i])-48*2+du;
                        if carry>9 then
                                begin
                                        du:=1;
                                        carry:=carry-10;
                                end
                        else
                                du:=0;
                        c:=chr(carry+48) + c;
                end;
        if du=1 then c:='1'+c;
        exit(c);
end;
 
procedure fibo;
var     i:byte;
begin
        a[0]:='1';
        a[1]:='1';
        for i:=2 to 100 do
                a[i]:=cong(a[i-1],a[i-2]);
end;
 
begin
        assign(f,fi); reset(f);
        readln(f,t);
        fibo;
        while not eof(f) do
                begin
                        readln(f,t);
                        writeln(a[t]);
                end;
        close(f);
end.