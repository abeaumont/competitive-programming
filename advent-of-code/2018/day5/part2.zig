const std = @import("std");
const readLineSlice = std.io.readLineSlice;
const abs = std.math.absCast;
const min = std.math.min;
const warn = std.debug.warn;

const M = 50010;

pub fn main() !void {
    var in: [M]u8 = undefined;
    var b: [M]u8 = undefined;
    const l = try readLineSlice(in[0..]);
    var m: usize = M;
    var c: u8 = 0;
    while (c < 26) : (c += 1) {
        const a = 'a' + c;
        const A = 'A' + c;
        var k: usize = 0;
        var i: usize = 0;
        while (i < l.len) : (i += 1) {
            if (l[i] == a or l[i] == A) continue;
            if (k == 0 or abs(i32(l[i]) - i32(b[k - 1])) != 32) {
                b[k] = l[i];
                k += 1;
            } else k -= 1;
        }
        m = min(m, k);
    }
    warn("{}\n", m);
}
