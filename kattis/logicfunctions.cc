// https://open.kattis.com/problems/logicfunctions
void exclusive(bool x, bool y, bool &ans) { ans = x ^ y; }
void implies(bool x, bool y, bool &ans) { ans = !x || y; }
void equivalence(bool x, bool y, bool &ans) { ans = x == y; }
