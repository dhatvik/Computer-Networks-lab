#include<stdio.h>
#include<stdlib.h>

void main()
{
    int incoming,outgoing,bsize,store=0,n;
    printf("Enter bucket size ,outging rate,number of inputs\n");
    scanf("%d%d%d",&bsize,&outgoing,&n);

    while(n!=0)
    {
        printf("Enter incoming packet size \n");
        scanf("%d",&incoming);
        printf("The incoming packet size is %d\n",incoming);

        if(incoming <= (bsize-store))
        {
            store=store+incoming;
            printf("The bucket buffer is %d out of %d\n",store,bsize);

        }
        else
        {
            printf("Dropped %d packets from buffer\n",incoming-(bsize-store));
            store=bsize;
        }
        store = store-outgoing;
        printf("after outgoing %d packets left out of %d buffer size\n ",store,bsize);
        n--;
    }
}