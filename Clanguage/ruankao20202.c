#include<stdio.h>
#include<math.h>

double cubeRoot(double x)
{double x1,x2=x;
    if(fabs(x)<1e-6) return 0;
    do{
        x1=x2;
        x2=(2.0*x1+x/pow(x1,2)/3.0);
    }while(fabs(x2-x1)>1e-6);
    return x2;
}
int main(){
    double  x;
    for(x=-8.0;x<=8.0;x+=0.1){
        printf("%.2lf %.2lf\n",x,cubeRoot(x));
    }
    return 0;
}