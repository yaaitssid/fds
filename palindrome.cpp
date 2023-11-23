/* Group 10 - Palindrome
A palindrome is a string of character that‘s the same forward and backward. Typically, punctuation, capitalization, and spaces are ignored. For example, ‖Poor Dan is in a droop‖ is a palindrome, as can be seen by examining the characters ―poor danisina droop‖ and observing that they are the same forward and backward. One way to check for a palindrome is to reverse the characters in the string and then compare with them the original-
in a palindrome, the sequence will be identical. Write C++ program with functions-
1. To check whether given string is palindrome or not that uses a stack to determine whether a string is a palindrome.
2. To remove spaces and punctuation in string, convert all the Characters to lowercase, and then call above Palindrome checking function to check for a palindrome
3. To print string in reverse order using stack*/

#include<iostream>
#include<string.h>
#define max 30
using namespace std;

class MYSTACK
{
	private:
		char a[max];
		int top;

	public:
		MYSTACK()
		{
			top=-1;
		}

		void push(char);
		void reverse_string();
		void convert(char[]);
		void palindrome();
};

void MYSTACK::push(char c)
{
	top++;
	a[top] = c;
	a[top+1]='\0';
}

void MYSTACK::reverse_string()
{
	char str[max];

	cout<<"\n\nReverse string is : ";

	for(int i=top,j=0; i>=0; i--,j++)
	{
		cout<<a[i];
		str[j]=a[i];
	}

	cout<<endl;
}

//ASCII a to z = 97 to 122 , A to Z = 65 to 90
void MYSTACK::convert(char str[])
{
	int j,k,len = strlen(str);

	for(j=0, k=0; j<len; j++)
	{
		if( ( (int)str[j] >= 97 && (int)str[j] <=122 ) || ( (int)str[j] >= 65 && (int)str[j] <=90 ))    // to check char is alphabet small or capital
		{
			if( (int)str[j] <=90 )    //check char is Capital letter
			{
				str[k] = (char)( (int)str[j] + 32 );   //convert capital to small letter by adding 32
			}else
			{
				str[k] = str[j];   // if char is small then add as it is
			}

			k++;
		}
	}
	str[k]='\0';

	cout<<endl<<"Converted String : "<<str<<"\n";
}



void MYSTACK::palindrome()
{
	char str[max];
	int i,j;

	for(i=top,j=0; i>=0; i--,j++)
	{
		str[j]=a[i];
	}
	str[j]='\0';


	if(strcmp(str,a) == 0)
		cout<<"\n\nString is palindrome...";
	else
		cout<<"\n\nString is not palindrome...";
}


int main()
{
	MYSTACK stack;

	char str[max];
	int i=0;

	cout<<"\nEnter string to be check : \n\n";

	cin.getline(str , 50);

	stack.convert(str);

	while(str[i] != '\0')
	{
		stack.push(str[i]);
		i++;
	}

	stack.palindrome();

	stack.reverse_string();

}
