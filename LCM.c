#include<stdio.h>
void main()
{ int c[20][20],i,j,min,m,n,b,d,c2,c1,p,q,dem[20],sup[20],rf[20],cf[20],sum=0;
  printf("\nEnter the row & column:");
  scanf("%d%d",&m,&n);
  printf("\nEnter the cost:");
  for(i=0;i<m;i++)
    { for(j=0;j<n;j++)
	scanf("%d",&c[i][j]);
    }
    printf("\nEnter the supply:");
  for(i=0;i<m;i++)
    scanf("%d",&sup[i]);
  printf("\nEnter the demand:");
  for(i=0;i<n;i++)
    scanf("%d",&dem[i]);

  printf("\nMatrix:\n");
  for(i=0;i<m;i++)
    { for(j=0;j<n;j++)
	printf(" %d ",c[i][j]);
      printf("%d",sup[i]);
      printf("\n");
    }
  for(j=0;j<n;j++)
    printf("%d ",dem[j]);
  for(i=0;i<m;i++)
    rf[i]=0;
  for(i=0;i<n;i++)
    cf[i]=0;
  b=m;d=n;
  while(b>0&&d>0)
    { min=1000;
      for(i=0;i<m;i++)
	{ if(rf[i]!=1)
	    { for(j=0;j<n;j++)
		{ if(cf[j]!=1)
		    { if(min>c[i][j])
			{ min=c[i][j];
			  p=i;
			  q=j;
			}
		    }
		}
	    }
	}
      if(sup[p]<dem[q])
	c1=sup[p];
      else
	c1=dem[q];
      for(i=0;i<m;i++)
	{ if(rf[i]!=1)
	    { for(j=0;j<n;j++)
		{ if(cf[j]!=1)
		    { if(min==c[i][j])
			{ if(sup[i]<dem[j])
			    c2=sup[i];
			  else
			    c2=dem[j];
			  if(c2>c1)
			    { c1=c2;
			      p=i;
			      q=j;
			    }
			}
		    }
		}
	    }
	}
      printf("\n  %d %d %d ",min,p,q);
      if(sup[p]<dem[q])
	{ sum=sum+c[p][q]*sup[p];
	  dem[q]-=sup[p];
	  rf[p]=1;
	  b--;
	}
      else
	if(sup[p]>dem[q])
	  { sum=sum+c[p][q]*dem[q];
	    sup[p]-=dem[q];
	    cf[q]=1;
	    d--;
	  }
	else
	  if(sup[p]==dem[q])
	    { sum=sum+c[p][q]*sup[p];
	      rf[p]=1;
	      cf[q]=1;
	      b--;
	      d--;
	    }
      printf("\n %d",sum);
    }
  printf("\n\n  %d",sum);
}
