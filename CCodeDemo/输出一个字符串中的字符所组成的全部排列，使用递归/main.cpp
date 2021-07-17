#include <iostream>
#include <string.h>

using namespace std;

void swapstr(char *str,int i,int j)
{
    char c;
    c= str[i];
    str[i] = str[j];
    str[j] =c;
}
void permutation(char *str,int i,int j){
    if(i + 1 == j){
        printf("%s\n",str);
    }else{
        for(int k =0;k<j;k++){
            swapstr(str,i,k);
            permutation(str,i+1,j);
            swapstr(str,i,k);
        }
    }
}
int main()
{
    char s[] = "abcde";
    permutation(s,0,strlen(s));
}
