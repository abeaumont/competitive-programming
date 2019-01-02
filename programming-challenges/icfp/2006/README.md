## ICFP Contest 2006

A pair of UM implementations for [ICFP Contest 2006](http://boundvariable.org/).
Task and source code available at [http://boundvariable.org/task.shtml](http://boundvariable.org/task.shtml)

* Python: [um.py](um.py).
* Nim: [um.nim](um.nim). Requires [fixed](https://github.com/OpenSystemsLab/struct.nim/pull/1) [struct.nim](https://github.com/OpenSystemsLab/struct.nim).

Sandmark running times, for reference:

```
> time pypy ./um.py sandmark.umz > /dev/null

real	2m55.396s
user	2m51.325s
sys	0m4.067s
> nim c -d:release um.nim
[...]
> time ./um sandmark.umz > /dev/null

real	0m24.632s
user	0m23.772s
sys	0m0.860s
```
