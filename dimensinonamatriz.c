#include<stdio.h>
#include<conio.h>


 int l,c,tam;
 void  dimensiona(int linhas, int colunas){
    l = linhas;
    c = colunas;
    tam = linhas*colunas;
    return;
 }
 int calculo(int linhas, int colunas){
     linhas = linhas-1 ;
    colunas = colunas-1;
    int k = (linhas*c)+colunas;
    return k;

 }



void zera_matriz( int vet[tam]){
    int acesso;
    for(int i=1; i<=l ; i++){
        for(int j=1; j<=c; j++){
            acesso = calculo(i,j);
            vet[acesso]=0;
            

        }
    }
    return;
}
 
void imprime_matriz(int vet[tam], int linhas, int colunas){
    for(int i = 1; i<=linhas; i++){
        for(int j=1; j<=colunas; j++ ){
           int acesso = calculo(i,j);
           printf("%d ", vet[acesso]);

        }
        printf("\n");
    }

     return;
}

void adiciona_elemento(int vet[tam], int num, int linha,int coluna){
    int acesso = calculo(linha,coluna);
    vet[acesso]=num;
    return;
    
}

int buscar_elemento(int vet[tam], int linha, int coluna){
     int acesso = calculo(linha,coluna);
     return vet[acesso];
    

     }
   


   void somaMatriz (int vetor1[tam], int vetor2[tam], int resultado[tam]) {
	for(int i=1;i<=l;i++){
		for(int j=1;j<=c;j++){
			int acesso = calculo(i,j);
			resultado[acesso] = vetor1[acesso] + vetor2[acesso];
		}
	}
}


int main(){

	//dimensiona a matriz
	dimensiona(3, 3);

	
    int vet1[tam];
    int vet2[tam];
    int vetResultado[tam];
	
	//zero a primeira matriz
	zera_matriz(vet1);
	
	//imprimo a primeira matriz
	printf("Matriz 1 zerada:\n");
	imprime_matriz(vet1,l,c);
	
	//preenche a primeira matriz
	adiciona_elemento(vet1, 15, 1, 1);
	adiciona_elemento(vet1, 25, 2, 2);
	adiciona_elemento(vet1, 35, 3, 3);
	
	//imprime a primeira matriz preenchida
	printf("Matriz 1 preenchida:\n");
	imprime_matriz(vet1,l,c);
	
	//zera a segunda matriz
	zera_matriz(vet2);
	
	//imprime a segunda matriz zerada
	printf("Matriz 2 zerada:\n");
	imprime_matriz(vet2,l,c);
	
	//preenche a segunda matriz
	adiciona_elemento(vet2, 5, 1, 1);
	adiciona_elemento(vet2, 5, 2, 2);
	adiciona_elemento(vet2, 5, 3, 3);
	
	//imprime a segunda matriz zerada
	printf("Matriz 2 preenchida:\n");
	imprime_matriz(vet2,l,c);
	
	printf("\n");

	printf("O elemento que esta na linha 2 e coluna 2 da matriz 1 eh: %d\n\n", buscar_elemento(vet1, 2, 2));

	//soma a primeira matriz com a segunda
	somaMatriz(vet1, vet2, vetResultado);

	//imprime o resultado de ambas as matrizes
	printf("Soma das matrizes:\n");
	imprime_matriz(vetResultado,l,c);

    return 0;
}




