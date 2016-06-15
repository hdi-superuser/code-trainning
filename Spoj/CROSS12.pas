Var M,N: longint;
    S: ansistring;
    R,A,F,luu: Array[0..150000] of longint;
 
Function max(a,b: longint): longint;
begin
    max:=a;
    if b>max then max:=b;
end;
 
Function min(a,b: longint): longint;
begin
    min:=a;
    if b<min then min:=b;
end;
 
 
Function xuli(i: longint): longint;
var bd,dem: longint;
begin
    bd:=0;
    dem:=0;
    While bd<=m do
      begin
        bd:=bd+i;
        inc(dem);
        While S[bd]='1' do dec(bd);
      end;
    exit(dem);
end;
 
 
Procedure Enter;
var i,j: longint;
    max1,min1: longint;
begin
    Readln(N,M);
    max1:=0; min1:=100000000;
    for i:=1 to N do
      begin
        read(R[i]);
        max1:=max(max1,R[i]);
        min1:=min(min1,R[i]);
      end;
    Readln;
    Read(S);
    For i:=1 to 101 do S:=S+'';
    for i:=min1 to max1 do luu[i]:=xuli(i);
    for i:=1 to n do A[i]:=luu[R[i]];
end;
 
 
 
Procedure Sort(L,h: longint);
var key,t,i,j: longint;
begin
    if L>=H then EXIT;
    key:=A[random(H-L+1)+L];
    i:=L; j:=H;
    repeat
      While A[i]<key do inc(i);
      While A[j]>key do dec(j);
      if i<=j then
        begin
           if i<j then begin t:=A[i];A[i]:=A[j];A[j]:=t end;
           inc(i); dec(j);
        end;
    until i>j;
    Sort(L,j); Sort(i,H);
 
end;
 
Procedure Process;
var i,j: longint;
begin
    F[0]:=0; F[1]:=A[1]; F[2]:=A[2];
    For i:=3 to N do
      F[i]:=min(F[i-1]+A[i]+A[1], F[i-2]+A[1]+2*A[2]+A[i]);
    Write(F[n]);
end;
 
begin
        Enter;
        Sort(1,N);
        Process;
end.