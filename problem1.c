#include <stdio.h>
int main(){
	/* This intializes the string where the name of the file will be */
	char inputFile[100];
	/* This prompts the user to enter the file name */
	printf("Enter the name of the file: \n");
	/* This takes hte input and stores in the string we created previously. */
	scanf("%s", inputFile);
	
	const char* months[] = {
	"January",
	"Feburary",
	"March",
	"April",
	"May",
	"June",
	"July",
	"August",
	"September",
	"October",
	"Novemeber",
	"December"};
	
	/* Read the contents of the file */
	FILE *file = fopen(inputFile, "r");
	float sales_floats[12];

	int i = 0;
	float num;
	while(fscanf(file, "%f", &num) > 0){
		sales_floats[i] = num;
		i++;
	}
	fclose(file);
	
	/* This section prints out the sales report table */
	printf("\n");
	printf("   Monthly sales report for 2022:");
	printf("   \nMonth\tSales\n");

	for(int i = 0; i< 12;i++){
		/* printf("%s", months[i]); */
		printf("%10s\t $%.2f\n", months[i], sales_floats[i]);
		/* printf("\t$%.2f\n",sales_floats[i]); */
	}
	printf("\n");
	/* This section pritns the minimum and maximum sales summary */
	float min_sales = sales_floats[0];
	float max_sales = sales_floats[0];
	float avg_sales = 0;
	for(int i = 0; i < 12; i++){
		if(sales_floats[i] < min_sales){
			min_sales = sales_floats[i];
		};
		if(sales_floats[i] > max_sales){
			max_sales = sales_floats[i];
		}
		avg_sales += sales_floats[i];
	}
	printf("\n");
	printf("Sales summary:\n");
	printf("Minimum sales: $%.2f\n", min_sales);
	printf("Maximum sales: $%.2f\n", max_sales);
	printf("Average sales: $%.2f\n", avg_sales);

	printf("\n");
	printf("Six-month Moving Average Report: \n");
	/* This section wil print the six-month moving average */	
	for(int i = 0; i < 6; i++){
		float six_avg = ((sales_floats[i] + sales_floats[i+1]+ sales_floats[i+2]+ sales_floats[i+3]+ sales_floats[i+4]+ sales_floats[i+5])/6);
		printf("%10s - %10s \t $%.2f\n", months[i], months[i+5],six_avg);
	}

	printf("\n");
	printf("Sales Report (Highest to Lowest)\n");
	/* This section prints the sales report from highest to lowest */
	float temp = 0;
	for (int i = 0; i < 12; i++){
		for(int j = i+1; j < 12; j++){
			if(sales_floats[i] < sales_floats[j]){
				temp = sales_floats[i];
				sales_floats[i] = sales_floats[j];
				sales_floats[j] = temp;
			}
		}
	}
	for(int i = 0; i< 12;i++){
			/* printf("%s", months[i]); */
			printf("%10s\t $%.2f\n", months[i], sales_floats[i]);
			/* printf("\t$%.2f\n",sales_floats[i]); */
		}
}
