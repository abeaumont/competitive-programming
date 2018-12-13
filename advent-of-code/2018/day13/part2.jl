#!/usr/bin/env julia
m = map(x -> map(x -> x[1], split(x, "")), readlines(stdin))
let c = 1, d = Dict(), e = [], f = []
    for (i, v) in enumerate(m)
        for (j, x) in enumerate(m[i])
            if m[i][j] in "<>^v"
                if haskey(d, (i, j))
                    delete!(d, (i, j))
                end
                d[(i, j)] = c
                c += 1
                push!(e, 0)
                if m[i][j] in "<>"
                    push!(f, m[i][j] == '<' ? 0 : 2)
                    m[i][j] = '-'
                else
                    push!(f, m[i][j] == '^' ? 1 : 3)
                    m[i][j] = '|'
                end
            end
        end
    end
    while true
        if length(d) == 1
            y, x = collect(keys(d))[1]
            println("$(x - 1),$(y - 1)")
            break
        end
        for k in sort(collect(keys(d)))
            if !haskey(d, k)
                continue
            end
            u = d[k]
            delete!(d, k)
            i, j = k
            y, x = i, j
            if f[u] % 4 == 0
                x -= 1
            elseif f[u] % 4 == 1
                y -= 1
            elseif f[u] % 4 == 2
                x += 1
            else
                y += 1
            end
            if haskey(d, (y, x))
                delete!(d, (y, x))
            else
                d[(y, x)] = u
            end
            if m[y][x] == '+'
                if e[u] % 3 == 0
                    f[u] -= 1
                elseif e[u] %3 == 2
                    f[u] += 1
                end
                e[u] += 1
            elseif m[y][x] == '\\'
                if f[u] % 4 == 0
                    f[u] = 1
                elseif f[u] % 4 == 1
                    f[u] = 0
                elseif f[u] % 4 == 2
                    f[u] = 3
                else
                    f[u] = 2
                end
            elseif m[y][x] == '/'
                f[u] = 3 - (f[u] % 4)
            end
        end
    end
end
