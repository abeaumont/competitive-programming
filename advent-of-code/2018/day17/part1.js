#!/usr/bin/env node
const rl = require('readline').createInterface({input: process.stdin})

let c = []
rl.on('line', (l) => {
    let [a, b] = l.split(', ')
    if (a.indexOf('y') == -1) {
        [a, b] = [b, a]
    }
    c.push([a, b].map((e) => {
        const v = e.split('=')[1]
        const fs = v.indexOf('.') == -1 ? [v, v] : v.split('..')
        return [parseInt(fs[0]), parseInt(fs[1])]
    }))
})

rl.on('close', () => {
    const ymax = Math.max(...c.map((x) => x[0][1])) + 1
    const ymin = Math.min(...c.map((x) => x[0][0]))
    const xmax = Math.max(...c.map((x) => x[1][1])) + 2

    let m = new Array(ymax).fill().map(_ => Array(xmax).fill('.'))
    m[0][500] = '+'
    for (const [y, x] of c)
        for (let i = y[0]; i <= y[1]; i++)
            for (let j = x[0]; j <= x[1]; j++)
                m[i][j] = '#'

    const fill = (y, x, d) => {
        if (m[y][x] == '#') return false
        m[y][x] = '|'
        if (m[y + 1][x] == '|') return true
        if (m[y + 1][x] == '.' && (down(y + 1, x))) return true
        if (fill(y, x + d, d)) return true
        m[y][x] = '~'
        return false
    }

    const replace = (y, x, d) => {
        for (let i = x; m[y][i] == '~'; i += d) m[y][i] = '|'
    }

    const rowfill = (y, x) => {
        m[y][x] = '~'
        const p1 = fill(y, x + 1, 1)
        const p2 = fill(y, x - 1, -1)
        if (p1) replace(y, x, -1)
        if (p2) replace(y, x, 1)
        return p1 || p2
    }

    const down = (y, x) => {
        m[y][x] = '|'
        if (y == ymax - 1) return true
        if (m[y + 1][x] == '#') return rowfill(y, x)
        if (down(y + 1, x)) return true
        m[y][x] = '~'
        return rowfill(y, x)
    }

    down(1, 500)
    let s = 0
    for (let i = ymin; i < ymax; i++)
        s += m[i].reduce((a, x) => a + (x == '~' || x == '|' ? 1 : 0), 0)
    console.log(s)
})
