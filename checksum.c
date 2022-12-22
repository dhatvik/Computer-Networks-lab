#include<stdio.h>
#include<math.h>


int sender(int b[20],int k)
{
    int checksum,sum=0,i;
    printf("\n SENDER SIDE\n");
    for(i=0;i<k;i++)
    sum+=b[i];
    printf("Sender Sum is \t:%d",sum);
   
    checksum=~sum;
    printf("\n Sender Checksum is %d:",checksum);
    return checksum;
}

int receiver(int c[20],int k,int scheck)
{
    int checksum,sum=0,i;
    printf("\n RECEIVER SIDE\n");
    for(i=0;i<k;i++)
    sum+=c[i];
    printf("\nReceivers Sum is %d",sum);
    sum=sum+scheck;
    checksum=~sum;
    printf("\n Receiver Chcksum is %d ",checksum);
    return checksum;
}



void main()
{
    int a[20];
    int i,scheck,rcheck,m;

    printf("Enter no of bit strings\n");
    scanf("%d",&m);
    printf("Enter the bit strings\n");
    for(i=0;i<m;i++)
    scanf("%d",&a[i]);

    scheck=sender(a,m);
    rcheck=receiver(a,m,scheck);

    if(rcheck==0)
    printf("\nNo Errors");
    else
    printf("\nError is present");
    
}