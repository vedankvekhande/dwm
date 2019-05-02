#include<stdio.h>
#include<stdlib.h>
#include<math.h>

void main()
{
	int i,n,ogArray[20],k1[20],k2[20];

	printf("Enter the number of elements: ");
	scanf("%d",&n);
	printf("Enter the elements in ascending order: ");
	for(i=0;i<n;i++)
		scanf("%d",&ogArray[i]);

	int m1,m1old,m2,m2old,j=0,k=0,sum1=0,sum2=0;
	m1=m1old=ogArray[1], m2=m2old=ogArray[n-2];

	//gen1
	for(i=0;i<n;i++)
		if(abs(ogArray[i]-m1)<abs(ogArray[i]-m2))
		{
			k1[j] = ogArray[i];
			j++;
		}
		else
		{
			k2[k] = ogArray[i];
			k++;
		}


	for(i=0;i<j;i++)
		sum1 += k1[i];
	m1 = sum1/j;

	for(i=0;i<k;i++)
		sum2 += k2[i];
	m2 = sum2/k;

	//gen2
	while(m1 != m1old && m2 != m2old)
	{
		for(i=0;i<n;i++)
			if(abs(ogArray[i]-m1) < abs(ogArray[i]-m2))
			{
				k1[j] = ogArray[i];
				j++;
			}
			else
			{
				k2[k] = ogArray[i];
				k++;
			}

		for(i=0;i<j;i++)
			sum1 += k1[i];
		m1old = m1;
		m1 = sum1/j;

		for(i=0;i<k;i++)
			sum2 += k2[i];
		m2old = m2;
		m2 = sum2/k;
	}

	printf("\nMean 1: %d \n Partition 1:\n",m1);
	for(i=0;i<j;i++)
		printf("%d\t",k1[i]);
	printf("\nMean 2:%d  \n Partition 2:\n",m2);
	for(i=0;i<k;i++)
		printf("%d\t",k2[i]);

}
