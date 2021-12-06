#!/bin/awk -f
/forward .*/{f+=$2}
/up .*/{d-=$2}
/down .*/{d+=$2}
END{print(f*d)}
