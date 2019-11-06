#!/bin/bash

#aa= ls -l | grep -v "\->" | nl | awk '{print $1}'

#print $aa

for i in {1..1114};do
    print "$i"
    bb= ls -l | grep -v "\->" | nl| awk '{print $1 " "  $10}' | grep $i | awk '{print $2}'

    print $bb
    [ $i -lt 10 ] && mv $bb 0000000${i}.svg





done





