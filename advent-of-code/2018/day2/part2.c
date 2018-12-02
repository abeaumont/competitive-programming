#include <assert.h>
#include <stdio.h>
#include <string.h>

int main() {
  char ids[300][27];
  int n = 0;
  while (scanf("%26s", ids[n]) != EOF) n++;
  for (int i = 0; i < n - 1; i++)
    for (int j = i + 1; j < n; j++) {
      assert(strlen(ids[i]) == strlen(ids[j]));
      int c = 0;
      for (int k = 0; k < strlen(ids[i]); k++)
        c += ids[i][k] != ids[j][k];
      if (c == 1) {
        for (int k = 0; k < strlen(ids[i]); k++)
          if (ids[i][k] == ids[j][k]) putchar(ids[i][k]);
        puts("");
        return 0;
      }
    }
}
