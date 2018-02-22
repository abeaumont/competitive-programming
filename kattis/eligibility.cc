// https://open.kattis.com/problems/eligibility
#include <cstdio>

int main() {
  int n;
  int x = scanf("%d", &n);
  for (int i = 0; i < n ;i++) {
    char a[31];
    int b1, b2, b3;
    int c1, c2, c3;
    int d;
    x = scanf("%s %d/%d/%d %d/%d/%d %d", a, &b1, &b2, &b3, &c1, &c2, &c3, &d);
    if (b1 >= 2010) printf("%s %s\n", a, "eligible");
    else if (c1 >= 1991) printf("%s %s\n", a, "eligible");
    else if (d > 40) printf("%s %s\n", a, "ineligible");
    else printf("%s %s\n", a, "coach petitions");
  }
}
