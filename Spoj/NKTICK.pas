Program NKTICK;
Uses math;
Const
        fi='';
        fo='';
Var
        g,f : Text;
        T,R,Fx : Array[0..60000] of LongInt;
        N,i,j : LongInt;
 
Procedure DocFile;
        Begin
                Assign(f,fi); Reset(f);
                Readln(f,N);
                For i:=1 to N do Read(f,T[i]);
                For i:=1 to N-1 do Read(f,R[i]);
                Close(f);
        End;
 
Procedure XuLy;
        Begin
                Fx[1]:=T[1];
                Fx[0]:=0;
                For i:=2 to N do
                        Fx[i]:=min(Fx[i-1]+T[i],Fx[i-2]+R[i-1]);
        End;
 
Procedure GhiFile;
        Begin
                Assign(g,fo); Rewrite(g); Write(g,Fx[N]); Close(g);
        End;
 
Begin
        DocFile;
        XuLy;
        GhiFile;
End.