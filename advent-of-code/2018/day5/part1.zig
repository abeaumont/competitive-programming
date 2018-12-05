const std = @import("std");
const readLineSlice = std.io.readLineSlice;
const abs = std.math.absCast;
const warn = std.debug.warn;

pub fn main() !void {
    var in: [50010]u8 = undefined;
    var b: [50010]u8 = undefined;
    const l = try readLineSlice(in[0..]);
    var k: usize = 0;
    var i: usize = 0;
    while (i < l.len) : (i += 1) {
        if (k == 0 or abs(i32(l[i]) - i32(b[k - 1])) != 32) {
            b[k] = l[i];
            k += 1;
        } else k -= 1;
    }
    warn("{}\n", k);
}
