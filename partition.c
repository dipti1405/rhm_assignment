#include <stdio.h>
#include <stdbool.h>

bool partiion(int a[], int n) 
{
	int sum;
	int i, j;
	sum = 0;

	for (i = 0; i < n; i++)
		sum += a[i];

	if (sum%2 != 0)
		return false; 

	bool p[sum/2+1][n+1];

	for(i = 0; i <= n; i++)
		p[0][i] = true;

	for (i = 1; i <= sum/2; i++)
		p[i][0] = false;

	for (i = 1; i <= sum/2; i++) {
		for (j = 1; j <= n; j++) {
			p[i][j] = p[i][j-1];
			
			if (i >= a[j-1])
				p[i][j] = p[i][j] || p[i - a[j-1]][j-1];
		}
	}

	for (i = 0; i <= sum/2; i++)
	{
		for (j = 0; j <= n; j++)
			printf ("%4d", p[i][j]);
		printf("\n");
	}

	return p[sum/2][n]; 
}      
  
int main() 
{
	int a[] = {3, 1, 1, 2, 2, 1};
	int n = sizeof(a)/sizeof(a[0]);
	if (partiion(a, n) == true)
		printf("Can be subdivided into equal sum");
	else
		printf("Cannot be divided into equal sum");
	getchar();

	return 0; 
} 
