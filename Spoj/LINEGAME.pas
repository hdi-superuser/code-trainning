uses 	math;
const   fi='';
        nmax=1000000;
type    data=longint;
var
        n:data;
        a:array[1..nmax] of longint;
        cong,tru:array[1..nmax] of int64;
        f:text;
 
procedure docfile;
var     i:data;
begin
        assign(f,fi); reset(f);
        readln(f,n);
        for i:=1 to n do
                read(f,a[i]);
        close(f);
end;
 
procedure bpa;
var     i:data;
begin
        cong[1]:=a[1];
        tru[1]:=0;
        for i:=2 to n do
                begin
			cong[i]:=max(tru[i-1]+a[i],cong[i-1]);
			tru[i]:=max(cong[i-1]-a[i],tru[i-1]);
                end;
        writeln(max(cong[n],tru[n]));
 
end;
 
 
begin
        docfile;
        bpa;
        //readln;
end.