#include <stdio.h>
#include <string.h>

int main() {
  char str[6] = "xiyou";
  char str1[10]="linux";
  strcat(str,str1);
  printf("%s\n", str);
}