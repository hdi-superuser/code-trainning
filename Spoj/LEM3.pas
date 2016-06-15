program LEM3;
const
        MaxN    =       16;
        maxS    =       1 shl maxN-1;
        maxC    =       200000;
var
        n       :       byte;
        a       :       array[1..maxN, 1..maxN] of integer;
        t       :       array[0..maxS, 0..maxN] of longint;
 
procedure Enter;
var     fi : text;
        i,j: integer;
begin
        assign(fi, ''); reset(fi);
        readln(fi, n);
        for j:= 1 to n do
        begin
                for i:= 1 to n do
                        read(fi, a[i,j]);
                readln(fi);
        end;    close(fi)
end;
 
function getBit(a: word; i : byte): byte;
begin
        getBit := (a shr i) and 1;
end;
 
function turnoff(a : word; i : byte): word;
begin
        turnoff:= a and not (1 shl i);
end;
 
procedure Optimize;
var     u, i, j, k : byte; kq : longint;
        s, p, first, last: word;
        b : array[0..maxN] of byte;
begin
        first:= 1; last:= 1 shl n - 1;
        for u:= 1 to n do
        begin
                for s:= 0 to last do
                        t[s, u]:= maxC;
                t[1 shl (u-1), u]:= 0;
        end;
        for s:= first to last do
        begin
                fillchar(b, sizeof(b), 0);
                k:= 0;
                for i:= 1 to n do
                if getBit(s, i-1)=1 then
                begin
                        inc(k);
                        b[k]:= i;
                end;
                for i:= 1 to k do
                begin
                        u:= b[i];
                        p:= turnoff(s, b[i]-1);
                        for j:= 1 to k do
                        if (i<>j) and
                        (t[p, b[j]] + a[b[j], u] < t[s, u]) then
                        t[s, u]:= t[p, b[j]] + a[b[j], u];
                end;
        end;
        kq:= t[last, 1];
        for u:= 2 to n do
                if t[last, u] < kq then
                        kq:= t[last, u];
        write(kq);
end;
 
 
BEGIN
        Enter;
        Optimize;
readln
END.