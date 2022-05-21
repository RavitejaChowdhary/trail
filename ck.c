#include <stdio.h>
#include <string.h>
char check(char ch)
{
   if (ch >= 'A' && ch <= 'Z')
      return ch;
   else if (ch >= 'a' && ch <= 'z')
      return (ch - 32);
}
int main()
{
   char arr[100];
   gets(arr);
   int i = 0;
   int n = strlen(arr);
   while (i < n)
   {
      if (arr[i] == ' ')
      {
         arr[i + 1] = check(arr[i + 1]);
      }
      i++;
   }
   printf("%s", arr);
    char arr[20] = "hello mawa";
   arr[0] -= 32;
   printf("%s", arr);
}
