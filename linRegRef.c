#include<stdio.h>

void main()
{
    int i,j,n,x[10],y[10],xBar,yBar,abBar,asqBar,A[10],B[10],AB[10],ASQUARE[10];
    int sumX=0,sumY=0,sumAB=0,sumASQUARE=0;
    float beta0, beta1, inputX, outputY;

    printf("Enter the number of values of x and y:");
    scanf("%d",&n);

    printf("\nEnter the values of x: ");
    for(i=0;i<n;i++)
        scanf("%d",&x[i]);
    printf("\nEnter the values of y: ");
    for(i=0;i<n;i++)
        scanf("%d",&y[i]);

    for(i=0;i<n;i++)
    {
        sumX += x[i];
        sumY += y[i];
    }

    xBar = sumX/n;
    yBar = sumY/n;

    for(i=0;i<n;i++)
    {
        A[i] = x[i] - xBar;
        B[i] = y[i] - yBar;
    }

    for(i=0;i<n;i++)
        AB[i] = A[i]*B[i];

    for(i=0;i<n;i++)
        ASQUARE[i] = A[i]*A[i];

    for(i=0;i<n;i++)
    {
        sumAB += AB[i];
        sumASQUARE += ASQUARE[i];
    }

    abBar = sumAB/n;
    asqBar = sumASQUARE/n;

    beta1 = (float)abBar/(float)asqBar;
    beta0 = yBar - (beta1*xBar);

    printf("values of beta0: %f and beta1: %f\n",beta0,beta1);
    printf("Enter value of x for prediction:\n");
    scanf("%f",&inputX);

    outputY = beta0 + (beta1*inputX);
    printf("Value of y = %f at x = %f\n", outputY,inputX);
}
