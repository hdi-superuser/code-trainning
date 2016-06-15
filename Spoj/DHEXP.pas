Const
finp	=	'';
fout	=	'';
Var
fi, fo : text;
n, k : longint;
gt : int64;
a : array[1..100000] of longint;
procedure	quicksort(dau, cuoi : longint);
var
tam, chot, trai, phai : longint;
begin
trai := dau;
phai := cuoi;
chot := a[dau + random(cuoi-dau+1)];
repeat
while a[trai] > chot do	inc(trai);
while chot > a[phai] do dec(phai);
if trai <= phai then
begin
tam := a[trai]; a[trai] := a[phai]; a[phai] := tam;
inc(trai); dec(phai);
end;
until trai >= phai;
if trai < cuoi then quicksort(trai, cuoi);
if dau < phai then quicksort(dau , phai);
end;
procedure	process;
var
i : longint;
begin
readln(fi, n, k);
for i := 1 to n do
read(fi, a[i]);
quicksort(2,n); // sap xep tang;
gt := a[1];
for i := 2 to n do
begin
if k > 0 then
begin
gt := gt + a[i];
dec(k);
end
else
gt := gt - a[i];
end;
writeln(fo, gt);
end;
BEGIN
assign(fi, finp);	reset(fi);
assign(fo, fout);	rewrite(fo);
process;
close(fi);
close(fo);
END.



