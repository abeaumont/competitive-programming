#!/bin/bash
for i in {9..15}
do
  ./14.py > 14-output-$i &
  sleep 0.1
done
