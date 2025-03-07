#include <stdio.h>
main()
{
   float a;
   scanf("%f",&a);
   printf("%.2f",a=(int)(a*100+0.5)/100.0);
}
