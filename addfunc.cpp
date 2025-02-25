#include<iostream>
#include<cstring>
using namespace std;

long long func(int *p,int x,int y)
{
	long long s=0;
	for(int i=x;i<=y;i++)
	{
		s=(s*10+p[i]);
	}
	//cout<<s<<" ";
	return s;
}

//0->48
int main() 
{
	char n[20];
	cin>>n;
	int len=strlen(n);
	int k=0;
	int a[100];
	long long b[1000000]= {0};
	for(int i=0; i<len; i++) 
	{
		a[i]=(int)(n[i]-48);
		//cout<<a[i]<<" ";
	}
	//cout<<len<<endl;
	for(int i=0;i<len-1; i++) 
	{
		for(int j=0;j<len-1;j++)
		{
			for(int m=0;m<len-1;m++)
			{
				//cout<<i<<" "<<j<<" "<<m<<endl;
				if(i<j&&j<m)
				{
					b[k]=func(a,0,i)+func(a,i+1,j)+func(a,j+1,m)+func(a,m+1,len-1);
					//cout<<b[k]<<endl;
					k++;
				}
			}
			
		}
	}
	for(int i=0;i<k;i++) 
	{
		for(int j=k-1;j>i;j--) 
		{
			if(b[j]>b[j-1]) 
			{
				long long temp=b[j];
				b[j]=b[j-1];
				b[j-1]=temp;
			}
		}
	}
	for(int i=0;i<k; i++) 
	{
		cout<<b[i]<<" ";
	}
	return 0;
}