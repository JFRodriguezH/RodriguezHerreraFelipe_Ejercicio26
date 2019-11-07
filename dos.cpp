#include <iostream>
#include <fstream>
using namespace std;

float * lee(string filename, int *n_points);
void mult(float *x, float *y, int n_x, string file_name);

int main(){
    /*Inicializa los arreglos y las variables*/
    float *x=NULL;
    float *y=NULL;
    int n_x=0;
    int n_y=0;
    /*Lee los archivos y lo guarda en los arreglos*/
    x = lee("valores_x.txt", &n_x);
    y = lee("valores_y.txt", &n_y);
    /*El nombre del archivo que se va a crear*/
    string file_name = "multiplicados.dat";
    /*Se crea el archivo*/
    mult(x, y, n_x, file_name);
  
    return 0;
}

float * lee(string filename, int *n_points){
    int n_lines=0;
    ifstream infile; 
    string line;
    int i;
    float *array;

    /*cuenta lineas*/
    infile.open(filename); 
    getline(infile, line);
    while(infile){
        n_lines++;
        getline(infile, line);
    }
    infile.close();
    *n_points = n_lines;

    /*reserva la memoria necesaria*/
    array = new float[n_lines];

    /*carga los valores*/
    i=0;
    infile.open(filename); 
    getline(infile, line);  
    while(infile){
        array[i] = atof(line.c_str());
        i++;
        getline(infile, line);
    }
    infile.close();

    return array;
}

void mult(float *x, float *y, int n_x, string file_name){
    /*Crea el archivo y lo abre*/
    ofstream outfile;
    outfile.open(file_name);
    double a;
    double b;
    cout << "Escribiendo en " << file_name << endl; 
    for (int i=0; i < n_x; i++){
        /*Guarda los valores que lee de los arreglos de entrada*/
        a = x[i];
        b = y[i];
        /*Escribe el produco en el archivo*/
        outfile << (a*b)  << endl;
    }
    outfile.close(); 
}
