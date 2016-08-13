# Inautix_practice
This repository contains Inautix_practice problems ( most of them are solved in C)

/*iNautix Test – 12

1)	Calculate Factorial 
Complete the function factorial in your editor. It has 1 parameter:
1.	An integer, n.
 
It must return the factorial of n. 
 
Input Format
The locked stub code in your editor reads the following input from stdin and passes it to your function:
The first line contains a single integer N.
 
Constraints
•	1 ≤ N ≤ 15
 
Output Format
Your function must return the factorial of n. This is printed to stdout by the locked stub code in your editor.
 
Sample Input 1
2
 
Sample Output 1
2
 
Sample Input 2
3
 
Sample Output 2
6
 
Sample Input 3
4
Sample Output 3
24
 
Explanation 3
Factorial of 4 is 1*2*3*4 = 24.
*/
Solution:

int main()
{
	int n;
	scanf("%d",&n);
	int ans=factorial(n);
	printf("%d",ans);
	return 0;
}
int factorial(int n) {
    if(n==1)
	{
        return 1;
    }
    else{
        return n*factorial(n-1);
    }
}


/*2)	Cup Cake Feast
Sarah loves going to her favorite bakery, Zillycakes, with n dollars to buy cupcakes. Each cupcake has a flat cost of c dollars, and the store has a promotion where they give you 1 free cupcake for every m cupcake wrappers you trade in.
 
For example, if m = 2 and Sarah has n = 4 dollars that she uses to buy 4 cupcakes at c = 1 dollar apiece, she can trade in the 4 wrappers to buy 2 more cupcakes. Now she has 2 more wrappers that she can trade in for 1 more cupcake. Because she only has 1 wrapper left at this point and 1 < m, she was only able to eat a total of 7 cupcakes.
 
Complete the maximumCupcakes function in your editor. It has 1 parameter: an array of strings named trips. Each string in trips contains the following three space-separated values:
1.	An integer, n, denoting the amount of money (in dollars) Sarah can spend during that trip to Zillycakes.
2.	An integer, c, denoting the cost of a cupcake in dollars.
3.	An integer, m, denoting the number of wrappers that can be traded in for one new cupcake.
For each trip to Zillycakes in trips, your function must print an integer denoting the maximum number of cupcakes Sarah can eat on a new line.
 
Input Format
The locked stub code in your editor reads the following input from stdin and passes it to your function:
The first line contains an integer, t, denoting the number of trips Sarah makes to the store (i.e., the size of the trips array).
Each line i of the t subsequent lines contains three space-separated integers describing the respective n, c, and m values for one of Sarah's trips to the store. This corresponds to element i in trips.
 
Constraints
•	1 ≤ t ≤ 103
•	2 ≤ n ≤ 105
•	1 ≤ c ≤ n
•	2 ≤ m ≤ n
 
Output Format
For each trip in trips, your function must print a single integer on a new line denoting the maximum number of cupcakes Sarah can eat during that trip.
 
Sample Input 1
The following argument is passed to your function: trips = ["10 2 5", "12 4 4", "6 2 2"]
 
Sample Output 1
6
3
5
 
Explanation 1
Sarah makes the following three trips to Zillycakes:
1.	She spends 10 dollars on 5 cupcakes at 2 dollars apiece. She then eats them and exchanges all 5 wrappers to get 1 more cupcakes. We print the total number of cupcakes she ate, which is 6.
2.	She spends 12 dollars on 3 cupcakes at 4 dollars apiece; however, she needs 4 wrappers to trade for her next cupcake. Because she only has 3 wrappers, she cannot purchase or trade for any more cupcakes. We print the total number of cupcakes she ate, which is 3.
3.	She spends 6 dollars on 3 cupcakes at 2 dollars apiece. She then exchanges 2 of the 3 wrappers for 1 additional cupcake. Next, she combines her third leftover cupcake wrapper from her initial purchase with the wrapper from her trade-in to do a second trade-in for 1 more cupcake. At this point she has 1 wrapper left, which is not enough to perform another trade-in. We print the total number of cupcakes she ate, which is 5.
 
Sample Input 2
The following argument is passed to your function: trips = ["8 4 2", "7 2 3"]
 
Sample Output 2
3
4
 
Explanation 2
Sarah makes the following three trips to Zillycakes
1.	She spends 8 dollars on 2 cupcakes at 4 dollars apiece. She then eats them and exchanges both of her wrappers for 1 more cupcake. At this point she has 1 wrapper left, which is not enough to perform another trade-in. We print the total number of cupcakes she ate, which is 3.
2.	She spends 6 of her 7 dollars on 3 cupcakes at 2 dollars apiece. She then eats them and exchanges all three of her wrappers for 1 more cupcake. At this point she has 1 wrapper left, which is not enough to perform another trade-in. We print the total number of cupcakes she ate, which is 4.
 
*/
Solution:

void maximumCupcakes(int trips_size, char** trips) {
int i=0,j,k=0,n,c,m,r=0,wraps,rem,flag=0;
    char temp[10];
    for(i=0;i<trips_size;i++){
        flag=0;
        k=0;
        for(j=0;trips[i][j]!='\0';j++){
            if(trips[i][j]!=' ')
            {
                temp[k]=trips[i][j];
                k++;
            }
            else
            {
                temp[k]='\0';
                if (flag==0)
	  {
                    n=atoi(temp);	//conversion of string to integer
                    k=0;
                    flag=1;
                }
                else
	 {
                    c=atoi(temp);
                    k=0;flag=0;
                }
            }
        }
        temp[k]='\0';
        m=atoi(temp);
        r=n/c;
        wraps=r;
        while(wraps>=m)
        {
            r=r+(wraps/m);			//no of chocolates with money
            rem=wraps%m;
            wraps=(wraps/m)+rem;		// no of chocolates with wrappers
        }
        printf("%d\n",r);
    }
}
