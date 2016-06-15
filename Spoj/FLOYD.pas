const   fi='';
        nmax=10000;
        vc=100000;//high(longint);
 
type    data=longint;
var
        f:text;
        n,m,k:data;
        A:array[0..nmax+1,0..nmax+1] of data;
        D:array[0..nmax+1] of data;
        free:array[0..nmax+1] of boolean;
        trace:array[0..nmax+1] of data;
 
        luu:array[0..nmax+1] of data;
        spt:data;
 
procedure dijkstra(s,t:data);
var     i,j,u,v,min:data;
begin
        for i:=1 to n do
                begin
                        free[i]:=true;
                        d[i]:=a[s,i];
                        trace[i]:=s;
                end;
 
        repeat
                min:=vc; u:=0;
                for i:=1 to n do
                        if (free[i]) and (d[i]<min) then
                                begin
                                        min:=d[i];
                                        u:=i;
                                end;
                if (u=0) or (u=t) then break;
 
                free[u]:=false;
 
                for v:=1 to n do
                        begin
                        if (free[v]) and (d[v]>d[u]+a[u,v]) then
                                begin
                                        d[v]:=d[u]+a[u,v];
                                        trace[v]:=u;
                                end;
 
                        end;
        until FALSE;
end;
 
procedure truyvet(v:data);
var     x:data;
        i:data;
begin
        if trace[v]<>0 then
                begin
                        truyvet(trace[v]);
                        inc(spt);
                        luu[spt]:=v;
                end
        else
                begin
                        inc(spt);
                        luu[spt]:=v;
                end;
end;
 
 
procedure docfile;
var     i,j,u,v,c,tl:data;
begin
        assign(f,fi); reset(f);
        readln(f,n,m,k);
        for i:=1 to n do
                for j:=1 to n do
                        if i=j then
                                a[i,j]:=0
                        else
                                a[i,j]:=vc;
        for i:=1 to m do
                begin
                        readln(f,u,v,c);
                        a[u,v]:=c;
                        a[v,u]:=c;
                end;
        for i:=1 to k do
                begin
                        readln(f,tl,u,v);
                        if tl=0 then
                                begin
                                        dijkstra(u,v);
                                        writeln(d[v]);
                                end
                        else
                                begin
                                        dijkstra(u,v);
                                        if u<>v then
                                                begin
                                                        spt:=0;
                                                        trace[u]:=0;
                                                        truyvet(v);
                                                        write(spt,' ');
                                                        for j:=1 to spt do
                                                                write(luu[j],' ');
                                                        writeln;
                                                end
                                        else
                                                writeln('2 ',u,' ',v);
                                end;
                end;
        close(f);
end;
 
begin
        docfile;
        readln;
end.