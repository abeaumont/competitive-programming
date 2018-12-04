import std.stdio, std.array, std.algorithm, std.conv, std.regex;

void main() {
  int[][int] a;
  int g, s, e;
  foreach (line; stdin.byLineCopy.array.sort()) {
    auto m = line.matchFirst(`.*:(\d{2})\] (\w+) #?(\w+).*`);
    if (m[2] == "Guard") g = m[3].to!int;
    else if (m[2] == "falls") s = m[1].to!int;
    else {
      e = m[1].to!int;
      foreach (i; s .. e) {
        a.require(g, new int[60]);
        a[g][i]++;
      }
    }
  }
  int m = 0, l = 0;
  foreach (k, v; a) {
    auto i = v.maxIndex();
    if (v[i] > m) {
      m = v[i];
      g = k;
      l = i.to!int;
    }
  }
  writeln(g*l);
}
