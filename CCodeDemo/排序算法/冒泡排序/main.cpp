#include <iostream>

using namespace std;

void insertSort(int data[],int n)
{
    int i,j,temp,tag=1;
    for(i=1; tag&&i<n; i++)
    {
        tag=0;
        for(j=0; j<n-1; j++)
        {
            if(data[j]>data[j+1])
            {
                temp = data[j];
                data[j+1]=data[j];
                data[j]=temp;
                tag=1;
            }
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
