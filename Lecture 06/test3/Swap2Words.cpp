#include<iostream>
using namespace std;
#include<cstring>
#include<stdio.h>

void reverse( char *str , int first , int last)
   {	
   		
   		char ch;
   		int end = last;
   		for(int i =first; i<=(first+last)/2;i++)
   		{
   			ch = str[i];
   			str[i] = str[end];
   			str[end] = ch;
   			end--;

   		}

   		return ;
   }

void reverse_word(char *str ,int first , int last)
{	

	// cout<< first << " and " << last << endl;
	int start = first,i ;
	for( i =first;i<=last;i++)
	{	
		if( str[i]!=' ')
			continue;

		// cout<< start << " and "  << i << endl;
		reverse(str,start,i-1);
		start = i+1;

	}
	reverse(str,start,last);
}



void swapstring(char *input , char*swap1, char*swap2)
{	
	int swap1firstindex = 0 , swap2lastindex =0 , swap1lastindex=0 , swap2firstindex=0;

   for(int i = 0;input[i]!='\0';i++)
   {	
   	  if(input[i]==swap1[0])
   	  {  
   	  	int j;
   	  	 for(  j = 0; swap1[j]!='\0';j++)
   	  	 {	 if(input[i+j]!=swap1[j])
   	  	 		break;

   	  	 }
   	  	 
   	  	 if(j==strlen(swap1))
   	  	 	{
   	  	 		swap1firstindex = i;
   	  	 		swap1lastindex = i+j-1;
   	  	 	}
   	  }// end of if

   	  if(input[i]==swap2[0])
   	  {  
   	  		int j;
   	  	 for( j = 0; swap2[j]!='\0';j++)
   	  	 {	 
   	  	 	if(input[i+j]!=swap2[j])
   	  	 		break;
   	  	 }
   	  	 if(j==strlen(swap2))
   	  	 	{
   	  	 		swap2lastindex = i+j-1;
   	  	 		swap2firstindex = i;
   	  	 	}
   	  }// end of if

   } 

   if(swap1firstindex<swap2firstindex)
   		{reverse(input,swap1firstindex,swap2lastindex);
   			reverse_word(input,swap1firstindex,swap2lastindex);
   		}

	else
		{
			reverse(input,swap2firstindex,swap1lastindex);
			reverse_word(input,swap2firstindex,swap1lastindex);
		}
   
   
   


return;
}



int main()
{
	char input[100] ;
	char swap1[100];
	char swap2[100];

	gets(input);
	gets(swap1);
	gets(swap2);

	swapstring(input,swap1,swap2);

	cout<< input<< endl;


	return 0;
}