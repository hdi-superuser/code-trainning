{$MODE OBJFPC}
program CountMod;
const
  InputFile  = 'COUNTMOD.INP';
  OutputFile = 'COUNTMOD.OUT';
var
  fi, fo: TextFile;
  a, b: array[1..4] of Int64;

procedure Enter;
var
  i: Integer;
begin
  for i := 1 to 3 do
    ReadLn(fi, a[i], b[i]);
end;

function MulMod(a, b, m: Int64): Int64;
var
  t: Int64;
begin
  if b < 0 then
    begin
      a := -a; b := -b;
    end;
  if b = 0 then Exit(0);
  t := MulMod(a, b div 2, m);
  if Odd(b) then
    Result := (2 * t + a) mod m
  else
    Result := 2 * t mod m;
end;

procedure SolveDiophante(a, b, c: Int64; var lcm, x: Int64);
var
  m, n, r, q, xm, xn, xr, t: Int64;
begin
  m := a; xm := 1;
  n := b; xn := 0;
  while n <> 0 do
    begin
      q := m div n;
      r := m - q * n;
      xr := xm - q * xn;
      m := n; xm := xn;
      n := r; xn := xr;
    end;
  t := c div m;
  x := MulMod(xm, t, b div m);
  lcm := Abs(a div m * b);
end;

//x mod a = b; x mod c = d

procedure Solve2(a, b, c, d: int64; var m, x: Int64);
var
  y: Int64;
begin
  SolveDiophante(a, -c, d - b, m, y);
  x := (MulMod(a, y, m) + b) mod m;
end;

procedure Solve3;
var
  x, m: Int64;
begin
  Solve2(a[1], b[1], a[2], b[2], a[4], b[4]);
  Solve2(a[3], b[3], a[4], b[4], m, x);
  x := ((x mod m) + m) mod m;
  WriteLn(fo, x);
end;

begin
  AssignFile(fi, InputFile); Reset(fi);
  AssignFile(fo, OutputFile); Rewrite(fo);
  try
    Enter;
    Solve3;
  finally
    CloseFile(fi); CloseFile(fo);
  end;
end.

