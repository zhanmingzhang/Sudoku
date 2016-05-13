#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h> 

int main()
{

//initialize random number generator 

  srand(time(NULL));

FILE* fp;

//size of the soduku
int n = 9;
int sqrtn = (int)sqrt((double)n);

fp = fopen ("sudoku.cnf", "w+");
   fprintf(fp, "p cnf %d ", n*n*n);
 //  fprintf(fp,"%d ", ncktwire);
   fprintf(fp, "0\n");

// Pre assign number in the grids
// in the preassign session, we assign one random value in each block
int  row, col, value; 
int howmanypreassign = n;
int rowblock, colblock;

for(int preassign=0; preassign<howmanypreassign; preassign++){
	rowblock = (int)(preassign/sqrtn)+1;
	colblock = preassign%sqrtn+1;

	row = (rowblock-1)*sqrtn+(int)(((double)rand()/(double)(RAND_MAX))*sqrtn)+1; //random number from 1 to sqrtn
	col = (colblock-1)*sqrtn+(int)(((double)rand()/(double)(RAND_MAX))*sqrtn)+1;

	value = (int)(((double)rand()/(double)(RAND_MAX))*9)+1;
	if(row>n) row = n;
	if(col>n) col = n;
	if(value>n) value = n;
	fprintf(fp, "%d ", (row-1)*n*n+(col-1)*n+value);	
}
	fprintf(fp, "0 \n");

// Cell defineness 
for(int r=1; r<=n; r++){
	for(int c = 1; c<=n; c++){	
		for(int v=1;v<=n; v++){
		fprintf(fp, "%d ", (r-1)*n*n+(c-1)*n+v);
}
fprintf(fp, "0 \n");
}
}





// Row uniqueness

for (int r=1; r<=n; r++){
	for(int v=1; v<=n; v++){
		for(int ci=1; ci<=n-1; ci++){
			for(int cj=ci+1; cj<=n; cj++){
			fprintf(fp, "-%d", (r-1)*n*n+(ci-1)*n+v);
			fprintf(fp, " -%d", (r-1)*n*n+(cj-1)*n+v);	
			fprintf(fp, " 0 \n");	
			}

		}	

	}


}

//Column Uniqueness
for (int c=1; c<=n; c++){
	for(int v=1; v<=n; v++){
		for(int ri=1; ri<=n-1; ri++){
			for(int rj=ri+1; rj<=n; rj++){
				fprintf(fp, "-%d", (rj-1)*n*n+(c-1)*n+v);
				fprintf(fp, " -%d", (ri-1)*n*n+(c-1)*n+v);	
				fprintf(fp, " 0 \n");	
				}

			}	

		}


	}






//Block uniqueness

for(int z=1; z<=n; z++){
	for(int i=0; i<=sqrtn-1; i++){
		for(int j=0;j<=sqrtn-1; j++){
			for(int x=1; x<=sqrtn; x++){
				for(int y=1; y<=sqrtn; y++){
					for(int k = y+1; k<=sqrtn; k++){	
			
				fprintf(fp, "-%d ", (sqrtn*i+x-1)*n*n+(sqrtn*j+y-1)*n+z);
				fprintf(fp, "-%d ", (sqrtn*i+x-1)*n*n+(sqrtn*j+k-1)*n+z);
				fprintf(fp, "0\n");
					}
				}
			}
		}
	}
}

for(int z=1; z<=n; z++){
	for(int i=0; i<=sqrtn-1; i++){
		for(int j=0;j<=sqrtn-1; j++){
			for(int x=1; x<=sqrtn; x++){
				for(int y=1; y<=sqrtn; y++){
					for(int k = x+1; k<=sqrtn; k++){	
						for(int l = 1; l<=sqrtn; l++){	
				fprintf(fp, "-%d ", (sqrtn*i+x-1)*n*n+(sqrtn*j+y-1)*n+z);
				fprintf(fp, "-%d ", (sqrtn*i+k-1)*n*n+(sqrtn*j+l-1)*n+z);
				fprintf(fp, "0\n");
						}
					}
				}
			}
		}
	}
}
 fclose(fp);

return 0;

}


