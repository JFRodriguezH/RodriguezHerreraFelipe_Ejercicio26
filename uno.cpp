#include <iostream>

int main(){
    /*Inicializa las variables*/
    int* a = NULL;
    int x;
    /*Pregunta por la terminal el tamaño del arreglo*/
    std::cout<<"Escriba el tamaño del arreglo: "<<std::endl;
    std::cin>>x;
    /*Guarda el espacio en la memoria*/
    a = new int[x];
    /*Escribe en el arreglo*/
    std::cout<<"Su arreglo es: "<<std::endl;
    std::cout<<0<<std::endl;
    for(int i=1; i<x;i++){
        a[i]=1;
        /*Calcula el factorial de la posición*/
        for(int j=i;j>0;j--){
           a[i]= a[i]*j; 
        }
        std::cout<<a[i]<<std::endl;
    }
    /*Libera el espacio en la memora*/
    delete [] a;
    return 0;   
}