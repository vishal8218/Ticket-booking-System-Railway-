#include<iostream>
#include<stdio.h>
using namespace std;
int partitaion( long int arr[], int f,int l)
	{ 
		 long int x=arr[l];
		int  i=f-1;
		for(register int j=f;j<=l-1;j++)
		{
			if(arr[j]<x)
			{
				i++;
				long  int s=arr[i];
				arr[i]=arr[j];
				arr[j]=s;	
			}
			else if(arr[j]==x)
			continue;
		}
	arr[l]=arr[i+1];
	arr[i+1]=x;
	return (i+1);
}
	void q_s(long int ar[], int p1 , int r1)
	{

		while (p1<r1)
		{
			int  q= partitaion(ar,p1,r1);
			if(r1-q>q-p1)
			{
			q_s(ar,p1,q-1);
			p1=q+1;
		    }
			else
			{
	     	q_s(ar,q+1,r1);
	     	r1=q-1;
	        }   
	   }
    } 
int main()
{
    int n;
    scanf("%d",&n);
  long int   a[n];
for( register int i=0;i<n;i++)
scanf("%ld",&a[i]);
q_s(a,0,n-1);
for(register int i=0;i<n;i++)
printf("%ld ",a[i]);
	return 0;
}
