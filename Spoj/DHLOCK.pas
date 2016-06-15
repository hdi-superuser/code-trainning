Const fin='';
      fon='';
      maxN = trunc(3e2);
Var N,k,kq: LongInt;
    S,A,B: array [1..maxN] of LongInt;
    fi,fo: text;
Procedure nhap;
    Var i: LongInt;
    Begin
        Assign(fi,fin); Reset(fi);
        Assign(fo,fon); Rewrite(fo);
            readln(fi,N,k);
            For i:=1 to N do read(fi,S[i]);
            For i:=1 to N do read(fi,A[i]);
    End;
Function min(x,y: LongInt): LongInt;
    Begin
        IF x > y then x:=y;
        min:=x;
    End;
Function cal: LongInt;
    Var i,j,w,sum: LongInt;
    Begin
        cal:=high(LongInt);
        For i:=1 to N do
            Begin
                IF A[i] >= S[i] then sum:=A[i]-S[i]
                ELSE sum:=k-(S[i]-A[i])+1;
                w:=sum;
                For j:=1 to N do
                    Begin
                        B[j]:=S[j]+sum;
                        IF B[j] > k then dec(B[j],k+1);
                    End;
                For j:=1 to N do
                    IF A[j] >= B[j] then inc(w,A[j]-B[j])
                    ELSE inc(w,k-(B[j]-A[j])+1);
                cal:=min(cal,w);
            End;
    End;
Procedure xuly;
    Var i,j,x,count: LongInt;
    Begin
        kq:=high(LongInt); count:=0;
        For i:=1 to N do
            Begin
                kq:=min(kq,count+cal);
                inc(count); x:=S[N];
                For j:=N downto 2 do S[j]:=S[j-1];
                S[1]:=x;
            End;
        writeln(fo,kq);
        Close(fi);
        Close(fo);
    End;
Begin
    nhap;
    xuly;
End.