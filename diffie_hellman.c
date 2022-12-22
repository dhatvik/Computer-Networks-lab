#include<stdio.h>
#include<math.h>

long long power(int a,int b,int mod)
{
    return (int) pow(a,b)%mod;
}
void main()
{
    int g,p,r1,r2,x,y;
    printf("Enter Values for g and p\t");
    scanf("%d%d",&g,&p);
    printf("Enter x for sender\t");
    scanf("%d",&x);
    r1=power(g,x,p);
    printf("Enter y for receiver\t");
    scanf("%d",&y);
    r2=power(g,y,p);

    printf("Value of key for sender is:%d",power(r2,x,p));
    printf("Value of key for receiver is:%d",power(r1,y,p));
}