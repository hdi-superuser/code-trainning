uses math;
const   fi='';
        nmax=1000;
var
        f:text;
        s1,s2:ansistring;
        KQ:array[0..nmax+10,0..nmax+10] of word;
 
 
procedure docfile;
begin
        assign(f,fi); reset(f);
        readln(f,s1);
        readln(f,s2);
        close(f);
end;
 
procedure bpa;
var     i,j:word;
begin
        for i:=0 to length(s1) do
                kq[i,0]:=0;
 
        for i:=0 to length(s2) do
                kq[0,i]:=0;
 
        for i:=1 to length(s1) do
                for j:=1 to length(s2) do
                        if s1[i]=s2[j] then
                                KQ[i,j]:=kq[i-1,j-1] + 1
                        else
                                KQ[i,j]:=max(kq[i,j-1],kq[i-1,j]);
 
        writeln(kq[length(s1),length(s2)]);
end;
 
begin
        docfile;
        bpa;
end.