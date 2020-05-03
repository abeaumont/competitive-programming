#!/bin/bash
wget -q https://contest.tuenti.net/resources/2020/resources/img/05-headache.png
strings 05-headache.png |tail -1 > 8.bf
bfc 8.bf
./a.out |cut -d" " -f 4
