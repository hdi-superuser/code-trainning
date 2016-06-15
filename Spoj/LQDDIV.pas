Program LQDDIV;
CONST FINP = '';	FOUT = '';
TYPE gr = array[1..65555] of int64;
VAR fi,fo:text;
A:array[1..32] of longint;
S1,S2,D1,D2:gr;
N,M:byte;
V2,V1,S:longint;
K:int64;

Procedure Quicksort(Var A:gr; L,R:longint);
Var i,j,mid,tmp:longint;
BEGIN
mid := A[(L+R) div 2];
i := L;
j := R;
	repeat
	while A[i] < mid do inc(i);
	while A[j] > mid do dec(j);
	if i <= j then
		begin
		tmp := A[i];
		A[i] := A[j];
		A[j] := tmp;
		inc(i);
		dec(j);
		end;
	until i > j;
if L < j then Quicksort(A,L,j);
if R > i then Quicksort(A,i,R);
END;

Procedure Try(i:byte);
Var j:byte;
BEGIN
if i = M+1 then 
	begin
	inc(V2);
	S2[V2] := S;
	end
else
	begin
	for j := 0 to 1 do
		begin
		S := S + j*A[i];
		Try(i+1);
		S := S - j*A[i];
		end;
	end;
END;

Procedure Update(Var A,B:gr; Var N:longint);
Var i,j,c,tmp:longint;
BEGIN
c := 0;
i := 1;
while i <= N do
	begin
	if A[i] = A[i+1] then
		begin
		tmp := 1;
		j := i+1;
		while A[j] = A[i] do
			begin
			inc(tmp);
			inc(j);
			end;
		A[i-c] := A[i];
		B[i-c] := tmp;
		inc(c,tmp-1);
		inc(i,tmp);
		end
	else
		begin
		A[i-c] := A[i];
		B[i-c] := 1;
		inc(i);
		end;
	end;
dec(N,c);
END;

Procedure BinSearch(x:longint; Var L,R:longint);
Var mid,tmp:longint;
BEGIN
While R - L >= 2 do
	begin
	mid := (L+R) div 2;
	tmp := 2*(x + S2[mid]);
	if K >= tmp then L := mid
	else R := mid
	end;
END;

Procedure Process;
Var i,j,count,L,R:longint;
T1,dis,tmp,min:int64;
BEGIN
count := 0;
K := 0;
readln(fi,N);
M := N div 2;
for i := 1 to M do 
	begin
	read(fi,A[i]);
	K := K + A[i];
	end;
Try(1);
for i := 1 to V2 do 
	begin
	S1[i] := S2[i];
	S2[i] := 0;
	end;
Quicksort(S1,1,V2);
V1 := V2;
V2 := 0;
S := 0;
if N mod 2 = 1 then inc(M);
for i := 1 to M do 
	begin
	read(fi,A[i]);
	K := K + A[i];
	end;
Try(1);
min := K;
Quicksort(S2,1,V2);
Update(S1,D1,V1);
Update(S2,D2,V2);
for i := 1 to V1 do
	begin
	L := 1;
	R := V2;
	Binsearch(S1[i],L,R);
	for j := L to R do
		begin
		T1 := S1[i] + S2[j];
		dis := abs(K - 2*T1);
//		writeln(fo,S1[i],' ',j,' ',S2[j],' ',dis,' ',T1,' ',K);
		if dis = min then inc(count,D1[i]*D2[j])
		else if min > dis then
			begin
			min := dis;
			count := D1[i]*D2[j];
			end;
		end;
	end;
//for i := 1 to 5 do writeln(fo,S2[i],' ',D2[i]);
writeln(fo,min,' ',count div 2);
END;

BEGIN
assign(fi,FINP);	assign(fo,FOUT);
reset(fi);			rewrite(fo);
Process;
close(fi);
close(fo);
END.