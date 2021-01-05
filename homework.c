/* David Rogers
Write a program that estimates the value of a definite integral of a function f(x) over a given interval
[a, b]
The program should support three functions such as:
1. A polynominal function f(x) = ∑ ni=0 a i x i
2. f(x) = e kx
3. f(x) = ln⁡(x)

X-1983*/

#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>


int integral_1 ();
int integral_2 ();
int integral_3 ();
int rangefun(int *min_range, int *max_range );


int main(){
	
	int integration_choice;
	int *min_range, *max_range;

	printf("please specify which function you would like to integrate\n \
		number 1: sum from i = 0 to n (ax^i)\n \
		number 2: e^kx\n \
		number 3: ln(x)\nChoice: ");
	scanf("%d", &integration_choice);
	while (integration_choice < 0 || integration_choice > 3 ){
		printf("!!!please enter a valid choice!!!\n");
		scanf("%d", &integration_choice);
	}

	switch(integration_choice) {                                                     // choose which case to run
		case 1:
			integral_1 ();
		break;
		case 2:
			integral_2 ();
		break;
		case 3:
			integral_3 ();
		break;
	}
}


int integral_1 (){
	
	int k, l, m, preans, q , a, n , min_range, max_range, range, integral;            // declare variables
	int *ans;
	
	printf("please enter a value of a: ");                                            // ask users for values of a and n
	scanf("%d", &a);
	printf("please enter a value of n: ");
	scanf("%d", &n);

	rangefun(&min_range, &max_range);                                                 // rangefun returns user input in pointer

	range = max_range - min_range;

	int (*j)[range] = malloc(sizeof(int[range][n]));                                  // malloc for 1d and 2d arrays
	ans = malloc((range + 1) * sizeof(int));

	for((min_range); min_range <= (max_range); min_range++) {                         // loop determines value of y
		for(int i = 0; i <= n; i++)                                                     // for individual pieces of the equation
			j[k][i-1] = a * pow(min_range, i);                                            // ie. 3x = y 3x^2 = y2 etc
		k++;
	}

	for (int i = 0; i <= range; ++i)                                                   // sums up all the y values to the nth variable
		for (int x = 0; x <= n; ++x) {                                                   // stores them in a new array with x as index
			l = j[i][x - 1];                                                               // and y as the value of index
			ans[i] = ans[i] + l;			
		}

	l = 0;                                                                              // reset variable l

	for(int i = 1; i < range; i++)                                                      // add up values from n=1 to n=n-1
		l = ans[i] + l;

	integral = 0.5 * ((ans[range] + ans[0]) + (2 * l));                                 // find area using .5*((n0 + n) + 2(sum of other n values))
                                                                                      // .5*((n0 + n) + 2(sum of other n values))
	printf("integral = %d\n", integral );                                               // print value   
	
	free(ans);
	free(j);
}


int integral_2 () {                                                                    // process repeats for different functions
                                                                                       // the only difference being 1d arrays only
	double *ans;
	int l, c, k, integral, min_range, max_range, range, j;

	rangefun(&min_range, &max_range);

	printf("please enter a value of k: ");
	scanf("%d", &k);

	range = max_range - min_range;
	ans = malloc((range + 1) * sizeof(double));

	for(min_range; min_range <= max_range; min_range++) {
		j = k * min_range;
		ans[c] = exp(j);
		c++;
	}

	for(int i = 1; i < range; i++) 
		l = ans[i] + l;

	integral = 0.5 * ((ans[range] + ans[0]) + (2 * l));

	printf("integral = %d\n", integral );

	free(ans);
}


int integral_3 () {

	double *ans;
	int l, c, min_range, max_range, range, integral;

	rangefun(&min_range, &max_range);

	while(min_range < 1) {
		printf("please enter a value greater than 0\n");
		scanf("%d", &min_range);
	}

	range = max_range - min_range;
	ans = malloc((range + 1) * sizeof(double));
	c = 0;

	for(min_range; min_range <= max_range; min_range++) {
		ans[c] = log(min_range);
		c++;
	}

	for(int i = 1; i < range; i++) 
		l = ans[i] + l;

	integral = 0.5 * ((ans[range] + ans[0]) + (2 * l));

	printf("integral = %d\n", integral );

	free(ans);
}

int rangefun(int *min_range, int *max_range) {

	printf("please enter the range\nfrom: ");
	scanf("%d", min_range);
	printf("to: ");
	scanf("%d", max_range);
}
