use std::collections::HashSet;
use std::io;
use std::io::prelude::*;
use std::vec::Vec;

fn main() -> io::Result<()> {
    let stdin = io::stdin();
    let mut g: Vec<HashSet<_>> = vec![HashSet::new(); 26];
    for line in stdin.lock().lines() {
        let b = line?.into_bytes();
        let u = (b[5] - 65) as usize;
        let v = (b[36] - 65) as usize;
        g[v].insert(u);
    }
    let mut s = HashSet::new();
    let mut p = vec![];
    for _ in 0..26 {
        for i in 0..26 {
            if s.contains(&i) {
                continue;
            }
            if g[i].difference(&s).collect::<HashSet<_>>().is_empty() {
                s.insert(i);
                p.push(i as u8 + 65);
                break;
            }
        }
    }
    println!("{}", String::from_utf8(p).unwrap());
    Ok(())
}
