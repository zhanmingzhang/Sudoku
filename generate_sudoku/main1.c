#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
 
int main()
{
//initialize random number generator 

  srand(time(NULL));

FILE *myFile;
FILE* fp;
fp = fopen ("generated_sudoku.txt", "w+");
myFile=fopen("test.txt", "r");
//read file into array
int numArray[729];
int i;
int n=9;
for (i=1; i<=n*n*n; i++){
	fscanf(myFile, "%d", &numArray[i]);
}
/*
for (i=1; i<=n*n*n; i++){
	printf("Number: %d\n", numArray[i]);
}
*/
int c, r, k;

//double p = (double) rand()/RAND_MAX;

for (c=1; c<=n; c++){
	for(r=1;r<=n;r++){
		for (k=1;k<=n; k++){
			if (numArray[n*(r-1)+n*n*(c-1)+k]>0){
//				if ((double) rand()/RAND_MAX>0.5){
					fprintf(fp,"%d ", k);
//				}
//				else fprintf(fp, "_ ");
			}
		}

	
	}
fprintf(fp, "\n");


}

fclose(fp);
return 0;
}

