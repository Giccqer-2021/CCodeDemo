#include <iostream>

using namespace std;

void insertSort(int data[],int n)
{
    int i,j,temp;
    for(i=1; i<n; i++)
    {
        if(data[i] <data[i-1])
        {
            temp = data[i];
            data[i]=data[i-1];
            for(j=i-2; j>=0&&data[j]>temp; j--)
            {
                data[j+1]=data[j];
            }
            data[j+1]=temp;
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
