const   fi='';
        nmax=30;
type    data=longint;
var
        f:text;
        B:array[-3000..3000,-3000..3000] of word;
        ax,ay:array[0..nmax+1] of data;
        uu,vv,n,res:data;
 
procedure try1(i,u,v:data);
begin
        if i>n div 2 then exit;
        try1(i+1,u+ax[i],v+ay[i]);
        inc(b[u+ax[i],v+ay[i]]);
        try1(i+1,u,v);
end;
 
procedure try2(i,u,v:data);
begin
        if i>n then exit;
        res:=res+b[uu-(u+ax[i]),vv-(v+ay[i])];
        try2(i+1,u+ax[i],v+ay[i]);
        try2(i+1,u,v);
end;
 
procedure docfile;
var     i,j:data;
begin
        assign(f,fi); reset(f);
        readln(f,n);
        fillchar(b,sizeof(b),0);
        for i:=1 to n do
                readln(f,ax[i],ay[i]);
        readln(f,uu,vv); b[0,0]:=1;
        close(f);
end;
 
begin
        docfile;
        try1(1,0,0);
        res:=B[uu,vv];
        try2(n div 2+1,0,0);
        writeln(res);
end.