#!/bin/bash

n=0; x=0;
for ((c = 1; c < 2; c++)) do
  if (! find D.in > /dev/null); then break; fi
  let "x = x + 1";
  timeout 3s ./table < D.in > output_.out
  if diff -w output_.out D.out > /dev/null ; then let "n = n + 1"; fi
done
echo $1 $2 $n $x >> /home/whoami/Desktop/ranklist.txt
