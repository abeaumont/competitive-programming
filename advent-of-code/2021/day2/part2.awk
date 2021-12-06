#!/bin/awk -f
/forward .*/{f+=$2;d+=$2*a}
/up .*/{a-=$2}
/down .*/{a+=$2}
END{print(f*d)}
