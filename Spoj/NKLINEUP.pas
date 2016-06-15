Uses    Math;
Const   Fi      =       '';//'NKLINEUP.INP';
        Fo      =       '';//'NKLINEUP.OUT';
        MaxN    =       50000;
        Base    =       Round(1E6);
        Beta    =       1;
Type    List    =       Array[Beta..MaxN] of Longint;
        Tree    =       Array[Beta..MaxN*4] of Longint;
Var     F, G    :       Text;
        N, Q, I :       Longint;
        A, B    :       Longint;
        Leaf    :       List;
        Key     :       List;
        L, H    :       Tree;
        TMax    :       Tree;
        TMin    :       Tree;
Procedure       Init;
        Begin
                For i:=Beta to 4*n do
                        Begin
                                TMax[i]:= 1;
                                TMin[i]:= Base;
                        End;
        End;
Procedure       Build(x, low, high: Longint);
        Var     Mid     :       Longint;
        Begin
                L[x]:= Low;     H[x]:= High;
                If Low=High Then
                        Begin
                                Leaf[Low]:=X;
                                TMax[x]:= Key[Low];
                                TMin[x]:= Key[Low];
                        End
                Else
                        Begin
                                Mid:= (High+Low) Div 2;
                                Build(2*x, Low, Mid);
                                Build(2*x+1, Mid+1, High);
                                TMax[x]:= Max(TMax[x], Max(TMax[2*x], TMax[2*x+1]));
                                TMin[x]:= Min(TMin[x], Min(TMin[2*x], TMin[2*x+1]));
                        End;
        End;
Function        GetHigh(A, B: Longint): Longint;
        Function        GetMax(X, Y: Longint): Longint;
                Function        RequestMax(Z: Longint): Longint;
                        Var     Res     :       Longint;
                        Begin
                                Res:= Beta;
                                If (L[z]>y) or (H[z]<x) Then Exit(Res);
                                If (L[z]>=x) and (H[z]<=y) Then Exit(Max(Res, TMax[z]));
                                Exit(Max(RequestMax(2*z), RequestMax(2*z+1)));
                        End;
                Begin
                        Exit(RequestMax(1));
                End;
        Function        GetMin(M, N: Longint): Longint;
                Function        RequestMin(K: Longint): Longint;
                        Var     Res     :       Longint;
                        Begin
                                Res:= Base;
                                If (L[k]>n) or (H[k]<m) Then Exit(Res);
                                If (L[k]>=m) And (H[k]<=n) Then Exit(Min(Res, TMin[k]));
                                Exit(Min(RequestMin(2*k), RequestMin(2*k+1)));
                        End;
                Begin
                        Exit(RequestMin(1));
                End;
        Begin
                Exit(GetMax(A, B)-GetMin(A, B));
        End;
BEGIN
        Assign(f, fi);  Assign(g, fo);
        Reset(f);       Rewrite(g);
        Readln(f, n, q);
        For i:=1 to n do Readln(f, Key[i]);
        Init;
        Build(1, 1, N);
        For i:=1 to q do
                Begin
                        Readln(f, A, B);
                        Writeln(g, GetHigh(A, B));
                End;
        Close(f);       Close(g);
END.
