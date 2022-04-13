/////////////////////////////
// Kadir YILDIZ 2200333___ //
/////////////////////////////

#include <iostream>
#include <cmath>

using namespace std;
#define EPSILON 0.00000001  // tolerans sınırı 1 * 10^-8
#define EULAR 2.7182818     // e sayisinin tanimi

double Fonksiyon1(double x);
double Fonksiyon2(double x);
double Turev1Fonk(double x);
double Turev2Fonk(double x);
double NewtonRaphson1(double x);
double NewtonRaphson2(double x);

int main(){
    double XNegatif = -1;
    double XPozitif =  1;

    cout << "----------------------------------------" << endl;
    cout << "Fonksiyon: x^2 - 5" << endl;
    cout << "Negatif kok: "<< NewtonRaphson1(XNegatif) << "." << endl;
    cout << "Pozitif kok: "<< NewtonRaphson1(XPozitif) << "." << endl;
    cout << "----------------------------------------" << endl << endl;

    XNegatif = -1;
    XPozitif =  1;

    cout << "----------------------------------------" << endl; 
    cout << "Fonksiyon: 0.5 - xe^(-x)^2 " << endl;
    cout << "Minimize nokta (negatif): " << NewtonRaphson2(XNegatif) << "." << endl;
    cout << "Minimize nokta (pozitif): " << NewtonRaphson2(XPozitif) << "." << endl;
    cout << "----------------------------------------" << endl << endl;

    system("pause");
    return 46;
}

///////////////  ILK DENKLEM ICIN  ///////////////
double Fonksiyon1(double x){ // bize verilen fonksiyon
    return (x*x - 5.0); // x^2 - 5
}

double Turev1Fonk1(double x){ // turevli hali
    return (2.0*x); // (x^2 - 5) ==> (2x)
}

double Turev2Fonk1(double x){
    return (2.0);   // (2x ==> 2)
}

double NewtonRaphson1(double x){
    double h = (Fonksiyon1(x) / Turev1Fonk1(x));

    while(abs(h) >= EPSILON){   // yakınsama islemi
        h = Fonksiyon1(x) / Turev1Fonk1(x);
        x = x - h;  // x(k+i) = x(k) - (f(x)/f'(x))        
    }
    
    return x;
}
/////////////////////////////////////////////////

/////////////   IKINCI DENKLEM ICIN     ///////////////
double Fonksiyon2(double x){
    return (0.5 - (x * pow(EULAR, -x*x)));
}

double Turev1Fonk2(double x){
    return (-1.0 + 2.0*x*x) / (pow(EULAR, x*x)); 
}

double Turev2Fonk2(double x){
    return (6.0*x-pow(x, 3.0) / pow(EULAR, x*x));
}

double NewtonRaphson2(double x){
    double h = (Turev1Fonk2(x) / Turev2Fonk2(x));

    while(abs(h) >= EPSILON){   // yakınsama islemi
        h = Turev1Fonk2(x) / Turev2Fonk2(x);
        x = x - h;  // x(k+i) = x(k) - (f(x)/f'(x))        
    }
    
    return x;
}
/////////////////////////////////////////////////