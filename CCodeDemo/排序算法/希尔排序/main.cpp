#include <iostream>

using namespace std;

void insertSort(int a[],int n,int sp)
{
    int i,j,t;
    for(i=0; i<n-sp; i++)
    {
        for(j=i; j<n-sp; j+=sp)
        {
            if(a[j]>a[j+sp])
            {
                t=a[j];
                a[j]=a[j+sp];
                a[j+sp]=t;
            }
        }
    }
}
void shellsort(int a[],int n,int d[],int dn)
{
    int i;
    for(i=0; i<dn; i++)
    {
        insertSort(a,n,d[i]);
    }
}
int main()
{
    int a[]= {1,2,8,6,12,11,8,14,9,13};
    int d[]= {5,3,1};
    shellsort(a,10,d,3);
    for(int i=0; i<10; i++)
    {
        cout<<a[i]<<" ";
    }
}
