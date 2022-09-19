#include<conio.h>
#include<stdlib.h>
#include<stdio.h>


void main()
{
	int n,b,o,j,i,bucket=0;
	printf("Enter the number of queries:");
	scanf("%d",&n);
	printf("Enter the bucket size:");
	scanf("%d",&b);
	printf("Enter the output size:");
	scanf("%d",&o);
    while (n != 0) 
	{

        printf("\nEnter the incoming packet size : ");
        scanf("%d", &i);
        if (i <= (b - bucket))
        {
            bucket += i;
            printf("Bucket buffer size %d out of %d\n", bucket, b);
        } else {
            printf("Dropped %d no of packets\n", i - (b - bucket));
            printf("Bucket buffer size %d out of %d\n", bucket, b);
            bucket = b;
        }
        bucket = bucket - o;
        printf("After outgoing %d packets left out of %d in buffer\n", bucket, b);
        n--;
	}
	
}