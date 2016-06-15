program QBMAX;
const   fi='';
        nmax=101;
        vc=maxint;
type    matran=array[0..nmax,0..nmax] of integer;
 
var
        a:matran;
        m,n:byte;
        f:text;
 
procedure docfile;
var i,j:byte;
begin
 
        assign(f,fi);
        reset(f);
        readln(f,m,n);
 
        for i:=0 to m+1 do
                for j:=0 to n+1 do
                        a[i,j]:=-vc;
 
        for i:=1 to m do
                for j:=1 to n do
                        read(f,a[i,j]);
        close(f);
end;
 
function max(a,b,c:longint):longint;
begin
        max:=a;
        if max<b then
                max:=b;
        if max<c then
                exit(c);
end;
 
procedure bpa;
var i,j:byte;
        kq:longint;
begin
        for j:=2 to n do
                for i:=1 to m do
                        a[i,j]:=max(a[i-1,j-1],a[i,j-1],a[i+1,j-1]) + a[i,j];
        kq:=-maxlongint;
        for i:=1 to m do
                if kq<a[i,n] then
                        kq:=a[i,n];
        writeln(kq);
end;             
 
begin
        docfile;
        bpa;
end.
2
1
2
3
4
5
6
7
8
9
10
11
12
13
14
15
16
17
18
19
20
21
22
23
24
25
26
27
28
29
30
31
32
33
34
35
36
37
38
39
40
41
42
43
44
45
46
47
48
49
50
51
52
53
54
55
56
program QBMAX;
const   fi='';
        nmax=101;
        vc=maxint;
type    matran=array[0..nmax,0..nmax] of integer;
 
var
        a:matran;
        m,n:byte;
        f:text;
 
procedure docfile;
var i,j:byte;
begin
 
        assign(f,fi);
        reset(f);
        readln(f,m,n);
 
        for i:=0 to m+1 do
                for j:=0 to n+1 do
                        a[i,j]:=-vc;
 
        for i:=1 to m do
                for j:=1 to n do
                        read(f,a[i,j]);
        close(f);
end;
 
function max(a,b,c:longint):longint;
begin
        max:=a;
        if max<b then
                max:=b;
        if max<c then
                exit(c);
end;
 
procedure bpa;
var i,j:byte;
        kq:longint;
begin
        for j:=2 to n do
                for i:=1 to m do
                        a[i,j]:=max(a[i-1,j-1],a[i,j-1],a[i+1,j-1]) + a[i,j];
        kq:=-maxlongint;
        for i:=1 to m do
                if kq<a[i,n] then
                        kq:=a[i,n];
        writeln(kq);
end;             
 
begin
        docfile;
        bpa;
end.
3
4
5
6
7
8
9
10
11
12
13
14
15
16
17
18
19
20
21
22
23
24
25
26
27
28
29
30
31
32
33
34
35
36
37
38
39
40
41
42
43
44
45
46
47
48
49
50
51
52
53
54
55
56
program QBMAX;
const   fi='';
        nmax=101;
        vc=maxint;
type    matran=array[0..nmax,0..nmax] of integer;
 
var
        a:matran;
        m,n:byte;
        f:text;
 
procedure docfile;
var i,j:byte;
begin
 
        assign(f,fi);
        reset(f);
        readln(f,m,n);
 
        for i:=0 to m+1 do
                for j:=0 to n+1 do
                        a[i,j]:=-vc;
 
        for i:=1 to m do
                for j:=1 to n do
                        read(f,a[i,j]);
        close(f);
end;
 
function max(a,b,c:longint):longint;
begin
        max:=a;
        if max<b then
                max:=b;
        if max<c then
                exit(c);
end;
 
procedure bpa;
var i,j:byte;
        kq:longint;
begin
        for j:=2 to n do
                for i:=1 to m do
                        a[i,j]:=max(a[i-1,j-1],a[i,j-1],a[i+1,j-1]) + a[i,j];
        kq:=-maxlongint;
        for i:=1 to m do
                if kq<a[i,n] then
                        kq:=a[i,n];
        writeln(kq);
end;             
 
begin
        docfile;
        bpa;
end.
