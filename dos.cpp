#include <iostream>
#include <fstream>
using namespace std;

float * lee(string filename, int *n_points);
int mult(float *x, float *y, int n_x, string file_name);

int main(){
    float *x=NULL;
    float *y=NULL;
    int n_x=0;
    int n_y=0;

    x = lee("valores_x.txt", &n_x);
    y = lee("valores_y.txt", &n_y);
    string file_name = "multiplicados.dat";
    
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

int mult(float *x, float *y, int n_x, string file_name){
    ofstream outfile;
    outfile.open(file_name);
    double a;
    double b;
    cout << "Escribiendo en " << file_name << endl; 
    for (int i=0; i < n_x; i++){
        a = x[i];
        b = y[i];
        outfile << (a*b)  << endl;
    }
    outfile.close(); 
    return 0;
}
