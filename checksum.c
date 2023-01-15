#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char str[100];

int generatechecksum(int mode ,int checksum)
{
    int n,temp,sum=0;
    if(strlen(str)%2 !=0)
    {
        n = (strlen(str)+1)/2;
    }
    else
    {
    n = strlen(str)/2;
    }

    for(int i=0;i<n;i++)
    {
        temp= str[i*2];
        temp=(temp*256) + str[(i*2)+1];
        printf("\n%x",temp);
        sum=sum+temp;
    }

    if(mode == 1)
    {
        printf("\n%x",checksum);
        sum=sum+checksum;
    }

    if(sum%65536 != 0)
    {
        n=sum%65536;
        sum=(sum/65536)+n;
    }
    printf("\nsum genearted is %x",sum);
    sum=65535-sum;
    printf("\n checksum generated is %x",sum);

    return sum;
} 

void main()
{
    int sum1=0;
    int sum2=0;

    printf("Enter the string u want to send");
    scanf("%s",str);

    sum1=generatechecksum(0,0);

    int ch;
    printf("Enter 1 if u want to introduce error");
    scanf("%d",&ch);
    if(ch==1)
    {
        str[0]++;
        sum2=generatechecksum(1,sum1);

        if(sum2==0)
        {
        printf("\n No error");
        }
        else
        printf("\n error detected");
    }
    else
    {
        sum2=generatechecksum(1,sum1);
        if(sum2==0)
        {
        printf("\n No error");
        }
        else
        printf("\n error detected");
    
    }
}
