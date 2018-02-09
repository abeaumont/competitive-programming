// https://www.codechef.com/FEB18/problems/LUCASTH
use std::io;
use std::mem;

fn s(n: usize, p: usize) {
    let mut a = vec![0; n];
    let mut b = vec![0; n];
    a[0] = 1;
    for i in 1 .. n {
        for j in 1 .. i + 1 {
            b[j] = (a[j - 1] + (i - 1) * a[j]) % p;
        }
        b = mem::replace(&mut a, b);
        a[0] = 0;
    }
    let mut c = 0;
    for i in 0 .. n {
        if a[i] != 0 { c += 1 }
    }
    println!("{}", c);
}

fn main() {
    let stdin = io::stdin();
    let mut line = String::new();
    stdin.read_line(&mut line).unwrap();
    let t = line.trim().parse::<usize>().unwrap();
    for _ in 0..t {
        line.clear();
        stdin.read_line(&mut line).unwrap();
        let numbers = line
            .split_whitespace()
            .map(|x| x.parse::<usize>().unwrap())
            .collect::<Vec<usize>>();
        let n = numbers[0] + 2 as usize;
        let p = numbers[1];
        s(n, p);
    }
}
