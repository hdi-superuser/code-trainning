const   fi='';
        nmax=25;
type    data=longint;
var
        f:text;
        n,k,i,test:data;
        A:array[0..nmax,0..nmax] of int64;
 
procedure init;
var     i,j:data;
begin
        fillchar(A,sizeof(a),0);
        a[0,0]:=1;
        for i:=1 to 25 do
                for j:=1 to i do
                        a[i,j]:=a[i-1,j-1]+a[i-1,j]*j;
end;
 
begin
        init;
        assign(f,fi); reset(f);
        readln(f,test);
        for i:=1 to test do
                begin
                        readln(f,n,k);
                        writeln(a[n,k]);
                end;
        close(f);
end.