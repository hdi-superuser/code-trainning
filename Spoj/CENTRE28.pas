Const   fi   =   '';
      fo   =   '';
        maxn=   30001;
        vc   =   maxlongint div 2;
Type   pter=   ^pt;
      pt   =   record u,c:longint; link:pter; end;
Var    f,f2:   text;
      a   :   array[1..maxn]of pter;
        d,h,r,heap,pos   :   array[1..maxn]of longint;
        kq,ok         :   array[1..maxn]of boolean;
        n,nh         :   longint;
Procedure inp;
  var u,v,c,i,m:longint; last:pter;
  begin
    assign(f,fi); reset(f);
    assign(f2,fo); rewrite(f2);
    read(f,n,m);
    for i:=1 to m do
      begin
        read(f,u,v,c);
        last:=a[u]; new(a[u]);
        a[u]^.u:=v; a[u]^.c:=c; a[u]^.link:=last;
        last:=a[v]; new(a[v]);
        a[v]^.u:=u; a[v]^.c:=c; a[v]^.link:=last;
      end;
    close(f);
  end;
Procedure truyvet(u:longint);
  var v,c:longint; x:pter;
  begin
    ok[u]:=true; x:=a[u];
    while x<>nil do
      begin
        v:=x^.u; c:=x^.c; x:=x^.link;
        if ok[v] then continue;
        if d[v]+c=d[u] then truyvet(v);
      end;
  end;
Function pop:longint;
  var i,v,c:longint;
  begin
    pop:=heap[1];
    heap[1]:=heap[nh]; dec(nh);
    v:=heap[1]; pos[v]:=1; i:=1;
    while i*2<=nh do
      begin
        c:=i*2;
        if (c<nh)and(d[heap[c]]>d[heap[c+1]]) then inc(c);
        if d[heap[c]]>=d[v] then break;
        heap[i]:=heap[c]; pos[heap[i]]:=i;
       i:=c;
      end;
    heap[i]:=v; pos[v]:=i;
  end;
Procedure up(u:longint);
  var v,c:longint;
  begin
    c:=heap[u];
    while u>1 do
      begin
        v:=u div 2;
        if d[heap[v]]<=d[c] then break;
        heap[u]:=heap[v]; pos[heap[u]]:=u;
        u:=v;
      end;
    heap[u]:=c; pos[c]:=u;
  end;
Procedure ijk;
  var i,u,v,c,min:longint; x:pter;
  begin
    for i:=2 to n do d[i]:=vc;
    for i:=1 to n do begin heap[i]:=i; pos[i]:=i; end;
    nh:=n;
    repeat
      u:=pop;
      if d[u]=vc then exit;
      x:=a[u];
      while x<>nil do
        begin
          v:=x^.u; c:=x^.c; x:=x^.link;
          if d[v]=d[u]+c then inc(h[v]) else
          if d[v]>d[u]+c then
            begin
              h[v]:=1;
              d[v]:=d[u]+c;
              up(pos[v]);
            end;
        end;
    until nh=0;
  end;
Procedure solve;
  var w,t,i,u,v,sod,c,m,divo,dira:longint; x:pter;
  begin
    fillchar(kq,sizeof(kq),true);
    sod:=0; r[1]:=1; w:=1; t:=1;
    while t<=w do
      begin
        u:=r[t]; inc(t);
        x:=a[u]; divo:=0; dira:=0;
        while x<>nil do
          begin
            v:=x^.u; c:=x^.c; x:=x^.link;
            if (d[v]=d[u]+c)and ok[v] then
           begin
             dec(h[v]);
                if (h[v]=0) and ok[v] then begin inc(w); r[w]:=v; end;
                inc(dira);
              end;
            if d[u]=d[v]+c then inc(divo);
          end;
        if sod=divo then kq[u]:=false;
        sod:=sod-divo+dira;
      end;
    m:=0;
    for i:=2 to n-1 do if kq[i] then inc(m);
    writeln(f2,m);
    for i:=2 to n-1 do if kq[i] then writeln(f2,i);
    close(f2);
  end;
Begin
  inp;
  ijk;
  truyvet(n);
  solve;
End. 