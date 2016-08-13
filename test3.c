# Inautix_practice
This repository contains Inautix_practice problems ( most of them are solved in C)

/*iNautix Test - 3
1)	Permutations divisible by 8

You are given an integer N. Is there a permutation of that integer's digits that yields an integer divisible by 8? For example, if the number N = 123, then {123, 132, 213, 231, 312, 321} are the possible permutations and 312 is divisible by 8.
 
Constraints
1 ≤T ≤ 45
0 ≤ N ≤ 10110
 
Input Format
The first line contains an integer T that gives the number of test cases.
T lines follow, each containing one integer N.
 
Output Format
For each test case, print YES if there exists at least one way of re-arranging its digits such that it is divisible by 8, and print NO otherwise.
 
Sample Input #00
2
61
75
 
Sample Output #00
YES
NO
 
Explanation #00
Test case #1: 16 is permutation of 61 which is divisible by 8.
Test case #2: None of permutation of 75, {57, 75}, are divisible by 8.*/
 Solution :

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int z=0;
void ispermuation_divisibleby8(int ,char **);
void swap(char *,char *);
int permute(char [],int,int);

int main()
{
    int n;
    scanf("%d",&n);
    int i;
    char **a=(char **)malloc(n*sizeof(char *));
    for(i=0;i<n;i++)
    {
        a[i]=(char *)malloc(100* sizeof(char));
        scanf("%s",a[i]);
    }
    ispermuation_divisibleby8(n,a);
    return 0;
}
void ispermuation_divisibleby8(int arr_size, char** arr)
{
    int len;
    long ans=0;
    for(int i=0;i<arr_size;i++)
    {
        len=strlen(arr[i]);
        ans=permute(arr[i],0,len-1);        //sending the number, first index,last index to permute function
        if(ans==1)
        {
            printf("YES\n");
        }
        else
        {
            printf("NO\n");
        }
    }
}

void swap(char *a,char *b)          //utility function to swap two variables
{
    char temp;
    temp=*a;
    *a=*b;
    *b=temp;
}

int permute(char arr[],int l, int r)
{
    long i=0,num=0;
    if(l==r)
    {
        num=atoi(arr);                  //converts a string into int
        if(num%8==0)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    else
    {
        for(i=l;i<=r;i++)
        {
            swap((arr+i),(arr+l));          //recursive function to find the permutation of a given number
                                            //for explanation refer: http://www.geeksforgeeks.org/write-a-c-						program-to-print-all- permutations-of-a-given-string/
            z=permute(arr,l+1,r);
            if(z==1)
            {
                return 1;
            }
            swap((arr+i),(arr+i));
        }
    }
    return 0;
}


/*2)	Finding ODD numbers between two digits
To find the odd numbers in between the range.
Input:
2
15
Output:
3 5 7 9 11 13
*/
SOution:

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main()
{
    int a,b,i;
    scanf("%d %d",&a,&b);
    int start=(a%2==0)?(a+1):a;
    for(i=start;i<b;i=i+2)
    {
        printf("%d ",i);
    }
    return 0;
}



