#include <stdio.h>
main()
{
    int a,b,c;
    scanf("%d\t%d",&a,&b);
    c=1000*(b%10)+100*(a/10)+10*(b/10)+(a%10);
    printf("%d",c);

}