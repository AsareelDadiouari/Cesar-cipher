#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char crypt(char *c)
{
  if((*c>=65 && *c<=90) || *c>=97 && *c<=122)
  {
    *c+=5;
    if(*c>90 || *c>122)
    {
        *c-=26;
    }
  }
  return *c;
}

int main(int argc, char const *argv[]) {
  char cMessage[]="BONJOURZ les ";
  int i;

  for(i=0; i<strlen(cMessage); i++)
  {
    cMessage[i]=crypt(&cMessage[i]);
  }

  printf("%s\n",cMessage);

  return 0;
}
