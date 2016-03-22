#include<stdio.h>
main()
{
  int flag=0,flag1=0;
  int s[10],d[10],sn,eop=1,dm,a[10][10];
  int i,j,sum=0,min,x[10][10],k,fa,fb;

  /* Getting The Input For the Problem*/
  
  printf("Enter the number of Supply");
  scanf("%d",&sn);
  printf("Enter the number of Demand");
  scanf("%d",&dm);
  printf("Enter the elements of the array");
  for(i=0;i<sn;i++)
    {
      for(j=0;j<dm;j++)
	{
	  scanf("%d",&a[i][j]);
	}
    }
  printf("Enter the Demand Values");
  for(j=0;j<sn;j++)
    scanf("%d",&d[j]);

  printf("Enter the Supply Values");
  for(i=0;i<sn;i++)
    scanf("%d",&s[i]);

  /* Calculation For the Transportation */
  
  i=0;j=0;
  for(i=0,j=0;i<sn,j<dm;)
    {
      if(s[i]<d[j]) // Check supply less than demand
	{
	  x[i][j]=a[i][j]*s[i]; // Calculate amount * supply
	  d[j]=d[j]-s[i]; // Calculate demand - supply
	  i++; // Increment i for the deletion of the row or column

	}
      else if(s[i]>=d[j]) //Check the supply greater than equal to demand
	  {
	    x[i][j]=a[i][j]*d[j]; // Calculate amount * demand
	    s[i]=s[i]-d[j]; // Calculate supply - demand
	    j++; // Increment j for the deletion of the row
	  }
      
    }
  /* The Cost Matrix is Estimated here */
  printf("Given Cost Matrix is :\n");
  for(fa=0;fa<sn;fa++)
    {
      for(fb=0;fb<dm;fb++)
	{
	  printf("%d ",a[fa][fb]);
	}
      printf("\n");
    }
  /* The Allocated Cost Matrix is */

  printf("Allocated Cost Matrix is ");
  for(fa=0;fa<sn;fa++)
    {
      for(fb=0;fb<dm;fb++)
	{
	  printf("%d ",x[fa][fb]);
	  sum=sum+x[fa][fb];
	}
      printf("");
    }
  /* Transportation Cost Estimated and Sum is Printed*/
  printf("The Transportation cost:%d",sum);
}
