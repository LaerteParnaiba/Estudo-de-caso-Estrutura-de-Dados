#include<stdio.h>

void dimensionamatriz(int vet[], int linhas, int colunas){
     vet[0]=linhas;
     vet[1]=colunas;
}

void remover_elemento(int vet[], int linha, int coluna){
    
    vet[2+(linha-1)* (int)vet[1]+(coluna-1)]=0;
}

int buscar_elemento(int vet[], int linhas, int colunas){
    return vet[2+(linhas-1)* (int)vet[1]+(colunas-1)];

}

void adicionar_elemento(int vet[],int elemento, int linhas, int colunas){
    
     vet[2+(linhas-1)* (int)vet[1]+(colunas-1)]=elemento;

}

void anular_matriz(int vet[]){
    for(int i=1; i<=vet[0]; i++){
        for(int j=1;j<=vet[1];j++){
            remover_elemento(vet,i,j);
        }
    }
}

void imprimir_matriz(int vet[]){
    for(int i=1; i<=vet[0]; i++){
        for(int j=1; j<=vet[1]; j++){
            printf("%4d", buscar_elemento(vet,i,j));
        }
        printf("\n");
    }
}

void preencher_matriz(int vet[]){
    int elemento;
    for(int i=1; i<=vet[0]; i++){
        for(int j=1; j<=vet[1]; j++){
            printf("digite o elemento %dx%d\n", i,j);
            scanf("%d", &elemento);
            adicionar_elemento(vet,elemento,i,j);
        }
    }
    

}

void soma_matriz( int vet1[], int vet2[], int vet3[]){

    if(vet1[0]!=vet2[0] || vet1[1]!=vet2[1]){
        printf("Nao eh possivel somar as matrizes. Digite matrizes com a mesma ordem\n");
        return;
    }
    for(int i=1;i<=vet1[0];i++){
        for(int j=1;j<=vet1[1];j++){
            adicionar_elemento(vet3,buscar_elemento(vet1,i,j) + buscar_elemento(vet2,i,j),i,j);
        }
    }
}

void subtrair_matriz(int vet1[], int vet2[], int vet3[]){
    if(vet1[0]!=vet2[0] || vet1[1]!=vet2[1]){
        printf("Nao eh possivel subtrair as matrizes. Digite matrizes com a mesma ordem\n");
        return;
    }
    for(int i=1;i<=vet1[0];i++){
        for(int j=1;j<=vet1[1];j++){
            adicionar_elemento(vet3,buscar_elemento(vet1,i,j) - buscar_elemento(vet2,i,j),i,j);
        }
    }

}

void copia_matriz(int vet[], int vet_copia[]){
    for(int i=1; i<=vet[0]; i++){
        for(int j=1;j<=vet[1]; j++){

            adicionar_elemento(vet_copia,buscar_elemento(vet,i,j),i,j);
        }
    }

}

 void matriz_transposta(int vet[], int transposta[]){
    for(int i=1; i<=vet[0]; i++){
        for(int j=1;j<=vet[1]; j++){

            adicionar_elemento(transposta,buscar_elemento(vet,j,i),i,j);
        }
    }

}
int matriz_identidade(int vet[]){
    if(vet[0]!=vet[1]){
        printf("Para ser matriz identidade precisa ter a mesma ordem");
        return 0;
    }

    for(int i=1; i<=vet[0]; i++){
        for(int j=1; j<=vet[1]; j++){
            if(i==j){
                if(buscar_elemento(vet,i,j)!=1){
                    return 0;
                }
            }
            else{
                if(buscar_elemento(vet,i,j)!=0){
                    return 0;
                }
            }
        }
    }
    return 1;
}

void multiplica_matriz(int vetorA[], int vetorB[], int vetC[]){
    
    if(vetorA[1] != vetorB[0]){
        printf("Nao eh possivel multiplicar as matrizes.\n");
        return;
    }
    dimensionamatriz(vetC,vetorA[0], vetorB[1]);

    for(int i=1; i<=vetorA[0]; i++){
        for(int j=1; j<=vetorB[1]; j++){
            int soma = 0;
            for(int k=1; k<=vetorA[1]; k++){
                soma = soma + buscar_elemento(vetorA,i,k) * buscar_elemento(vetorB,k,j);
            }
            adicionar_elemento(vetC, soma, i, j);
        }
    }
}

int matrizInversa( int vetorA[], int vetorB[]){
    int vetorCopia[2+(vetorA[0]*vetorB[1])];
    multiplica_matriz(vetorA, vetorB, vetorCopia);
    return matriz_identidade(vetorCopia);
}



int main(){

    int ordem;
    printf("digite a ordem da matriz quadrada");
    scanf("%d", &ordem);
    int vetA[2+(ordem*ordem)], vetB[2+(ordem*ordem)];
      

      dimensionamatriz(vetA, ordem, ordem);
         printf("\npreencha a primeira matriz\n");
            preencher_matriz(vetA);
    
    
      dimensionamatriz(vetB,ordem,ordem);
         printf("\npreencha a segunda matriz\n");
            preencher_matriz(vetB);
   
   
      

       printf("Matriz A:\n");
         imprimir_matriz(vetA);
           printf("\nMatriz B:\n");
            imprimir_matriz(vetB);

    printf("\nB eh a inversa de A? %d\n", matrizInversa(vetA, vetB));
   




    return 0;
     
}


 
