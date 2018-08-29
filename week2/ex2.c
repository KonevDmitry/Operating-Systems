#include <stdio.h>
#include <string.h>
int main(void){
    char s[10];
    gets(s);
    reverse(s);
    getch();
    return 0;
}
void reverse( char * sPtr )
{
   if ( sPtr[ 0 ] == '\0' )
      return;
   else {
      reverse( &sPtr[ 1 ] );
      putchar( sPtr[ 0 ] );
   }
}
