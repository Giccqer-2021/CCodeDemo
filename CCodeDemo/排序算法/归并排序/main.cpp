#include <iostream>

using namespace std;

void mer(int data[],int low,int mid,int high)
{
    int i,p,k;
    int *tmp;
    tmp = (int *)malloc((high-low+1)*sizeof(int));
    if(!tmp)
    {
        exit(0);
    }
    k=0;
    for(i=low,p=mid; i<mid&&p<=high;)
    {
        if(data[i]<data[p])
        {
            tmp[k++]=data[i++];
        }
        else
        {
            tmp[k++]=data[p++];
        }
    }
    while(i<mid)
    {
        tmp[k++]=data[i++];
    }
    while(p<=high)
    {
        tmp[k++]=data[p++];
    }
    i=low;
    p=0;
    while(p<k)
    {
        data[i++]=tmp[p++];
    }
    free(tmp);
}
void mergesort(int data[],int s,int t)
{
    int m;
    if(s<t)
    {
        m=(s+t)/2;
        mergesort(data,s,m);
        mergesort(data,m+1,t);
        mer(data,s,m+1,t);
    }
}
int main()
{
    int a[]= {1,2,8,6,12,11,8,14,9,13};
    mergesort(a,0,9);
    for(int i=0; i<10; i++)
    {
        cout<<a[i]<<" ";
    }
}
