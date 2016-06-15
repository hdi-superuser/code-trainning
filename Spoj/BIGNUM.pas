const   base = 10000;
        max  = 500  ;
        lt   = 4    ;
 
type    bignum = record
                l : longint;
                r : array[1..max] of longint;
        end;
 
var     a,b     : ansistring;
        x,y,key : bignum;
 
 
procedure Creat(var s : ansistring;var x : bignum);
 var    i,l : longint;
        o   : integer;
        t   : ansistring;
 begin
        l := length(s);
        t := '';
        for i := l downto 1 do begin
                t := s[i]+t;
                if length(t) = lt then begin
                        inc(x.l);
                        val(t,x.r[x.l],o);
                        t := '';
                end;
        end;
        if t <> '' then begin
                inc(x.l);
                val(t,x.r[x.l],o);
        end;
 end;
 
function fmax(x,y : longint) : longint;
 begin
        if x > y then exit(x);
        exit(y);
 end;
 
procedure Refresh(var x : bignum);
 var    i : longint;
 begin
        for i := 1 to x.l do x.r[i] := 0;
        x.l := 0;
 end;
 
procedure Cong(var x,y,key : bignum);
 var    i : longint;
 begin
        Refresh(key);
        key.l := fmax(x.l,y.l);
        for i := 1 to key.l do begin
                inc(key.r[i],x.r[i]+y.r[i]);
                if key.r[i] >= base then begin
                        key.r[i+1] := 1;
                        key.r[i] := key.r[i]-base;
                end;
        end;
        if key.r[key.l+1] > 0 then inc(key.l);
 end;
 
function More(var x,y : bignum) : boolean;
 var    i : longint;
 begin
        if x.l = y.l then begin
                for i := x.l downto 1 do
                        if x.r[i] <> y.r[i] then begin
                                More := x.r[i] > y.r[i];
                                exit;
                        end;
                More := true;
        end
        else
                More := x.l>y.l;
 end;
 
procedure Tru(var x,y,key : bignum);
 var    i : longint;
 begin
        Refresh(key);
        key.l := fmax(x.l,y.l);
        for i := 1 to key.l do
                if x.r[i] >= key.r[i]+y.r[i] then
                        key.r[i]:=x.r[i]-y.r[i]-key.r[i]
                else begin
                        inc(key.r[i+1]);
                        key.r[i]:=x.r[i]+base-y.r[i]-key.r[i];
                end;
        while (key.r[key.l]=0) and (key.l>1) do dec(key.l);
 end;
 
procedure Print(var key : bignum);
 var i:longint;
 
 procedure PrintInt(var x : longint);
  begin
        case x of
                0..9       : write('000',x);
                10..99     : write('00' ,x);
                100..999   : write('0'  ,x);
                1000..9999 : write(      x);
        end;
  end;
 
 begin
        write(key.r[key.l]);
        for i := key.l-1 downto 1 do
                PrintInt(key.r[i]);
        writeln;
 end;
 
procedure Nhan(var x,y,key : bignum);
 var    i,j,k : longint;
 begin
        Refresh(key);
        key.l := x.l+y.l-1;
        k := 0;
        for i := 1 to x.l do begin
                for j := 1 to y.l do begin
                        k := x.r[i]*y.r[j]+key.r[i+j-1];
                        inc(key.r[i+j],k div base);
                        key.r[i+j-1] := k mod base;
                end;
        end;
        if key.r[key.l+1] > 0 then inc(key.l);
 end;
 
 
BEGIN
        readln(a);
        readln(b);
 
        Creat(a,x);
        Creat(b,y);
 
        Cong(x,y,key);
        Print(key);
 
        if More(x,y) then Tru(x,y,key)
        else begin
                write('-');
                Tru(y,x,key);
        end;
        Print(key);
 
        Nhan(x,y,key);
        Print(key);
END.