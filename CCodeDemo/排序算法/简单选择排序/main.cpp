#include <iostream>

using namespace std;

void insertSort(int data[],int n)
{
    int i,j,k,temp;
    for(i=0; i<n-1; i++)
    {
        k=i;
        for(j=i+1; j<n; j++)
        {
            if(data[j]<data[k])
            {
                k=j;
            }
        }
        if(k!=i)
        {
            temp = data[i];
            data[i]=data[k];
            data[k]=temp;
        }
    }
}
int main()
{
    int a[] = {1,7,9,11,4,12,8,3,7,13};
    insertSort(a,10);
    for(int i=0; i<10; i++)
    {
        cout<<a[i]<<" ";
    }
}
