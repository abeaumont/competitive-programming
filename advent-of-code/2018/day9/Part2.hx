private class CircularListNode<T> {
  public var item: T;
  public var next: CircularListNode<T>;
  public var prev: CircularListNode<T>;

  public inline function new(item: T, next: CircularListNode<T>, prev: CircularListNode<T>) {
    this.item = item;
    this.next = next;
    this.prev = prev;
  }
}

class CircularList<T> {
  private var cur: CircularListNode<T>;

  public function new() {}

  public function add(item: T)
    if (this.cur == null) {
      this.cur = new CircularListNode(item, null, null);
      this.cur.next = this.cur;
      this.cur.prev = this.cur;
    } else {
      var node = new CircularListNode(item, null, null);
      node.prev = this.cur;
      node.next = this.cur.next;
      this.cur.next.prev = node;
      this.cur.next = node;
      this.cur = node;
    }

  public function remove()
    if (this.cur != null)
      if (this.cur == this.cur.next)
        this.cur = null;
      else {
        this.cur.next.prev = this.cur.prev;
        this.cur.prev.next = this.cur.next;
        this.cur = this.cur.next;
      }

  public function get(): Null<T> {
    if (this.cur == null)
      return null;
    return this.cur.item;
  }

  public function left(n: Int)
    if (this.cur != null)
      for (i in 0...n)
        this.cur = this.cur.prev;

  public function right(n: Int)
    if (this.cur != null)
      for (i in 0...n)
        this.cur = this.cur.next;
}

class Part2 {
  static public function main() {
    var r = ~/(\d+) .* (\d+)/;
    r.match(Sys.stdin().readLine());
    var n = Std.parseInt(r.matched(1));
    var k = Std.parseInt(r.matched(2)) * 100;
    var a = [for (_ in 0...n) 0];
    var l = new CircularList();
    l.add(0);
    for (i in 1...k+1)
      if (i % 23 == 0) {
        l.left(7);
        a[i % n] += i + l.get();
        l.remove();
      } else {
        l.right(1);
        l.add(i);
      }
    var m = 0;
    for (x in a)
      if (x > m)
        m = x;
    Sys.println(m);
  }
}
