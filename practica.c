#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#define N 512
 
float V1[N], V2[N], V3[N], V4 [N];
 
float Mat[N][N], MatDD[N][N];

void InitData(){
	int i,j;
	srand(4422543);
	for( i = 0; i < N; i++ ){
		for( j = 0; j < N; j++ ){
			Mat[i][j]=(((i*j)%3)?-1:1)*(100.0*(rand()/(1.0*RAND_MAX)));
			if ( (abs(i - j) <= 3) && (i != j))
				MatDD[i][j] = (((i*j)%3) ? -1 : 1)*(rand()/(1.0*RAND_MAX));
			else if ( i == j )
				 MatDD[i][j]=(((i*j)%3)?-1:1)*(10000.0*(rand()/(1.0*RAND_MAX)));
			else MatDD[i][j] = 0.0;
		}
	}
	for( i = 0; i < N; i++ ){
		V1[i]=(i<N/2)?(((i*j)%3)?-1:1)*(100.0*(rand()/(1.0*RAND_MAX))):0.0;
		V2[i]=(i>=N/2)?(((i*j)%3)?-1:1)*(100.0*(rand()/(1.0*RAND_MAX))):0.0;
		V3[i]=(((i*j)%5)?-1:1)*(100.0*(rand()/(1.0*RAND_MAX)));
	}
}
//exercici1
void PrintVect( float vect[N], int from, int numel ) {
	int i = numel;
	for ( i; i!=0; i-- ){
		printf( "%f ", vect[from] ); //%f: float
		from++;
	}
}
//exercici2
void PrintRow( float mat[N][N], int row, int from, int numel ){
	int i = numel;
	for (i; i!=0; i--) {
		printf ( "%f", mat[row][from]);
		from--;
	}
}
//exercici3
void MultEscalar( float vect[N], float vectres[N], float alfa ){
	int i; 
	for (i=0; i <N; i++){
		vectres[i]=vect[i]*alfa;
		printf("%f", vectres[i]);	
	}
}
//exercici4
float Scalar( float vect1[N], float vect2[N] ){
	int i; 
	float sumar;
	for (i=0; i<N; i++){
		sumar += vect1[i] * vect2[i];
	}
	printf("%f", sumar);
	return sumar;
}

//exercici5
float Magnitude( float vect[N] ){
	int i; 
	float suma;
	for (i=0; i<N; i++){
		suma+=vect[i]*vect[i];
	}
	float total = sqrt(suma);
	printf("%f", total);
}

//exercici6
int Ortogonal( float vect1[N], float vect2[N] ){
	int i;
	float suma=0;
	for (i=0; i<N; i++){
		suma+=vect1[i]*vect2[i];
	}
	if (suma=0){
		printf("1");
	}else{
		printf("0");
	}
}

//exercici7
void Projection( float vect1[N], float vect2[N], float vectres[N] ){
	float alfa = Scalar(vect1,vect2)/Magnitude(vect2);
	MultEscalar(vect1,vectres,alfa);
}

//exercici8
float Infininorm( float M[N][N] ){

}



int main (){
	InitData();

	printf("Exercici 1\n");
	PrintVect(V1,0, 10); //vector1
	printf("\n\n");
	PrintVect(V2,0, 10); //vector2
	printf("\n\n");
	PrintVect(V3,0, 10); //vector3
	printf("\n\n");

	printf("Exercici 2\n");
	PrintRow(Mat,100,0,10);	
	printf("\n\n");

	printf("Exercici 3\n");
	//printf("%f", V1[N]);
	//printf("\n\n");
	MultEscalar(V1,V4,3);
	printf("\n\n");

	printf("Exercici 4\n");
	Scalar(V1,V2);
	printf("\n\n");

	printf("Exercici 5\n");
	Magnitude(V1);
	printf("\n\n");

	printf("Exercici 6\n");
	Ortogonal(V1,V2);
	printf("\n\n");

	printf("Exercici 7\n");
	Projection(V1,V2,V4);


}












