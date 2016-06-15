Uses    Math;
Const   Fi      =       '';
        Fo      =       '';
        MaxN    =       Trunc(1e5);
Var     Res     :       Int64;
        N, I, J :       Longint;
        A       :       Array[1..MaxN] of Longint;
        F, G    :       Text;
procedure sort(l,r: longint);
      var
         i,j,x,y: longint;
      begin
         i:=l;
         j:=r;
         x:=a[(l+r) div 2];
         repeat
           while a[i]<x do
            inc(i);
           while x<a[j] do
            dec(j);
           if not(i>j) then
             begin
                y:=a[i];
                a[i]:=a[j];
                a[j]:=y;
                inc(i);
                j:=j-1;
             end;
         until i>j;
         if l<j then
           sort(l,j);
         if i<r then
           sort(i,r);
      end;
BEGIN
        Assign(f,fi);   Assign(g,fo);
        Reset(f);       Rewrite(g);
        Readln(f, N);
        For i:=1 to N do Readln(f, A[i]);
        Sort(1,N);
        For i:=1 to n do Inc(Res, A[i]);
        I:=1;   J:=N;
        While Not(i>j) Do
                Begin
                        Inc(Res, A[j]-A[i]);
                        Inc(I); Dec(J);
                End;
        Writeln(g, Res);
        Close(f);       Close(g);
END.


