#!/bin/bash

MAXCOUNT=150
count=1

echo
echo "150 случайных чисел:"
echo "-----------------"
while [ "$count" -le $MAXCOUNT ]      
do
  number=$RANDOM
  echo $number >> numbers.txt
  let "count += 1"  # Нарастить счетчик.
done
echo "-----------------"
