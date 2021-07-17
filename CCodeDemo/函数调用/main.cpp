#include <iostream>
using namespace std;

int f3(int n){
    printf("f3\n");
    return n+10;
}
int f2(int n){
    printf("f2\n");
    return n-1;
}
int f1(int (*f)(int)){
    printf("f1\n");
    int n = 0;
    return f(n);
}
int main()
{
    printf("%d\n",f1(f2));
    printf("%d\n",f1(f3));
}
