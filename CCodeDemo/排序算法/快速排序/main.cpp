#include <iostream>

using namespace std;

int part(int data[],int low,int high)
{
    int i,j,pivot;
    pivot = data[low];
    i=low;
    j=high;
    while(i<j)
    {
        while(i<j&&data[j]>=pivot)
        {
            j--;
        }
        data[i]=data[j];
        while(i<j&&data[i]<=pivot)
        {
            i++;
        }
        data[j]=data[i];
    }
    data[i]=pivot;
    return i;
}
void quicksort(int data[],int low,int high)
{
    if(low < high)
    {
        int loc = part(data,low,high);
        quicksort(data,low,loc-1);
        quicksort(data,loc+1,high);
    }
}
int main()
{
    int a[]= {1,2,8,6,12,11,8,14,9,13};
    quicksort(a,0,9);
    for(int i=0; i<10; i++)
    {
        cout<<a[i]<<" ";
    }
}
