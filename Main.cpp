#include <stdio.h>
#include<iostream>
#include<time.h>
using namespace std;

int det(double *, int);

int main(void){

	printf("Hello world!\n");
	int n = 350;
  	double massiveA[n][n];
	srand(time(NULL));
  	for(int i=0; i<n; i++){
		for(int j=0;j<n; j++){
			massiveA[i][j] = rand()%10+1;
			printf(" %5.2f ", massiveA[i][j]);
		}		
		printf("\n");
	}
	printf("The size of mas is %d\n", sizeof(massiveA)/4);
	det(&massiveA[0][0], n);

  	return 0;
}

int det(double *mas, int size){
	printf("Size is %d\n\n", size);

	for(int i = 0; i < size; i++){
		for(int j = 0; j < size; j++)
			printf(" %5.2f", *(mas+i*size+j));
		printf("\n");
	}

	printf("\n");
	for(int l=1; l<size; l++){
		for(int i=0; i<l; i++){
				double a=*(mas+l*size+i);
				if(a==0)
						continue;
				double b=*(mas+i*size+i);
				printf(" Lstr=%5.2f Istr=%5.2f \n", a,b);
				for(int j=0; j<size; j++){
						*(mas+l*size+j) = (((*(mas+l*size+j))*b)-(*(mas+i*size+j)*a))/b;
						printf(" %5.2f", *(mas+l*size+j));	
				}
				printf("\n\n");
				
		}
	}

	for(int i=0; i<size;i++){
		for(int j=0; j<size; j++){
				printf(" %5.2f", *(mas+i*size+j));
		}
		printf("\n");
	}

	int sum = 1;

	for(int i=0; i<size; i++){
		sum *= (*(mas+i*size+i));
	}

	printf("det is %d", sum);

	
			
	return 0;
}
