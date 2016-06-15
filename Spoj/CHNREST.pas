uses math;
const
        nmax    =       100;
        vc      =       100000000000000;
var
        n,m:longint;
        pow:array[0..nmax] of longint;
        F:Array[0..31,0..60000] of int64;
        p:array[0..31] of longint;
        c:array[0..11,0..31] of boolean;
procedure progress;
var i,j,u,v,jj:longint;
check:boolean;
begin
        readln(m,n);
        pow[0]:=1;
        for i:=1 to n do pow[i]:=pow[i-1]*3;
        for i:=1 to m do read(p[i]);
        readln;
        for i:=1 to n do
          begin
            while not seekeoln do
              begin
               read(j);
               c[i][j]:=true;
              end;
            readln;
          end;
        for i:=0 to m do for j:=0 to pow[n]-1 do F[i][j]:=vc;
        F[0][0]:=0;
        for i:=0 to m-1 do for j:=0 to pow[n]-1 do if F[i][j]<vc then
          begin
            F[i+1][j]:=min(F[i+1][j],F[i][j]);
            u:=j;check:=true;
            jj:=j;
            for v:=1 to n do if C[v][i+1] then
              begin
                if u mod 3=2 then
                  begin
                    check:=false;
                    break;
                  end;
                jj:=jj+pow[v-1];
                u:=u div 3;
              end
            else u:=u div 3;
            if check then F[i+1][jj]:=min(F[i+1][jj],F[i][j]+p[i+1]);
          end;
        if F[m][pow[n]-1]=vc then writeln(-1) else
        writeln(F[m][pow[n]-1]);
end;
begin
        assign(input,'');reset(input);
        assign(output,'');rewrite(output);
          progress;
        close(input);
        close(output);
end.

