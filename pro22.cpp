//Author:- Jaymin Parmar
//Id:- 201701203
//Description:- to check if an array of integers contains contiguous integers (duplicate entry allowed).

#include<iostream>
#include<string.h>

using namespace std;

int main()
{
	int i,j,k,n,min,temp,temp2,count=0;
	cout<<"Enter The Size of array=";
	cin>>n;
	int* a;
	a=new int[n];
	cout<<"Enter array=";
	for(i=0;i<n;i++)
	{
		cin>>a[i];
	}
	for(i=0;i<n;i++)
	{
		min=a[i];
		temp2=min;
		for(j=i;j<n;j++)
		{
			if(min>a[j])
			{
				min=a[j];
				k=j;
			}
		}
		if(min!=temp2)
		{
			temp=a[i];
			a[i]=a[k];
			a[k]=temp;
		}
	}
	for(i=0;i<n;i++)
	{
		if(a[i+1]-a[i]>1)
		{
			count++;
		}
	}
	if(count!=0)
	{
		cout<<"This array of integers doesn't contain contiguous integers "<<endl;
	}
	else
	{
		cout<<"This array of integers contains contiguous integers"<<endl;
	}
}
