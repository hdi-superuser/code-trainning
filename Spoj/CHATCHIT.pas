const   fi='';
        vao:array[1..13] of string
        = (' k ',' ko ',' ng ',' n ',' dc ',' hok ',' ntn ',' kq ','j','w','f','dz','z');
 
        ra:array[1..13] of string
        = (' khong ',' khong ',' nguoi ',' nhieu ',' duoc ',' khong ',' nhu the nao ',' ket qua ','gi','qu','ph','d','d');
 
        nmax=255;
type    data=longint;
var
        S:string;
        f:text;
        i,j,vt:data;
 
begin
        assign(f,fi); reset(f);
        readln(f,s);
        close(f);
        s:=' '+s+' ';
        for i:=1 to 13 do
                begin
                        repeat
                                vt:=pos(vao[i],s);
                                if vt<>0 then
                                        begin
                                                delete(s,vt,length(vao[i]));
                                                insert(ra[i],s,vt);
                                        end;
                        until vt=0;
                end;
        writeln(copy(s,2,length(s)-2));
end.