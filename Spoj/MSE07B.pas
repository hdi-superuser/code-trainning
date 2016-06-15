
const   fi='';
        nmax=10000000;
type    data=longint;
        data1=record
                gt,vt:data;
        end;
 
var
        f:text;
        Heapmin,Heapmax:array[0..nmax+1] of data1;
        posmin,posmax:array[0..nmax+1] of data;
        nheapmin,nheapmax:data;
 
procedure swap(var a,b:data1);
var     c:data1;
begin
        c:=a;
        a:=b;
        b:=c;
end;
 
procedure upheapmin(i:data);
var     j:data;
begin
        if (i=1) or (heapmin[i].gt>=heapmin[i div 2].gt) then exit;
 
        posmin[heapmin[i].gt]:=i div 2;
        posmin[heapmin[i div 2].gt]:=i;
 
        swap(heapmin[i],heapmin[i div 2]);
        upheapmin(i div 2);
end;
 
procedure upheapmax(i:data);
begin
        if (i=1) or (heapmax[i].gt<=heapmax[i div 2].gt) then exit;
        posmax[heapmax[i].gt]:=i div 2;
        posmax[heapmax[i div 2].gt]:=i;
        swap(heapmax[i],heapmax[i div 2]);
        upheapmax(i div 2);
end;
 
procedure downheapmin(i:data);
var     j:data;
begin
        j:=i*2;
        if j>nheapmin then exit;
        if (j<nheapmin) and (heapmin[j+1].gt<heapmin[j].gt) then inc(j);
        if Heapmin[j].gt>=heapmin[i].gt then exit;
        posmin[heapmin[i].gt]:=j;
        posmin[heapmin[j].gt]:=i;
        swap(heapmin[i],heapmin[j]);
        downheapmin(j);
end;
 
 
procedure downheapmax(i:data);
var     j:data;
begin
        j:=i*2;
        if j>nheapmax then exit;
        if (j<nheapmax) and (heapmax[j+1].gt>heapmax[j].gt) then inc(j);
        if Heapmax[j].gt<=heapmax[i].gt then exit;
        posmax[heapmax[i].gt]:=j;
        posmax[heapmax[j].gt]:=i;
        swap(heapmax[i],heapmax[j]);
        downheapmax(j);
end;
 
 
procedure add(k,p:data);
begin
        inc(nheapmin);
        heapmin[nheapmin].gt:=p;
        heapmin[nheapmin].vt:=k;
        posmin [p]:=nheapmin;
 
        inc(nheapmax);
        heapmax[nheapmax].gt:=p;
        heapmax[nheapmax].vt:=k;
 
        posmax [p]:=nheapmax;
 
        upheapmax(nheapmax);
        upheapmin(nheapmin);
end;
 
function popmax(v:data):data1;
begin
        popmax:=heapmax[v];
        heapmax[v]:=heapmax[nheapmax];
        dec(nheapmax);
        posmax[heapmax[v].gt]:=v;
        upheapmax(v);
        downheapmax(v);
end;
 
Function PopMin (v : LongInt) : data1;
         Begin
              PopMin:=HeapMin[v];
              HeapMin[v]:=HeapMin[nHeapmin];
              dec(nHeapmin);
              PosMin[Heapmin[v].gt]:=v;
              UpheapMin(v);
              DownheapMin(v);
         end;
 
 
procedure docfile;
var     i,j,q,k,p:data;
        tmp:data1;
begin
        assign(f,fi); reset(f);
        nheapmin:=0;
        nheapmax:=0;
        repeat
                read(f,q);
                if q=0 then break;
                if q=1 then
                        begin
                                read(f,k,p);
                                add(k,p);
                        end
                else
                        if q=2 then
                                begin
                                        if nheapmax=0 then
                                                writeln(0)
                                        else
                                                begin
                                                        tmp:=popmax(1);
                                                        writeln(tmp.vt);
                                                        popmin(posmin[tmp.gt]);
                                                end;
                                end
                        else
                                begin
                                        if nheapmin=0 then
                                                writeln(0)
                                        else
                                                begin
                                                        tmp:=popmin(1);
                                                        writeln(tmp.vt);
                                                        popmax(posmax[tmp.gt]);
 
 
                                                end;
                                end;
        until false;
        close(f);
end;
 
begin
        docfile;
end.