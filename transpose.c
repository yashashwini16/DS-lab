/* Program to find transpose of a sparse matrix */

#include <stdio.h>
typedef struct
{
    int row;
    int col;
    int value;
}MATRIX;
MATRIX a[30],t[30];
 void create(int r,int c)
 {
     int i,j,k=1,ele;
    printf("Enter matrix elements\n");
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            scanf("%d",&ele);
            if(ele!=0)
            {
                a[k].row=i;
                a[k].col=j;
                a[k].value=ele;
                k++;
            }
        }
    }
    a[0].row=r;
    a[0].col=c;
    a[0].value=k-1;
    printf("sparse matrix\n");
    for(i=0;i<=a[0].value;i++)
        printf("%d\t%d\t%d\n",a[i].row,a[i].col,a[i].value);
 }
 void transpose()
 {
     int i,j,k=1;
     t[0].row=a[0].col;
     t[0].col=a[0].row;
     t[0].value=a[0].value;
     for(i=0;i<a[0].col;i++)
     {
         for(j=1;j<=a[0].value;j++)
         {
             if(a[j].col==i)
             {
                 t[k].row=a[j].col;
                 t[k].col=a[j].row;
                 t[k].value=a[j].value;
                 k++;
             }
         }
     }
     printf("Transpose\n");
     for(i=0;i<=t[0].value;i++)
     {
         printf("%d\t%d\t%d\n",t[i].row,t[i].col,t[i].value);
     }
 }
int main()
{
    int r,c;
    printf("Enter the order of matrix\n");
    scanf("%d%d",&r,&c);
    create(r,c);
    transpose();
    return 0;
}
