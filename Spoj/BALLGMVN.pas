const   fi='';
        nmax=3000;
type    data=longint;
var
        f:text;
        idd,xd,yd,idx,xx,yx,idnew:array[0..nmax+1] of data;
        xynew:array[0..nmax+1] of real;
 
        n:data;
 
procedure docfile;
var     i,j:data;
begin
        assign(f,fi); reset(f);
        readln(f,n);
        for i:=1 to n do
                begin
                        readln(f,xx[i],yx[i]);
                        idx[i]:=i;
                end;
        for i:=1 to n do
                begin
                        readln(f,xd[i],yd[i]);
                        idd[i]:=n+i;
                end;
        close(f);
end;
 
procedure Swap(var a,b:data);
var     z:data;
begin
        z:=a;
        a:=b;
        b:=z;
end;
 
procedure sort(l,r: longint);
      var
         i,j: longint;
         x,y:real;
      begin
         i:=l;
         j:=r;
         x:=xynew[(l+r) div 2];
         repeat
           while xynew[i]<x do inc(i);
           while x<xynew[j] do dec(j);
           if not(i>j) then
             begin
                y:=xynew[i];
                xynew[i]:=xynew[j];
                xynew[j]:=y;
                swap(idnew[i],idnew[j]);
                inc(i);
 
                j:=j-1;
             end;
         until i>j;
         if l<j then
           sort(l,j);
         if i<r then
           sort(i,r);
      end;
 
procedure xuli;
var     i,j,u,v:data;
begin
        // N vien bi xanh lam goc
        for i:=1 to n do
                begin
                        for j:=1 to n do
                                begin
                                        u:=xx[i]-xd[j];
                                        v:=yx[i]-yd[j];
                                        idnew[j]:=idd[j];
                                        if v=0 then
                                                xynew[j]:=high(data)
                                        else
                                                xynew[j]:=u/v;
                                end;
                        sort(1,n);
                        for j:=1 to n-1 do
                                if  xynew[j]=xynew[j+1] then
                                        begin
                                                writeln(idx[i],' ',idnew[j],' ',idnew[j+1]);
                                                readln;
                                                halt;
                                        end;
                end;
 
        // N vien bi do lam goc
        for i:=1 to n do
                begin
                        for j:=1 to n do
                                begin
                                        u:=xd[i]-xx[j];
                                        v:=yd[i]-yx[j];
                                        idnew[j]:=idx[j];
                                        if v=0 then
                                                xynew[j]:=high(data)
                                        else
                                                xynew[j]:=u/v;
                                end;
                        sort(1,n);
                        for j:=1 to n-1 do
                                if  xynew[j]=xynew[j+1] then
                                        begin
                                                writeln(idd[i],' ',idnew[j],' ',idnew[j+1]);
                                                readln;
                                                halt;
                                        end;
                end;
        writeln(-1);
end;
 
begin
        docfile;
        xuli;
end.