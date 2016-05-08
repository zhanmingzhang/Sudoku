#include <stdio.h>
#include <stdlib.h>
#include <math.h>
 

int main()
{
FILE* fp;

fp = fopen ("sudoku.cnf", "w+");
   fprintf(fp, "p cnf ");
 //  fprintf(fp,"%d ", ncktwire);
   fprintf(fp, "0\n");

//size of the soduku
int n = 4;
int sqrtn = (int)sqrt((double)n);

// Cell defineness 
for(int r=1; r<=n; r++){
	for(int c = 1; c<=n; c++){	
		for(int v=1;v<=n; v++){
		fprintf(fp, "%d ", (r-1)*16+(c-1)*4+v);
}
fprintf(fp, "0 \n");
}
}





// Row uniqueness

for (int r=1; r<=n; r++){
	for(int v=1; v<=n; v++){
		for(int ci=1; ci<=n-1; ci++){
			for(int cj=ci+1; cj<=n; cj++){
			fprintf(fp, "-%d", (r-1)*16+(ci-1)*4+v);
			fprintf(fp, " -%d", (r-1)*16+(cj-1)*4+v);	
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
				fprintf(fp, "-%d", (rj-1)*16+(c-1)*4+v);
				fprintf(fp, " -%d", (ri-1)*16+(c-1)*4+v);	
				fprintf(fp, " 0 \n");	
				}

			}	

		}


	}






//Block uniqueness
/*
for(int roffs=1; roffs<=sqrtn-1; roffs++){
	for(int coffs=1; coffs<=sqrtn-1; coffs++){
		for(int v=1;v<=n; v++){
			for(int r=1; r<=n; r++){
				for(int c = r+1; c<=n; c++){	
				fprintf(fp, "-%d ", (roffs*sqrtn+r%sqrtn)*100+(coffs*sqrtn+r%sqrtn)*10+v);
				fprintf(fp, "-%d ", (roffs*sqrtn+r%sqrtn)*100+(coffs*sqrtn+c%sqrtn)*10+v);
				fprintf(fp, " 0 \n");

			}

		}
	}
	}
}
*/
 fclose(fp);

return 0;

}


