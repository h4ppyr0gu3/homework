#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int integral_1 (int min_range, int max_range, int a, int n);
int integral_2 ();
int integral_3 ();
int recursive ( int x, int n, int a);


int main(){
	
	int integration_choice;

	printf("please specify which function you would like to integrate\n \
		number 1: sum from i = 0 to n (ax^i)\n \
		number 2: e^kx\n \
		number 3: ln(x)\nChoice: ");
	scanf("%d", &integration_choice);
	while (integration_choice < 0 || integration_choice > 3 ){
		printf("!!!please enter a valid choice!!!\n");
		scanf("%d", &integration_choice);
	}

	switch(integration_choice) {
		case 1:
		integral_1 (-10, 3,3,3);
		break;
		case 2:
		integral_2 ();
		break;
		case 3:
		integral_3 ();
		break;
		default:
		printf("invalid selection");
		break;
	}

}

int integral_1 (int min_range, int max_range, int a, int n){
	//write function
	int j[1000][1000], ans[10000], final[10000];
	int k, l, m, preans, q; 
	//take value of n in loop 
	// write a + ax + ax^2 ... + ax^n

	int range = max_range - min_range;
	k = 0;

	for(min_range; min_range <= max_range; min_range++) {


		for(int i = 0; i <= n; i++) {
			j[k][i] = a * pow(min_range, i);
			// j[k][i] = j[k][i] * a;
			printf("%d\n",j[k][i] );
		}
		k++;	
	}
	for (int i = 0; i < range; ++i) {
		for (int x = 0; x <= n; ++x) {
			printf("%d\t",j[i][x] );
		}
		printf("\n");
	}
}
int integral_2 () {

}

// integral of ln(x) where integral = xln(x) - x
int integral_3 () {

	int min_range, max_range, positive_area, negative_area, total_area;

	printf("please choose the range of x where x >= 0\n");
	printf("please specify the range\nfrom: ");
	scanf("%d", &min_range);
	while (min_range < 0) {
		printf("!!!please make a valid selection!!!\n");
		scanf("%d", &min_range);
	}
	printf("to: ");
	scanf("%d", &max_range); 

	if (min_range < 1 && max_range > 1) {
		negative_area = -1;
		positive_area = ((max_range * log((double)max_range)) - max_range);
		total_area = negative_area + positive_area;
		printf("%d,%d,%d\n", total_area, positive_area, negative_area);
	}
	else if (min_range >= 1) {
		negative_area = 0;
		positive_area = ((max_range * log((double)max_range)) - max_range) - ((min_range * log((double)min_range)) - min_range);
		total_area = negative_area + positive_area;
		printf("%d,%d,%d\n", total_area, positive_area, negative_area);
	}
	else if (min_range = max_range) {
		positive_area = ((max_range * log((double)max_range)) - max_range);
		negative_area = ((min_range * log((double)min_range)) - min_range);
		total_area = negative_area - positive_area;
		printf("%d,%d,%d\n", total_area, positive_area, negative_area);
	}
}

