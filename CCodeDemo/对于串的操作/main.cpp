#include <iostream>

using namespace std;

//Çó´®³¤
int strlen(char *s)
{
    int n=0;
    while(s[n]!='\0')
    {
        n++;
    }
    return n;
}
//´®¿½±´
char *strcpy(char *first,char *second)
{
    int i=0;
    while(second[i]!='\0')
    {
        first[i]=second[i];
        i++;
    }
    first[i]='\0';
    return first;
}
//´®±È½Ï
int strcmp(char *s1, char *s2)
{
    int i=0;
    while(s1[i]!='\0'||s2[i]!='\0')
    {
        if(s1[i]==s2[i])
        {
            i++;
        }
        else
        {
            return s1[i]-s2[i];
        }
    }
    return 0;
}
//´®Æ¥Åä
int index(char s[],char t[],int pos)
{
    int i=pos,j=0;
    int slen = strlen(s),tlen=strlen(t);
    while(i<slen&&j<tlen)
    {
        if(s[i]==t[j])
        {
            i++;
            j++;
        }
        else
        {
            i=i-j+1;
            j=0;
        }
    }
    if(j>=tlen)
    {
        return i-tlen;
    }
    return -1;
}
//main
int main()
{
    cout<<"´®³¤£º"<<endl;
    char *s1 = "HelloJava!";
    cout<<strlen(s1)<<endl;
    cout<<"´®¿½±´£º"<<endl;
    char cs[11];
    strcpy(cs,s1);
    cout<<cs<<endl;
    cout<<"´®±È½Ï£º"<<endl;
    char *s2="HelloPython!";
    cout<<strcmp(s1,s2)<<endl;
    cout<<"´®Æ¥Åä£º"<<endl;
    char *s3="Java";
    cout<<index(s1,s3,0)<<endl;
}
