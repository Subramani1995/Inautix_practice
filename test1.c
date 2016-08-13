# Inautix_practice
This repository contains Inautix_practice problems ( most of them are solved in C)

/*iNautix Selection Test-1		
1)	PowerSum
You are given two integers, l and r. Find the number of integers x such that l <= x <= r, and x is a Power Number.
A Power Number is defined as an integer that can be represented as sum of two powers, i.e.
•	x = a^p + b^q,
•	a, b, p and q are all integers, 
•	a, b = 0, and
•	p, q > 1.
 
You have to complete function int countPowerNumbers(int l, int r), which takes the arguments l and r and returns the result as described above. The code to process input and output is already provided.

Constraints:
•	0= l = r = 5,000,000
 
Input Format:
Complete the function "countPowerNumbers"  which contains two integers as its arguments, l and r respectively.
 
Output Format:
Return a single integer representing the required result. 
 
Sample Input #00:
l = 0
r = 1
Sample Output #00:
2
 
Explanation #00:
0 and 1 both are Power Numbers. 0 = 0^2+02. 1 = 1^2+0^2.
 
Sample Input #01:
l = 25
r = 30
Sample Output #01:
5
 
Explanation #01:
Except 30, all are Power Numbers.
•	25 = 5^2 + 0^2,
•	26 = 5^2 + 1^2,
•	27 = 3^3 + 0^2,
•	28 = 3^3 + 1^2,
•	29 = 5^5 + 2^2.
 
*/
Solution:
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
//  power sum
int countPowerNumbers(int ,int );
int main()
{ 
    int a,b;
    scanf("%d %d",&a,&b);
    int result=countPowerNumbers(a,b);
    printf("%d",result);
    return 0;
}
int countPowerNumbers(int a,int b)
{
    int base1,base2,power1,power2,count=0,flag,i;
    int max=(a>b)?a:b;
    for(i=a;i<=b;i++)
    {
        flag=0;
        for(base1=0;base1<=max;base1++)
        {
            for(base2=0;base2<=max;base2++)
            {
                for(power1=2;power1<=max;power1++)
                {
                    for(power2=2;power2<=max;power2++)
                    {
                        if(i == pow(base1,power1)+pow(base2,power2))            //checking whether 'i' is a power 											number or not?
                        {
                           // printf("%d^%d + %d^%d = %d\n",base1,power1,base2,power2,i);
                            flag=1;                                            //if it is a power number increment 										the count variable and break all 										the loops using flag variable
                            count++;
                            break;
                        }
                        if(flag==1)
                            break;
                    }
                    if(flag==1)
                        break;
                }
                if(flag==1)
                    break;
            }
            if(flag==1)
                break;
        }
    }
    return count;
}

