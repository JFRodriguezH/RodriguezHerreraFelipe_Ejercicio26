#include <iostream>

int main(){
    int* a = NULL;
    int x;
    std::cout<<"Escriba el tamaño del arreglo: "<<std::endl;
    std::cin>>x;
    a = new int[x];
    std::cout<<"Su arreglo es: "<<std::endl;
    std::cout<<0<<std::endl;
    for(int i=1; i<x;i++){
        a[i]=1;
        for(int j=i;j>0;j--){
           a[i]= a[i]*j; 
        }
        std::cout<<a[i]<<std::endl;
    }
    delete [] a;
    return 0;   
}