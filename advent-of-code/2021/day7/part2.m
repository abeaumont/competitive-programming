#!/bin/mira -exec
main = lay [shownum (mindist (parse $- ""))]

parse :: [char] -> [char] -> [num]
parse s a = [str2num a],               if s = [] \/ s = ['\n']
parse s a = str2num a:parse (tl s) [], if (hd s) = ','
parse s a = parse (tl s) (hd s:a),     otherwise

str2num :: [char] -> num
str2num s = 0,                                     if s = []
str2num s = str2num(tl s) * 10 + code (hd s) - 48, otherwise

mindist :: [num] -> num
mindist xs = min [dist xs x | x <- [min(xs)..max(xs)]]

dist :: [num] -> num -> num
dist xs x = 0,                                     if xs = []
dist xs x = dist (tl xs) x + sq (abs (hd xs - x)), otherwise

sq :: num -> num
sq x = x * (x + 1) div 2
