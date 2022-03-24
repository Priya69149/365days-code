#include<stdio.h>
#include<string.h>
int main()
{
  int i;
  char s[70];
  printf("Input the string:\n");
  gets(s);
  int l=strlen(s);
  for(i=0;i<l;i++)
  {
    int ch=s[i];
    if(ch>'A' && ch<='Z')
    s[i]=ch+32;
    if(ch>='a' && ch<='z')
    s[i]=ch-32;
  }
  puts(s);
  return 0;
}
