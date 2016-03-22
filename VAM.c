#include<stdio.h>
void sort(int a[],int n)
{ int temp,j,k;
  for(j=0;j<n;j++)
    { for(k=j+1;k<n;k++)
	{ if(a[j]>a[k])
	    { temp=a[j];
	      a[j]=a[k];
	      a[k]=temp;
	    }
	}
    }
}
void main()
{ int i,j,b,p,d,k,m,n,c[20][20],cf[20],rf[20],a[20],cp[20],rp[20];
  int sup[20],dem[20],max,min,s,t,sum=0;
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
	printf("\t%d",c[i][j]);
      printf("\t%d",sup[i]);
      printf("\n");
    }
  for(j=0;j<n;j++)
    {
      printf("\t%d",dem[j]);
      rf[i]=0;
      cf[i]=0;
    }
  b=m,d=n;
  while(b>0&&d>0)
    { for(i=0;i<m;i++)
	rp[i]=-1;
      for(i=0;i<n;i++)
	cp[i]=-1;
      for(i=0;i<m;i++)
	{ k=0;
	  if(rf[i]!=1)
	    { for(j=0;j<n;j++)
		{ if(cf[j]!=1)
		    a[k++]=c[i][j];
		}
	      if(k==1)
		rp[i]=a[0];
	      else
		{ sort(a,k);
		  rp[i]=a[1]-a[0];
		}
	    }
	}
      for(i=0;i<n;i++)
	{ k=0;
	  if(cf[i]!=1)
	    { for(j=0;j<m;j++)
		{ if(rf[j]!=1)
		    a[k++]=c[j][i];
		}
	      if(k==1)
		cp[i]=a[0];
	      else
		{ sort(a,k);
		  cp[i]=a[1]-a[0];
		}
	    }
	}
      for(i=0;i<m;i++)
	a[i]=rp[i];
      for(j=0;j<n;j++)
	a[i+j]=cp[j];
      max=a[0];
      p=0;
      for(i=1;i<m+n;i++)
	{ if(max<a[i])
	    {max=a[i];
	      p=i;
	    }
	}
      printf("\n\n     %d %d",max,p);
      min=1000;
      if(p>m-1)
	{ p=p-m;
	  if(cf[p]!=1)
	    { for(i=0;i<m;i++)
		{ if(rf[i]!=1)
		    { if(min>c[i][p])
			{ min=c[i][p];
			  s=i;
			  t=p;
			}
		    }
		}
	    }
	}
      else
	{ if(rf[p]!=1)
	    { for(i=0;i<n;i++)
		{ if(cf[i]!=1)
		    { if(min>c[p][i])
			{ min=c[p][i];
			  s=p;
			  t=i;
			}
		    }
		}
	    }
	}
      printf("\n\n      %d %d %d",min,s,t);
      if(sup[s]<dem[t])
	{ sum+=c[s][t]*sup[s];
	  dem[t]-=sup[s];
	  rf[s]=1;
	  b--;
	}
      else
	if(sup[s]>dem[t])
	  { sum+=c[s][t]*dem[t];
	    sup[s]-=dem[t];
	    cf[t]=1;
	    d--;
	  }
	else
	  if(sup[s]==dem[t])
	    { sum+=c[s][t]*dem[t];
	      cf[t]=1;
	      rf[s]=1;
	      b--;
	      d--;
	    }
    }
  printf("\n\n total cost by VAM = %d\n",sum);
  
}
