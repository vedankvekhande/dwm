#include<stdio.h>
#define damp 1

void main()
{
    int n,i,j,k,outlink[10],iter;
    float pr[10],prNew[10];
    int adj[10][10];

    printf("Enter number of nodes:");
    scanf("%d",&n);

    for(i=0;i<n;i++)
    {
        printf("Enter the number of outlinks for node %d: ",i);
        scanf("%d",&outlink[i]);
    }

    //Adjacency Matrix
    printf("\n----CREATING ADJACENCEY MATRIX----\n");
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
        {
            printf("Link between %d and %d ?: ",i,j);
            scanf("%d",&adj[i][j]);
        }

    printf("\nAdjacency Matrix\n\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
            printf("%d\t",adj[i][j]);
        printf("\n");
    }

    for(i=0;i<n;i++)
    {
        pr[i] = 1/(float)n;
        prNew[i] = 0;
    }

    printf("\nEnter number of iterations required: ");
    scanf("%d",&iter);

    for(k=0;k<iter;k++)//iter
    {
        for(i=0;i<n;i++)//all nodes
            for(j=0;j<n;j++)
                if(adj[j][i] == 1)
                    prNew[i] += ((1-damp) + (damp * (pr[j]/(float)outlink[j])));
    }

    for(i=0;i<n;i++)
        printf("\nPage Rank of Node %d is %f",i,prNew[i]);
}
