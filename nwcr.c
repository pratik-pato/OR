#include<stdio.h>
#include<stdlib.h>
int main(void)
{
  int i=0,j=0,k=0,r=0,c=0,max=0,min=0,col=0,row=0;
  int **a,flag=0,supply=0,demand=0,sum=0,temp=0,count=0,mr=0,mc=0;
  printf("\n************* NORTH WEST CORNER RULE *************\n");
  printf("\nPlease enter the order of the first matrix:\n");
  scanf("%d",&mr);
  printf("X\n");
  scanf("%d",&mc);
  r=mr+1;
  c=mc+1;
  a=(int**)malloc(r*sizeof(int*));
  for(i=0;i<r;i++)
    {
      a[i]=(int*)malloc(c*sizeof(int));
    }
  printf("\nEnter the element of the matrix:\n");
  for(i=0;i<mr;i++)
    {
      for(j=0;j<mc;j++)
	{
	  scanf("%d",&a[i][j]);
	}
    }

  printf("\nEnter the Supply:\n");
  for(i=0;i<mr;i++)
    {
      scanf("%d",&a[i][mc]);
    }
  printf("\nEnter the Demand:\n");
  for(j=0;j<mc;j++)
    {
      scanf("%d",&a[mr][j]);
    }
  a[mr][mc]=a[0][mc]+a[1][mc]+a[2][mc];

  printf("\n\nThe cost matrix is given bellow::\n\n");



  for(i=0;i<r;i++)
    {
      for(j=0;j<c;j++)
	{
	  printf("%5d",a[i][j]);
	}
      printf("\n");
    }



   do
     {
       count=0;
       flag=0;

       for(i=0;i<(r-1);i++)
	 {
	   for(j=0;j<(c-1);j++)
	     {
	       if((a[i][c-1]!=0)&&(a[r-1][j]!=0)&&flag==0)
		 {
		   min=a[i][j];
		   row=i;
		   col=j;
		   flag=1;
		   count++;
		 }

	     }
	 }
       supply=a[row][c-1];
       demand=a[r-1][col];
       if(supply>=demand)
	 {
	   temp=supply-demand;
	   a[row][col]=a[row][col]*demand;
	   sum=sum+a[row][col];
	   a[row][c-1]=temp;
	   a[r-1][col]=0;
	 }
       if(supply<demand)
	 {
	   temp=demand-supply;
	   a[row][col]=a[row][col]*supply;
	   sum=sum+a[row][col];
	   a[row][c-1]=0;
	   a[r-1][col]=temp;
	 }
     }while(count!=0);

   printf("\n\nTOTAL COST :: %d\n\n",sum);
   return 0;
}
