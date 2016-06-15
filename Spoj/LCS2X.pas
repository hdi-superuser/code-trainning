uses    math;
const   fi='';
        nmax=1500+100;
type
        data=longint;
var
        f:text;
        n,m,test:data;
        a,b,d:array[0..nmax] of data;
        C:array[0..nmax,0..nmax] of data;
        gtmax,res:data;
 
procedure QHD;
var     i,j:data;
begin
        res:=0;
        for i:=0 to n do
                d[i]:=0;
 
        for i:=1 to m do
                begin
                        gtmax:=0;
                        for j:=1 to n do
                                begin
                                        if a[i]=b[j] then
                                                c[i,j]:=gtmax+1;
                                        if a[i]>=2*b[j] then
                                                gtmax:=max(gtmax,d[j]);
                                        if a[i]=b[j] then
                                                begin
                                                        res:=max(res,c[i,j]);
                                                        d[j]:=max(d[j],c[i,j]);
                                                end;
                                end;
                end;
        writeln(res);
end;
 
procedure docfile;
var     i,j:data;
begin
        assign(f,fi); reset(f);
        readln(f,test);
        for i:=1 to test do
                begin
                        read(f,m,n);
                        for j:=1 to m do
                                read(f,a[j]);
                        for j:=1 to n do
                                read(f,b[j]);
                        QHD;
                end;
 
        close(f);
end;
 
 
begin
        docfile;
end.