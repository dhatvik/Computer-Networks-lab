#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int gcd(int a,int h)
{
    while(1)
    {
        int temp=a%h;
        if(temp==0)
        return h;
        else
        a=h;
        h=temp; 
    }
}

void main()
{
    int phi,p,q,n,msg,e=2,d=e;
    printf("enter Values for p and q\n");
    scanf("%d%d",&p,&q);
    printf("Enter Message to be encrypted\n");
    scanf("%d",&msg);
    n=p*q;
    phi=(p-1)*(q-1);

    while (e<phi)
    {
        if(gcd(e,phi)==1)
        break;
        else
        e++;
    }
    
    while(1)
    {
        if(fmod(d*e,phi)==1)
        break;
        else
        d++;
    }
    long long encrypted=fmod(pow(msg,e),n);
    long long decrypted=fmod(pow(encrypted,d),n);
    printf("Message is %d\t",msg);
    printf("Encrypted Message is %d:\t",encrypted);
    printf("decrypted Message is %d:\t",decrypted);
    

}