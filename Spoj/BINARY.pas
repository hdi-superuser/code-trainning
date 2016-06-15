program binary;
const maxn = 33;
var f : array[-1..maxn , -1 .. maxn ] of int64;
n , k , l , kq : int64;
s : string;
{--------------------------------------------------------------------------}
procedure khoitao;
var i , j , kk : longint;
begin
        fillchar ( f , sizeof ( f ) , 0 );
        f[1 , 1] := 1;
        f[1 , 0] := 1;
        f[0 , 0] := 1;
        for i := 2 to maxn do
                begin
                        f[i , 0] := 1;
                        f[i , i] := 1;
                        for j := 1 to i do
                                f[i , j] := f[i - 1 , j] + f[i - 1 , j - 1];
                end;

end;
{--------------------------------------------------------------------------}
procedure nhap;
begin
        readln ( n , k );
        s := binstr ( n , 32 );
        while ( length ( s ) > 1 ) and ( s[1] = '0' ) do delete ( s , 1 , 1);
        l := length ( s );
end;
{--------------------------------------------------------------------------}
procedure xuli;
var i , dem : longint;
begin
        kq := 0;
        if k = 1 then inc ( kq );
        for i :=  1 to l - 1 do
                kq := kq + f[ i - 1 , k];
        for i := 2 to l do
                begin
                        if s[i] = '1' then kq := kq + f[l - i , k - 1]
                        else dec ( k );
                end;
        if k = 0 then inc ( kq );
end;
{--------------------------------------------------------------------------}
procedure xuat;
begin
        writeln ( kq );
end;
{--------------------------------------------------------------------------}
begin
        khoitao;
        while not eof do
                begin
                        nhap;
                        if k > l then
                                begin
                                        writeln ( 0 );
                                        continue;
                                end;
                        xuli;
                        xuat;
                end;
end.

