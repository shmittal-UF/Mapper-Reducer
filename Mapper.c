#include <stdio.h>

int main() {
  char str[999];
FILE *file1;
int count=1;
file1 = fopen( "File.txt" , "r");
if (file1) {
    while (fscanf(file1, "%s", str)!=EOF)
    {
        printf("(%s,%d)\n",str,count);
    }
    fclose(file1);
}
return 0;
}
