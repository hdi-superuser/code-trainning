{$MODE OBJFPC}
program DiophanteEquation;
const
  InputFile  = 'DIOPHANTE.INP';
  OutputFile = 'DIOPHANTE.OUT';
var
  fi, fo: TextFile;
  a, b, c: Int64;
  d, m, n, r, xm, xn, xr, p, q, maxx, res: Int64;
begin
  AssignFile(fi, InputFile); Reset(fi);
  AssignFile(fo, OutputFile); Rewrite(fo);

  ReadLn(fi, a, b, c);
  m := a; xm := 1;
  n := b; xn := 0;
  while n <> 0 do
    begin
      q := m div n;
      r := m mod n;
      xr := xm - q * xn;
      m := n; xm := xn;
      n := r; xn := xr;
    end;
  d := m;
  if c mod d <> 0 then res := 0
  else
    begin
      p := b div d;
      xm := xm * (c div d);
      xm := (xm mod p + p) mod p;
      maxx := (c - b) div a;
      if maxx < xm then res := 0
      else
        begin
          res := (maxx - xm) div p + 1;
          if xm = 0 then Dec(res);
        end;
    end;
  WriteLn(fo, res);

  CloseFile(fi); CloseFile(fo);
end.

