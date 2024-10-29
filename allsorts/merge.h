#include "merge.h"

int *mergeSort(int *vet, int inicio, int fim){

   if (inicio < fim) {
      int meio = (inicio + fim) / 2;
      mergeSort (vet, inicio, meio);  
      mergeSort (vet, meio+1, fim);

    int *esquerda = malloc((meio-inicio+1)*(sizeof(int)));
    int *direita = malloc((fim-meio)*(sizeof(int)));
    
    for(int i=0;i<meio-inicio+1;i++){
        esquerda[i] = vet[inicio+i];

    }
    for(int i=0;i<fim-meio;i++){
        direita[i] = vet[meio+1+i];

    }

    //Merge

    int i=0;
    int j=0;
    int k = inicio;

    while(i<meio-inicio+1 && j< fim-meio){
        if(esquerda[i]<=direita[j]){
            vet[k] = esquerda[i];
            i++;
        }else{
            vet[k] = direita[j];
            j++;
        }
        k++;
    