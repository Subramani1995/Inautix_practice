# Inautix_practice
This repository contains Inautix_practice problems ( most of them are solved in C)

/*iNautix Test-5
1)	Prime or Not 
Complete the function isPrime that has one parameter, an integer n. The function should return 1 if n is a prime number otherwise, it should return the smallest factor of n, greater than one.
 
Input Format
The input consists of single integer n.
 
Constraints
2 ≤ n ≤ 1012
 
Output Format
The function should return 1 if n is a prime number otherwise, it should return the smallest factor of n, greater than one.
 
Sample Input 1
2
 
Sample Output 1
1
 
Explanation 1
As 2 is a prime number, so the function returns 1.
 
Sample Input 2
4
 
Sample Output 2
2
 
Explanation 2
As 4 is not a prime number, so the function returns 2, the smallest factor of 4.
*/
Solution:

#include<stdio.h>
#include<stdlib.h>
int isPrime(long );
int main()
{
    long int n;
    scanf("%ld",&n);
    int ans=isPrime(n);
    printf("%d",ans);
    return 0;
}

int isPrime(long int n)
{
    int i;
    int end=n/2 + 1;    //for optimization checking upto end value is enough
    for(i=2;i<end;i++)
    {
        if(n%i==0)
        {
            return i;           //if the number is divisible by i return the value of i. it is not prime
        }
    }
    return 1;               //return 1 since the number was not divisible by any i
}


/*2)	Last and  Second last 
Complete the lastLetter function in your editor. It has 1 parameter:
1.	A string, word.
 
It must return a string containing the last character and the last but one character in word with a space between them.
 
Input Format
The locked stub code in your editor reads the following input from stdin and passes it to your function:
The first line contains a string word.
 
Constraints:
•	1 ≤ length of string ≤ 100
 
Output Format:
Your function must return a string containing the last character and the last but one character in word with space between them. This is printed to stdout by the locked stub code in your editor.
 
Sample Input 1
APPLE
 
Sample Output 1
E L
 
Explanation
Sample Case 1: Last letter in APPLE is E and last but one letter is L.
*/
Solution:

#include<stdio.h>
#include<string.h>
char *last_2(char *);
int main()
{
    char str[100],*ans;
    scanf("%s",str);
    ans=last_2(str);
    printf("%s",ans);
    return 0;
}
char *last_2(char *str)
{
    char *ans;
    ans=(char *)malloc(4*sizeof(char));
    int len=strlen(str);
    ans[0]=str[len-1];
    ans[1]=' ';
    ans[2]=str[len-2];
    ans[3]='\0';
    return ans;
}


/*3)	Pascal's Triangle

Pascal’s Triangle
1
1 1
1 2 1
1 3 3 1
1 4 6 4 1
1 5 10 10 5 1
1 6 15 20 15 6 1
....
 
The rth column of nth row of the Pascal's Triangle is n! / ( r! x (n - r)! ). Note that the value of n starts from 0 and nth row has (n + 1) entries, i.e., 0 ≤ r ≤ n.
 
Complete the function pascalTriangle, that has one parameter- an integer k. The function should print first k rows of Pascal's Triangle, and the entries of a row must be printed separated by space.
 
Input Format
The input consists of single integer, k.
 
Constraints
2 ≤ k ≤25
 
Output Format
Print first k rows of the Pascal's Triangle (n = 0 to k - 1).
 
Sample Input
4  
 
Sample Output
1  
1 1  
1 2 1  
1 3 3 1
 
Explanation
The first row is n = 0 and r = 0.
The second row is n = 1 and r = 0 to 1.
The third row is n = 2 and r = 0 to 2.
The fourth row is n = 3 and r = 0 to 3.
*/
Solution:

#include<stdio.h>
void pascal(int );
int main()
{
    int n;
    scanf("%d",&n);
    pascal(n);
    return 0;
}
void pascal(int n)
{
    int i,v,j;
    for(i=0;i<n;i++)
    {
        v=1;
        for(j=0;j<=i;j++)
        {
            printf("%d ",v);
            v= v * (i-j)/(j+1);             //mathematical expression that produces pascal terms
        }
        printf("\n");
    }
}




