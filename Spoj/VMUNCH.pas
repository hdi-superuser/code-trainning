program vmunch;
const   fi='';
        nmax=100;
        cld:array[1..4] of shortint=(0,0,1,-1);
        clc:array[1..4] of shortint=(1,-1,0,0);
type    matran=array[0..nmax+1,0..nmax+1] of longint;
var     a:matran;
        m,n:longint;
        f:text;
        dong,cot:byte;

        QX,QY:array[1..nmax*nmax] of longint;
        C:array[1..nmax*nmax] of longint;
        dau,cuoi:longint;

procedure xuat;
var     i,j:word;
begin
        for i:=1 to n do
                begin
                        for j:=1 to n do
                                write(a[i,j]:3);
                        writeln;
                end;
        for i:=1 to cuoi do
                write(c[i],' ');
        writeln;
end;

procedure docfile;
var     i,j:byte;
        s:char;
begin
        assign(f,fi); reset(f);
        readln(f,m,n);
        a[1,1]:=0;
        for i:=0 to m+1 do
                for j:=0 to n+1 do
                        a[i,j]:=1;
        a[1,1]:=0;

                for i:=1 to m do
                begin
                        for j:=1 to n do
                                begin
                                        read(f,s);
                                        if s='.' then
                                                a[i,j]:=0
                                        else
                                                if s='C' then
                                                        begin
                                                                dong:=i;
                                                                cot:=j;
                                                                a[i,j]:=0;
                                                        end;
                                end;
                        readln(f);
                end;
        close(f);
end;

function empty:boolean;
begin
        exit(dau>cuoi);
end;

procedure them(x,y:byte);
begin
        inc(cuoi);
        qx[cuoi]:=x;
        qy[cuoi]:=y;
end;

procedure layra(var x,y:byte);
begin
        x:=qx[dau];
        y:=qy[dau];
        inc(dau);
end;

procedure BFS;
var     i:byte;
        x,y:byte;
        x1,y1,k:byte;
begin
        fillchar(C,sizeof(c),0);
        Fillchar(qy,sizeof(qy),0);
        Fillchar(qx,sizeof(qx),0);
        dau:=1;
        cuoi:=0;

        them(1,1);
        c[1]:=1;
        a[1,1]:=1;
        repeat
                begin
                        layra(x,y);
                       For k:=1 to 4 do
                                if a[x+cld[k],y+clc[k]]=0 then
                                        begin
                                                a[x+cld[k],y+clc[k]]:=c[dau-1]+1;
                                                them(x+cld[k],y+clc[k]);
                                                c[cuoi]:=c[dau-1]+1;
                                        End;
                end;
        until empty;
        writeln(a[dong,cot]-1);
end;


begin
        docfile;
        BFS;
        readln;
end.
