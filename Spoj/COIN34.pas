const
        COIN    =       34;
        maxm    =       391230;
var
        n, res  :       byte;
        test, i,
        x       :       longint;
        a, t    :       array[0..coin] of longint;
        f       :       array[0..maxm] of byte;
        count   :       array[0..coin] of byte;
 
 
procedure init;
var     i : byte;
begin
        a[1]:= 2; a[2]:= 3; a[3]:= 5;
        for i:= 4 to 34 do
                a[i]:= a[i-1] + a[i-2] + a[i-3];
end;
 
procedure duyet1(i : byte);
var     j : byte;
begin
        for j:= 0 to 1 do
        begin
                t[i]:= t[i-1]; count[i]:= count[i-1];
                if j=1 then
                begin
                        inc(t[i], a[i]); inc(count[i])
                end;
                if i < 20 then
                        duyet1(i+1)
                else    if count[i] > f[t[i]] then
                        f[t[i]]:= count[i]
        end;
end;
 
function max(a, b : byte): byte;
begin
        if a > b then
                max:= a
        else    max:= b
end;
 
procedure duyet2(i : byte);
var     j : byte;
begin
        for j:= 0 to 1 do
        begin
                t[i]:= t[i-1]; count[i]:= count[i-1];
                if j=1 then
                begin
                        inc(t[i], a[i]); inc(count[i]);
                end;
                if i < coin then
                        duyet2(i+1)
                else    if (x - t[i] >= 0) and (x - t[i] <= maxm) then
                        if ((x - t[i] > 0) and (f[x - t[i]] <> 0))
                           or (x - t[i] = 0) then
                                res:= max(res, f[x-t[i]] + count[i])
        end
end;
 
 
begin
        init;
        duyet1(1);
        readln(test);
        t[20]:= 0; count[20]:= 0;
        for i:= 1 to test do
        begin
                readln(x);
                res:= 0;
                if x <= maxm then
                        res:= max(res, f[x]);
                duyet2(21);
                if res=0 then
                        writeln('Case #', i, ': -1')
                else    writeln('Case #', i, ': ', res)
        end;
readln
end.