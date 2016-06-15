const   fi='';
        nmax=1000;
type    data=longint;
var
        f:text;
        A:array[0..nmax+1,0..nmax+1] of int64;
        n,m,k:data;

function GetS(x,y,u,v:data):int64;
begin
        gets:=A[u,v]-A[u,y-1]-a[x-1,v]+a[x-1,y-1];
end;

function min(a,b:int64):int64;
begin
        if a<b then exit(a); exit(b);
end;

procedure xuli(x,y,u,v:data);
var     i,j:data;
        res,Sfull,stam:int64;
        dau,cuoi,giua:data;
begin
        Sfull:=getS(x,y,u,v);
        res:=high(int64);
        dau:=x;
        cuoi:=u-1;
        while dau<=cuoi do
                begin
                        giua:=(dau+cuoi) shr 1;
                        stam:=getS(x,y,giua,v);
                        if 2*stam<=sfull then
                                begin
                                        res:=min(res,sfull-2*stam);
                                        dau:=giua+1;
                                end
                        else
                                cuoi:=giua-1;
                end;
        dau:=x;
        cuoi:=u-1;
        while dau<=cuoi do
                begin
                        giua:=(dau+cuoi) shr 1;
                        stam:=getS(x,y,giua,v);
                        if 2*stam>=sfull then
                                begin
                                        res:=min(res,2*stam-sfull);
                                        cuoi:=giua-1;
                                end
                        else
                                dau:=giua+1;
                end;
        dau:=y;
        cuoi:=v-1;
        while dau<=cuoi do
                begin
                        giua:=(dau+cuoi) shr 1;
                        stam:=gets(x,y,u,giua);
                        if 2*stam>=sfull then
                                begin
                                        res:=min(res,2*stam-sfull);
                                        cuoi:=giua-1;
                                end
                        else
                                dau:=giua+1;
                end;
        dau:=y;
        cuoi:=v-1;
        while dau<=cuoi do
                begin
                        giua:=(dau+cuoi) shr 1;
                        stam:=gets(x,y,u,giua);
                        if 2*stam<=sfull then
                                begin
                                        res:=min(res,sfull-2*stam);
                                        dau:=giua+1
                                end
                        else
                                cuoi:=giua-1;
                end;
        writeln(res);
end;

Procedure docfile;
var     i,j,x,y,u,v:data;
begin
        assign(f,fi); reset(f);
        read(f,m,n,k);
        for i:=0 to m+1 do
                A[i,0]:=0;
        for j:=0 to n+1 do
                a[0,j]:=0;
        for i:=1 to m do
                for j:=1 to n do
                        begin
                                read(f,a[i,j]);
                                A[i,j]:=A[i,j]+A[i-1,j]+a[i,j-1]-A[i-1,j-1];
                        end;
        for i:=1 to k do
                begin
                        read(f,x,y,u,v);
                        xuli(x,y,u,v);
                end;
        close(f);
end;

begin
        docfile;
end.


