#include <stdio.h>
#include <string.h>

int main() {
  int k[] = {0, 0};
  char line[27];
  while (scanf("%26s\n", line) != EOF) {
    char l[26];
    bzero(l,26);
    for (char *p = line; *p; p++) l[*p - 'a']++;
    int s[] = {0, 0};
    for (int i = 0; i < 26; i++) {
      if (l[i] == 2) s[0]++;
      else if (l[i] == 3) s[1]++;
    }
    if (s[0]) k[0]++;
    if (s[1]) k[1]++;
  }
  printf("%d\n", k[0] * k[1]);
}
