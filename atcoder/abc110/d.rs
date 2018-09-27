// https://abc110.contest.atcoder.jp/tasks/abc110_d
use std::collections::HashMap;
use std::io;
use std::vec::Vec;

const MOD: i64 = 1000000007;

fn modinv(a: i64, n: i64) -> i64 {
    let mut t = (0, 1);
    let mut r = (n, a);
    while r.1 != 0 {
        t = (t.1, t.0 - (r.0 / r.1) * t.1);
        r = (r.1, r.0 % r.1);
    }
    while t.0 < 0 {
        t.0 += n
    }
    t.0
}

fn main() {
    let mut l = String::new();
    io::stdin().read_line(&mut l).expect("");
    let l = l
        .trim()
        .split(" ")
        .map(|x| x.parse().expect(""))
        .collect::<Vec<i64>>();
    let (n, mut m) = (l[0], l[1]);
    let mut h = HashMap::new();
    let mut i = 2;
    while i * i <= m {
        if m % i == 0 {
            h.insert(i, 1);
            m /= i;
            while m % i == 0 {
                if let Some(x) = h.get_mut(&i) {
                    *x = *x + 1
                }
                m /= i;
            }
        }
        if i % 2 == 0 {
            i += 1
        } else {
            i += 2
        }
    }
    if m > 1 {
        h.insert(m, 1);
    }
    let mut r = 1;
    for (_, &v) in h.iter() {
        let mut k = 1;
        for i in 0..v {
            k = k * (n + i) % MOD
        }
        let mut l = 1;
        for i in 2..v + 1 {
            l = (l * i) % MOD
        }
        r = r * (k * modinv(l, MOD) % MOD) % MOD
    }
    if r < 0 {
        r += MOD
    }
    println!("{}", r)
}
