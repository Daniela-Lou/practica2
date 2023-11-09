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
		printf ( "%f ", mat[row][from]);
		from++;
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
	//printf("%f", sumar);
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
	//printf("%f", total);
	return total;
}

//exercici6
int Ortogonal( float vect1[N], float vect2[N] ){
	int i;
	float suma=0;
	for (i=0; i<N; i++){
		suma+=vect1[i]*vect2[i];
	}
	if (suma=0){
		//printf("1");
		return 1;
	}else{
		//printf("0");
		return 0;
	}
}

//exercici7
void Projection( float vect1[N], float vect2[N], float vectres[N] ){
	int i;
	float alfa = Scalar(vect1,vect2)/Magnitude(vect2);
	MultEscalar(vect2,vectres,alfa);
	for (i=0;i<N;i++){
		printf("%f ", vectres[i]);
	}
}

//exercici8
float Infininorm( float M[N][N] ){
	int i, j;
	float maxim =0;
	float suma=0;
	for (i=0; i<=N-1; i++){
		for(j=0;j<N;j++){
			suma+=fabs(M[i][j]);
		}
		if (suma>=maxim){
			maxim=suma;
		}
		suma=0;
	}
	return maxim;
}
//exercici9
float Onenorm( float M[N][N] ){
	int i, j;
	float maxim=0;
	float suma=0;
	for (j=0;j<N;j++){
		for(i=0;i<N;i++){
			suma+=fabs(M[i][j]);	
		}
		if(suma>maxim){
			maxim=suma;
		}
		suma=0;
	}
	return maxim;
}

//exercici10
float NormFrobenius( float M[N][N] ){
	int i, j;
	double frobenius;
	float coeficiente;  
	double suma=0;	
	for (i=0;i<N;i++){
		for (j=0;j<N;j++){
			coeficiente= M[i][j]; 
			suma += (coeficiente*coeficiente);
		}
	}
	//printf("%f", suma);
	frobenius = sqrt(suma);
	//return frobenius;
	printf("%f", frobenius);
}

//exercici11
int DiagonalDom( float M[N][N] ){
	int i, j; 
	float valor;
	float suma; 
	int dominante = 1;
	while (dominante == 1){
		for (i=0;i<N;i++){
			for (j=0;j<N;j++){
				suma += fabs(M[i][j]);
				suma = suma - M[i][i];
				valor =	fabs(M[i][i]);
				if (suma > valor){
					dominante =0;
				}
			}
		}
	}
	return dominante;	
}		

//exercici12
int Jacobi( float M[N][N] , float vect[N], float vectres[N], unsigned iter ){
	int n; //vect = termes independents - vectres = incògnites
	float tmp[N]; 
	
	if (DiagonalDom(M)==0){ //S'ha de complir: DiagonalDom=1 i X convergeix 
		return 0;
	}else{ 
		//DiagonalDom==1. Falta X
		for (int i=0;i<N;i++){ vectres[i]=0.0;}

		for (n=0;n<iter;n++){
			for (int i =0; i <N; i++){
				tmp[i] = vect[i];
				for (int j=0; j<N; j++){
					if (i!=j) {tmp[i] -= M[j][i] * vectres[j];}
				}
				tmp[i] /= M[i][i];
			}	
			for (int i=0; i<N; i++){ vectres[i] = tmp[i];}
			
		}
		return 1;
	}
}

int main (){
	InitData();
	//PrintRow(MatDD,100,90,10); No encaixa
	printf("%f\n", Infininorm(Mat));
	printf("%f\n", Onenorm(Mat));
	NormFrobenius(Mat);
	//printf("%f\n", NormFrobenius(Mat));
//	printf("%d\n", DiagonalDom(Mat));

}












