Const fi='';
      fo='';

Type ma=array[1..3] of longint;
     ma1=array[1..10000] of real;

Var        n: LongInt;
           Tien: Double;
           A:array[1..10001] of ma ;
           f:Text;

Procedure doi(i, j : longint) ;
Var
     tg : Ma;
Begin
     tg :=a[i]; a[i]:=a[j]; a[j]:=tg;
End ;

Function value(i: longint ):Real;
Begin
     value:=a[i,1]/a[i,2] ;
End ;

Procedure Quicksort( l , r : Integer ) ;
Var
     i , j : longint;
     Key   : Real;
Begin
     If l >= r then Exit ;
     Key := value( l + Random(r-l+1) ) ;
     i := l ; j := r ;
     While i < j do Begin
           While value(i) > Key do Inc(i) ;
           While value(j) < Key do Dec(j) ;
           If i <= j then Begin
              If i < j then doi( i , j ) ;
              Inc(i) ; Dec(j) ;
           End ;
     End ;
     Quicksort(l,j) ; Quicksort(i,r) ;
End ;

Procedure Init ;
Var
     i : longint;
Begin
     For i := 1 to n do A[i,3] := i ;
     Quicksort(1,n) ;
End ;

Procedure Process ;
Var
     i ,bd,kt : longint ;
     S: real  ;
Begin
     S := 0;
     For i := 1 to n do S := S + A[i,1] ;
     For i := 1 to n do Begin
         Tien := Tien + S * A[i,2] ;
         S := S - A[i,1] ;
     End ;
End ;

Procedure KetQua ;
Var
     i : Integer ;
Begin
     Assign(f,fo) ;
     Rewrite(f)    ;
     Writeln(f,Tien:0:0) ;
     For i := 1 to n do Write(f,A[i,3],' ') ;
     Close(f)      ;
End ;

Procedure Nhapdl ;
Var
     i : Integer   ;
Begin
     Assign(f,fi) ;
     Reset(f)      ;
     Readln(f,n)   ;
     For i := 1 to n do Read(f,A[i,1]) ;
     For i := 1 to n do Read(f,A[i,2]) ;
     Close(f)      ;
End ;

BEGIN
     Nhapdl ;
     Init   ;
     Process;
     KetQua ;
END.
