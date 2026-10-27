#include<bits/stdc++.h>
using namespace std;

vector<int> Fun(vector<int>a,int n, int max)
{
     vector<int> b(n);
     vector<int> count(max+1);
     for(int i=0;i<=max;i++)
     {
         count[i]=0;
     }
     
     for(int i=0;i<n;i++)
     {
       ++count[a[i]];
     }
     for(int i=1;i<=max;i++)
     {
          count[i]=count[i-1]+count[i];
     }
     for(int i=n-1;i>=0;i--)
     {
        b[--count[a[i]]]=a[i];
     }

     for(int i=0;i<n;i++)
     {
        a[i]=b[i];
     }
return a;
     
}

int main()
{
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    int max=a[0];
    for(int i=1;i<n;i++)
    {
        if(max<a[i])
        {
            max=a[i];
        }
    }

     a=Fun(a,n,max);
     for(int i=0;i<n;i++)
     {
        cout<<a[i]<<" ";
     }


    return 0;
}