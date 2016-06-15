// BALLGAME
label 1;
const max=100000;
      na:array['A'..'B'] of string=('her','his');
type new=
     record
           o,time:longint;
     end;
     nem=
     record
           w:char;
           u,v:longint;
     end;
     list=array[1..max] of nem;
var m,n,i:longint;
    t,x,y,l:longint;
    r:longint;
    f:array[1..max shl 2+1] of 0..2;
    h:array[1..max] of new;
    a:list;
    c:array['A'..'B'] of longint;
    res:array[1..max] of longint;
function FMax(x,y:longint):longint;
         begin
              if x>y then FMax:=x else FMax:=y;
         end;
function FMin(x,y:longint):longint;
         begin
              if x<y then FMin:=x else FMin:=y;
         end;
procedure Push(o,time:longint);
          label 1;
          var r,c:longint;
              tmp:new;
          begin
               inc(l);
               h[l].o:=o;
               h[l].time:=time;
               c:=l;
               tmp:=h[l];
               while c>1 do
                     begin
                          r:=c shr 1;
                          if h[r].time<=tmp.time then goto 1;
                          h[c]:=h[r];
                          c:=r;
                     end;
               1:
               h[c]:=tmp;
          end;
procedure Down;
          label 1;
          var r,c:longint;
              tmp:new;
          begin
               tmp:=h[1];
               r:=1;
               while r shl 1<=l do
                     begin
                          c:=r shl 1;
                          if c<l then
                             if h[c].time>h[c+1].time then inc(c);
                          if h[c].time>=tmp.time then goto 1;
                          h[r]:=h[c];
                          r:=c;
                     end;
               1:
               h[r]:=tmp;
          end;
function GetLeft(p,l,r,x:longint):longint;
         var m,c,con:longint;
         begin
              GetLeft:=0;
              if x<l then exit;
              if f[p]=2 then
                 begin
                      GetLeft:=FMin(x,r);exit;
                 end;
              if f[p]=0 then
                 begin
                      GetLeft:=0;exit;
                 end;
              con:=p shl 1;
              m:=(l+r)shr 1;
              c:=GetLeft(con+1,m+1,r,x);
              if c=0 then c:=GetLeft(con,l,m,x);
              GetLeft:=c;
         end;
function GetRight(p,l,r,x:longint):longint;
         var m,c,con:longint;
         begin
              GetRight:=0;
              if x>r then exit;
              if f[p]=2 then
                 begin
                      GetRight:=FMax(x,l);exit;
                 end;
              if f[p]=0 then
                 begin
                      GetRight:=0;exit;
                 end;
              m:=(l+r)shr 1;
              con:=p shl 1;
              c:=GetRight(con,l,m,x);
              if c=0 then c:=GetRight(con+1,m+1,r,x);
              GetRight:=c;
         end;
procedure Up(p,l,r,x:longint);
          var m,c:longint;
          begin
               if x<l then exit;
               if x>r then exit;
               if l=r then
                  begin
                       f[p]:=2;exit;
                  end;
               m:=(l+r)shr 1;
               c:=p shl 1;
               if f[p]=0 then
                  begin
                       f[p shl 1]:=0;
                       f[p shl 1+1]:=0;
                       f[p]:=1;
                  end;
               Up(c,l,m,x);Up(c+1,m+1,r,x);
               if (f[c]=2)and(f[c+1]=2) then f[p]:=2;
          end;
procedure Del(p,l,r,x:longint);
          var m,c:longint;
          begin
               if x<l then exit;
               if x>r then exit;
               if l=r then
                  begin
                       f[p]:=0;exit;
                  end;
               m:=(l+r)shr 1;
               c:=p shl 1;
               if f[p]=2 then
                  begin
                       f[c]:=2;
                       f[c+1]:=2;
                       f[p]:=1;
                  end;
               Del(c,l,m,x);Del(c+1,m+1,r,x);
               if (f[c]=0)and(f[c+1]=0) then f[p]:=0;
          end;
procedure Sort(l,r:longint;var a:list);
          var i,j,x:longint;
              y:nem;
          begin
               i:=l;j:=r;x:=a[(l+r)shr 1].u;
               repeat
                     while a[i].u<x do inc(i);
                     while x<a[j].u do dec(j);
                     if i<=j then
                        begin
                             y:=a[i];a[i]:=a[j];a[j]:=y;
                             inc(i);dec(j);
                        end;
               until i>j;
               if l<j then Sort(l,j,a);
               if i<r then Sort(i,r,a);
          end;
 
begin
readln(n,m);
f[1]:=2;
for i:=1 to m do readln(a[i].w,a[i].u,a[i].v);
Sort(1,m,a);
for i:=1 to m do
    begin
         inc(c[a[i].w]);
         t:=a[i].u;
         repeat
               if l=0 then goto 1;
               if t<h[1].time then goto 1;
               r:=h[1].o;
               h[1]:=h[l];dec(l);
               Down;
               Up(1,1,n,r);
         until false;
         1:
         case a[i].w of
              'A':r:=GetRight(1,1,n,1);
              'B':r:=GetLeft(1,1,n,n);
         end;
         if r=0 then
            begin
                 if a[i].w='A' then write('Alice ')
                 else write('Bob ');
                 writeln('loses at ',na[a[i].w],' turn: ',c[a[i].w]);
                 writeln('Game lasts: ',t,' minute(s)');
                 exit;
            end;
         res[i]:=r;
         Push(r,a[i].u+a[i].v);
         Del(1,1,n,r);
    end;
writeln('DRAW');
while l>1 do
      begin
           h[1]:=h[l];dec(l);Down;
      end;
writeln('Game lasts: ',h[1].time,' minute(s)');
for i:=1 to m do
    begin
         if a[i].w='A' then write('Alice ')
         else write('Bob ');
         writeln('takes the hole: ',res[i]);
    end;
end.