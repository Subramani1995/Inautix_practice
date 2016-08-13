# Inautix_practice
This repository contains Inautix_practice problems ( most of them are solved in C)

/*iNautix Test 10

1)	Java Exception

Problem Statement
The MyCalculator class and int power(int,int) method are provided for you in the editor. The power(int,int) method has two parameters, n and p, and either calculates and returns np or throws an exception in the event that one or both arguments passed to it are negative.
 
Complete the main method in the Solution class so it performs the following tasks:
•	Use the Scanner class to read successive lines of two space-separated integers (in the form n p) from STDIN until no more input is detected.
•	Print a line of output for each line of input. If n ≥ 0 and p ≥ 0, it prints np; otherwise, it prints java.lang.Exception: n and p should be non-negative.
 
Input Format
Each line consists of two space-separated integers, n and p, respectively; continue scanning input until no more input is detected.
 
Output Format
For each line of input, print the corresponding output (see Problem Statement above) on a new line.
 
Sample Input 0
3 5
2 4
-1 -2
-1 3
 
Sample Output 0
243
16
java.lang.Exception: n and p should be non-negative
java.lang.Exception: n and p should be non-negative
 
Explanation
In the first two lines, n and p are positive so the value of np is printed.
In the third line, both n and p are negative and an exception is thrown.
In the fourth line, n is negative and an exception is thrown.
*/
Solution:
class Solution 
{
    public static void main(String []argh) 
    {
        Scanner in=new Scanner(System.in);
        int n[]=new int[20];
        int p[]=new int[20];
        for(int i=0;in.hasNext();i++)
        {
            n[i]=in.nextInt();
            p[i]=in.nextInt();
            
            
               if(n[i]>=0 &&p[i]>=0)
                {
                    System.out.println((int)Math.pow(n[i],p[i]));
                } 
                else
                {
                   System.out.println("java.lang.Exception: n and p should be non-negative"); 
                  
                }
         }
     }
}


/*2)	Pangram 

A pangram is a word or sentence that contains every letter of the alphabet.
For example : the quick brown fox jumps over the lazy dog. Nicole wants to improve her typing speed for programming contests, and she thinks that practicing typing pangrams is the best way to do it.
Given N strings comprised of lowercase letters (a - z) and spaces, determine whether or not they are pangrams.
Complete the isPangram function, which takes an array of N strings (S0, S1, ..., SN-1) as a parameter and returns a string of N binary characters. Each character i of the returned string should be a 1 if string Si is a pangram or 0 if it is not.
 
Input Format
The locked code in your editor assembles the following input and passes it to the isPangram function:
The first line contains an integer N, the number of strings. Each line i (where 0 ≤ i < N) of the N subsequent lines contains a string, Si.
 
Constraints
•	1 ≤ N ≤ 100
•	Each string Si (where 0 ≤ i < N) is composed of lowercase letters and spaces.
•	1 ≤ |Si| ≤ 105, where |Si| is the length of string Si.
 
Output Format
The isPangram function must return a binary string of length N in which each character i (where 0 ≤ i < N) denotes whether or not input string Si is a pangram.
 
Sample Input 1
4
we promptly judged antique ivory buckles for the next prize
we promptly judged antique ivory buckles for the prizes
the quick brown fox jumps over the lazy dog
the quick brown fox jump over the lazy dog
 
Sample Output 1
1010
 
Sample Input 2
4
cfchcfcvpalpqxenhbytcwazpxtthjumliiobcznbefnofyjfsrwfecxcbmoafes tnulqkvx
oxhctvhybtikkgeptqulzukfmmavacshugpouxoliggcomykdnfayayqutgwivwldrkp
gpecfrak zzaxrigltstcrdyhelhz rasrzibduaq  cnpuommogatqem
hbybsegucruhxkebrvmrmwhweirx mbkluwhfapjtga liiylfphmzkq
 
Sample Output 2
0000
 
Explanation
Sample Case 1:
S0 = we promptly judged antique ivory buckles for the next prize
S1 = we promptly judged antique ivory buckles for the prizes
S2 = the quick brown fox jumps over the lazy dog
S3 = the quick brown fox jump over the lazy dog
Only S0 and S2 are pangrams.
Sample Case 2:
S0 = cfchcfcvpalpqxenhbytcwazpxtthjumliiobcznbefnofyjfsrwfecxcbmoafes tnulqkvx
S1 = oxhctvhybtikkgeptqulzukfmmavacshugpouxoliggcomykdnfayayqutgwivwldrkp
S2 = gpecfrak zzaxrigltstcrdyhelhz rasrzibduaq  cnpuommogatqem
S3 = hbybsegucruhxkebrvmrmwhweirx mbkluwhfapjtga liiylfphmzkq
No string in the array is a pangram.
*/
Solution:

#include<stdio.h>
#include<string.h>
char *pangram(int size,char **strings);
int main()
{
    int n,i;
    scanf("%d",&n);
    char **strings=(char **)malloc(n*sizeof(char *)),*result;
    for(i=0;i<n;i++)
    {
        strings[i]=(char *)malloc(100 * sizeof(char));
        scanf("%s",strings[i]);
    }
    result=pangram(n,strings);
    printf("%s",result);
    return 0;
}

char *pangram(int n,char **str)
{
    
    char *res=(char *)malloc(n*sizeof(char));
    int i,x;
    for(i=0;i<n;i++)
    {
        int j,a[26]={0};                    //initialize an array for 26 alphabets pointing to zero
        int len=strlen(str[i]),flag=0;
        for(j=0;j<len;j++)
        {
            a[str[i][j]-'a']++;             //whenever an alphabet is present in string increment that position
        }
        for(x=0;x<26;x++)
        {
            printf("%d ",a[x]);
            if(a[x]==0)
            {
                flag=1;                     //logic if all positions are incremented -> all letters are present -	>pangram
                break;          
            }
            else
            {
                flag=0;                     //if evene a single 0 is present it means that letter is not present in str. so not pangram
            }
        }
        if(flag==1)
        {
            res[i]='0';
        }
        else
        {
            res[i]='1';
        }
    }
    res[n]='\0';
    return res;
}




