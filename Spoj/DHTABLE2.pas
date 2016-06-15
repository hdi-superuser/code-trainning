Const   Fi='';
        Fo='';
Var     FF: Text;
        Pos,N,t: Qword;
        M10:array[0..18] of qword;
        Res:ansistring;
        V,F:array[0..20] of qword;
Function EXP(A,k:longint):qword;
        Var     S:qword;
                i:longint;
        Begin
                S:=1;
                For i:=1 to k do S:=S*A;
                Exit(S);
        End;
Procedure GenArray;
        Var     i:longint;
        Begin
                M10[0] := 1;
                For i:=1 to 18 do M10[i]:=M10[i-1]*10;
                F[1]:=9;
                For i:=2 to 17 do F[i]:=9*M10[i-1]*i;
                For i:=1 to 17 do F[i]:=F[i-1]+F[i];
        End;
Function N2Str(A:qword):ansistring;
        Var     S:ansistring;
        Begin
                Str(A,S);
                Exit(S);
        End;
Procedure       Process;
        Var     i:longint;
                tmp,num:qword;
        Begin
                Res:='';
                If N>=t then
                        Begin
                                i:=1;
                                While length(Res) < t do
                                        Begin
                                                Res:=Res+N2Str(i);
                                                Inc(i);
                                        End;
                                While length(Res) > t do
                                        Delete(Res,length(Res),1);
                                Write(ff,Res);
                                Exit;
                        End;
                GenArray;
                Pos:=t-N+1;
                For i:=1 to 17 do If F[i]>=Pos Then Break;
                Dec(i);
                tmp:=pos-F[i]-1;
                num:=tmp div (i+1);
                num:=num + M10[i];
                Res := N2Str(num);
                if tmp mod (i+1) <> 0 then delete(Res,1,(tmp mod (i+1)));
                tmp := num+1;
                While length(Res) < N do
                        Begin
                                Res:=Res+N2Str(tmp);
                                Inc(tmp);
                        End;
                While length(Res) > N do delete(Res,length(Res),1);
                writeln(ff,Res);
        End;
BEGIN
        Assign(ff,fi);
        Reset(ff);
        Readln(ff,n,t);
        Close(ff);
        Assign(ff,fo);
        Rewrite(ff);
        Process;
        Close(ff);
END.

