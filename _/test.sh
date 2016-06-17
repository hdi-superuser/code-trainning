#!/bin/bash

n=0; x=0;
for ((c = 1; ; c++)) do
  if (! find game.$c.in > /dev/null); then break; fi
  let "x = x + 1";
  timeout 1s ./duy < game.$c.in > output_.out
  timeout 1s ./testt < game.$c.in > output.out
  if diff -w output_.out output.out > /dev/null ; then let "n = n + 1"; fi
done
echo $1 $2 $n $x >> /home/whoami/Desktop/ranklist.txt
