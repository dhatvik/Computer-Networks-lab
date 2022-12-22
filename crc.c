#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int i,j,msglen,keylen;
char senddata[50],recdata[50],temp[30],rem[30],quot[30],input[50],key[20],key1[20];

void  division(char input[50])
{
    for(i=0;i<keylen-1;i++)
    input[i+msglen]='0';
    for(i=0;i<keylen;i++)
    temp[i]=input[i];
    for(i=0;i<msglen;i++)
    {
        quot[i]=temp[0];
        if(quot[i]=='0')
            for(j=0;j<keylen;j++)
            key[j]='0';
        else
            for(j=0;j<keylen;j++)
            key[j]=key1[j];

        for(j=keylen-1;j>0;j--)
        {
            if(temp[j]==key[j])
            rem[j-1]='0';
            else
            rem[j-1]='1';
        }    
        rem[keylen-1]=input[i+keylen];
        strcpy(temp,rem);
    }
    strcpy(rem,temp);
}

void main()
{
    printf("Enter send data\n");
    gets(senddata);
    printf("Enter key\n");
    gets(key);

    msglen=strlen(senddata);
    keylen=strlen(key);
    strcpy(key1,key);

    division(senddata);

    printf("The remainder is \n");
    for(i=0;i<keylen;i++)
    {
        printf("%c",rem[i]);
    }

    
    printf("\nThe Final Data  is \n");
    for(i=0;i<msglen;i++)
    {
        printf("%c",senddata[i]);
    }
    for(i=0;i<keylen;i++)
    {
        printf("%c",rem[i]);
    }

    printf("Enter rec data\n");
    gets(recdata);

    msglen=strlen(recdata);

    division(recdata);

    int flag=0;
    printf("The Remainder is given by\n");
    for(i=0;i<keylen-1;i++)
    {
        if(rem[i]==0)
        flag=1;
        printf("%c",rem[i]);
    }
    if(flag==0)
    printf("\nNo Error");
    else
    printf("\nThe data is corrupted");

}