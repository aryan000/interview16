#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
char a[1000002];
int t,l,s,i,j,flag,r;
scanf("%d\n",&t);
while(t--)
{
gets(a);
l=strlen(a);
s=0;
flag=0;
for(i=0;i<l;i++)
{
                if(a[i]!='9')
                {
                flag=1;             
                break;
                }
                }
                if(flag==0)
                {
                a[0]='1';
                a[l]='1';
                a[l+1]='\0';
                for(r=1;r<l;r++)
                {
                a[r]='0';
                }
                printf("%s\n",a);
                }
else
{               
for(i=0;i<=l/2;i++)
{
if(a[i]>a[l-i-1])
{
s=1;                   
a[l-i-1]=a[i];
}
else if(a[i]<a[l-i-1])
{
s=2;
a[l-i-1]=a[i];
}
}
if(s==1)
printf("%s\n",a);
else
{
if(l%2==0)
j=l/2 - 1;
else
j=l/2;
while(a[j]=='9')
{
                a[j]='0';
                a[l-j-1]='0';
                j--;
                }
                a[j]++;
                a[l-j-1]=a[j];
                printf("%s\n",a);
                }
                }
                }
                return(0);


        }