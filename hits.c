#include<stdio.h>

void main()
{
    int i,j,n,adj[10][10],adjTrans[10][10];
    int hubWeightVec[3] = {1,1,1}, AuthWeightVec[3] = {0,0,0};

    printf("Enter number of nodes: ");
    scanf("%d",&n);

    printf("\n----Creating Adjacency Matrix----\n");
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
        {
            printf("Link between %d and %d ?:",i,j);
            scanf("%d",&adj[i][j]);
        }

    printf("\nGiven Matrix:\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
            printf("%d\t",adj[i][j]);
        printf("\n");
    }

    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            adjTrans[j][i] = adj[i][j];

    printf("\nTranspose Matrix:\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
            printf("%d\t",adjTrans[i][j]);
        printf("\n");
    }

    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            AuthWeightVec[i] += adjTrans[i][j] * hubWeightVec[j];

    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            hubWeightVec[i] += adj[i][j] * AuthWeightVec[j];

    printf("Authority Weight Vector:\n");
    for(i=0;i<n;i++)
        printf("%d\t", AuthWeightVec[i]);
    printf("\nHub Weight Vector:\n");
    for(i=0;i<n;i++)
        printf("%d\t", hubWeightVec[i]);

    printf("\n");
    for(i=0;i<n;i++)
        if(hubWeightVec[i]>AuthWeightVec[i])
            printf("Node %d is a Hub\n",i);
        else
            printf("Node %d is an Authority\n",i);
}
