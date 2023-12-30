/********************************************************************
Ejemplo de metodo de MonteCarlo para aproximar Pi

By
Angel Antonio Mendez Hernandez
********************************************************************/

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

double MonteCarloPi(int n){
    srand(time(nullptr));
    double x, y;
    int contador=0;
    for(int i=0; i<n; i++){
        //generamos coordenadas aleatorias en el rectangulo
        //[0,1]x[0,1]
        x=static_cast<double>(rand()) / RAND_MAX;
        y=static_cast<double>(rand()) / RAND_MAX;
        double d=(x-0.5)*(x-0.5)+(y-0.5)*(y-0.5);
        //evaluamos si el punto cae en el circulo
        //de ser asi, lo contamos
        if(d<0.25)
            contador++;
    }
    return 4*static_cast<double>(contador)/n;
}


int main() {
    int n;
    cout<<"Ingrese el numero de tiradas: ";
    cin>>n;
    cout<<"La aproximacion de Pi con "<<n<<" tiradas es: "<<MonteCarloPi(n)<<endl;
    return 0;
}
