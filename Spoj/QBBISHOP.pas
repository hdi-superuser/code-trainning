
const   fi='';
        nmax=205;
        cld:array[1..4] of shortint=(1,1,-1,-1);
        clc:array[1..4] of shortint=(1,-1,1,-1);
type
        data=longint;
        dulieu=record
                u,v:data;
        end; 
var
        f:text;
        A:array[0..nmax+1,0..nmax+1] of byte;
        m,n,s,t,q,p:data;
        C:array[0..nmax+1,0..nmax+1] of data;
 
        H:array[0..nmax*nmax] of dulieu;
        dau,cuoi:data;
 
procedure docfile;
var     i,j,u,v:data;
begin
        assign(f,fi); reset(f);
        readln(f,n,m,p,q,s,t);
        for i:=1 to n do
                for j:=1 to n do
                        a[i,j]:=0;
        for i:=0 to n +1 do
                begin
                        A[0,i]:=3;
                        A[n+1,i]:=3;
                        A[i,0]:=3;
                        a[i,n+1]:=3;
                end;
        for i:=1 to m do
                begin
                        readln(f,u,v);
                        a[u,v]:=2;
                end;
        close(f);
end;
 
procedure themvao(x,y:data);
begin
        inc(cuoi);
        H[cuoi].u:=x;
        H[cuoi].v:=y;
end;
 
 
procedure layra(var x,y:data);
begin
        x:=H[dau].u;
        y:=H[dau].v;
        inc(dau);
end;
 
procedure go(x,y,k:data);
var     u,v:data;
begin
        u:=x;
        v:=y;
        while a[u,v]<>3 do
                begin
                        if (A[u,v]=0) then
                                begin
                                        c[u,v]:=c[x,y]+1;
                                        themvao(u,v);
                                        a[u,v]:=1;
                                end;
                        if a[u,v]=2 then
                                exit;
                        if (u=s) and (v=t) then
                                begin
                                        writeln(c[s,t]);
                                        readln;
                                        halt;
                                end;
                        u:=u+cld[k];
                        v:=v+clc[k];
                end;
 
end;
 
procedure bfs;
var     i,j,x,y:data;
begin
        dau:=1;
        cuoi:=0;
        themvao(p,q);
        a[p,q]:=1;
        for i:=1 to n do
                for j:=1 to n do
                        C[i,j]:=0;
 
        while not (dau>cuoi) do
                begin
                        layra(x,y);
                        for i:=1 to 4 do
                                go(x,y,i);
                end;
        if c[s,t]=0 then
                writeln('-1');
end; 
begin
        docfile;
        bfs;
end.