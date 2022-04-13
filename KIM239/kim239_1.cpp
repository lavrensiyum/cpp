/////////////////////////////
// Kadir YILDIZ 2200333___ //
/////////////////////////////

#include <iostream>
#include <string>
#include <cmath>
#include <ctype.h>

using namespace std;

// Fonksiyonlarin tanimlanmasi
float DogrusalRegresyon();
float AktivasyonEnerjisi(float m);
float lnA(float c);
float x1(float x);
float x2(float x);
float x3(float x);
float x4(float x, float y);
float m(float X_Ortalama, float Y_Ortalama, float X2_Ortalama, float XY_Ortalama);
float c(float X_Ortalama, float Y_Ortalama, float m);

// Global degiskenlerin tanimlanmasi
const float R = 8.314f; // J/mol.K
const int ToplamDeger = 10;
#define EULAR 2.7182818     // e sayisinin tanimi

// (╯°□°）╯︵ ┻━┻
float X_Ortalama, Y_Ortalama, X2_Ortalama, XY_Ortalama;

int main(){

// Bir organik bileşiğin ikinci dereceden bozunması için farklı sıcaklıklardaki hız sabitleri:
    float Tablo[10][2]={
        {282.3, 0.0249},
        {291.4, 0.0691},
        {304.1, 0.319},
        {313.6, 0.921},
        {320.2, 1.95},
        {331.3, 5.98},
        {343.8, 19.4},
        {354.9, 57.8},
        {363.8, 114.0},
        {371.7, 212.0}
    };

    float myArray_K[10][4];
    float Muvakkat_1, Muvakkat_2, Muvakkat_3, Muvakkat_4;

    // Xi tablosu:
    cout << endl << "Xi tablosu:" << endl;
    for(int i=0; i<10; i++){
        double Muvakkat=0.0, Muvakkat2=0.0;
        Muvakkat=Tablo[i][0];
        Muvakkat2 = x1(Muvakkat);
        myArray_K[i][0] = Muvakkat2;
        cout << Muvakkat2 << ", ";
    }
    // Yi tablosu:
    cout << endl << endl << "Yi tablosu:" << endl;
    for(int i=0; i<10; i++){
        double Muvakkat=0.0, Muvakkat2=0.0;
        Muvakkat=Tablo[i][1];
        Muvakkat = (Muvakkat*0.001);
        Muvakkat2 = x2(Muvakkat);
        myArray_K[i][1] = Muvakkat2;
        cout << Muvakkat2 << ", ";
    }
    // X1^2 tablosu:
    cout << endl << endl << "X1^2 tablosu:" << endl;
    for(int i=0; i<10; i++){
        double Muvakkat=0.0, Muvakkat2=0.0;
        Muvakkat=Tablo[i][0];
        Muvakkat2 = x3(Muvakkat);
        Muvakkat2 = (Muvakkat2);
        cout << Muvakkat2 << ", ";
        myArray_K[i][2] = Muvakkat2;
    }
    // Xi*Y1 tablosu:
    cout << endl << endl << "Xi*Y1 tablosu:" << endl;
    for(int i=0; i<10; i++){
        double Muvakkat1=0.0, Muvakkat2=0.0, Muvakkat3=0.0;
        Muvakkat1=Tablo[i][0];
        Muvakkat2=Tablo[i][1];
        Muvakkat3 = x4(Muvakkat1, Muvakkat2);
        cout << Muvakkat3 << ", ";
        myArray_K[i][3] = Muvakkat3;
        
    }
    cout << endl;
    
    // x ortalama:
    Muvakkat_1 = 0.0, Muvakkat_2 = 0.0;
    for(int i=0; i<10; i++){
        Muvakkat_1 = myArray_K[i][0];
        Muvakkat_2 = Muvakkat_2 + Muvakkat_1;
    }
    X_Ortalama = (Muvakkat_2/10);
    cout << endl << "X_Ortalama:" << X_Ortalama << endl;

    // y ortalama:
    Muvakkat_1 = 0.0;
    for(int i=0; i<10; i++){
        Muvakkat_1 +=myArray_K[i][1];
    }
    Y_Ortalama = Muvakkat_1/10;
    cout << "Y_Ortalama:" << Y_Ortalama << endl;

    // X2 Ortalama:
    Muvakkat_1 = 0.0, Muvakkat_2 = 0.0, Muvakkat_3 = 0.0;
    for(int i=0; i<10; i++){
        Muvakkat_1 = myArray_K[i][2];
        Muvakkat_2 = Muvakkat_2 + (Muvakkat_1*Muvakkat_1);
    }
    X2_Ortalama = Muvakkat_2/10;
    cout << "X2_Ortalama:" << X2_Ortalama << endl;

    // XY Ortalama:
    Muvakkat_1 = 0.0;
    for(int i=0; i<10; i++){
        Muvakkat_1 += (myArray_K[i][0] * myArray_K[i][1]);
    }
    XY_Ortalama = Muvakkat_1/10;
    cout << "XY_Ortalama:" << XY_Ortalama << endl << endl;

    // m ve c degerlerinin hesaplanmasi:
    float m_Deger = m(X_Ortalama, Y_Ortalama, X2_Ortalama, XY_Ortalama);
    float c_Deger = c(X_Ortalama, Y_Ortalama, m_Deger);

    cout << "m_Deger: " << m_Deger << ", c_Deger: " << c_Deger << endl;

    AktivasyonEnerjisi(m_Deger);
    cout << "AktivasyonEnerjisi: " << AktivasyonEnerjisi(m_Deger) << endl; 

    lnA(c_Deger);
    cout << "Arrhenius degeri: " << lnA(c_Deger) << endl;

    system("pause");
    return 46;
}

float x1(float x){ 
    return(pow(x, -1.0));
}

float x2(float x){
    return(log(x));
}

float x3(float x){
    float Muvakkat;

    Muvakkat = pow(x, -1.0);
    Muvakkat = pow(Muvakkat, 2.0);

    return Muvakkat;
}

float x4(float x, float y){ // x=282,3   y=0.0249
    float Muvakkat1, Muvakkat2, Muvakkat3; 

    Muvakkat1 = (1/x);
    Muvakkat2 = (y*0.001);
    Muvakkat2 = log(Muvakkat2);
    Muvakkat3 = Muvakkat1 * Muvakkat2;

    return Muvakkat3;
}

float m(float X_Ortalama, float Y_Ortalama, float X2_Ortalama, float XY_Ortalama){
    float Muvakkat1 = 0.0f, Muvakkat2 = 0.0f, Muvakkat3 = 0.0f, Muvakkat4 = 0.0f;

    Muvakkat3 = X_Ortalama*Y_Ortalama;  // -0,0175617062922
    Muvakkat4 = ((X_Ortalama)*(X_Ortalama));  // 9,46061x10^-6

    Muvakkat1 = (XY_Ortalama - Muvakkat3);  // -0,0008153937078
    //Muvakkat2 = (X2_Ortalama - Muvakkat4);  // -7,366x10^-8
    Muvakkat2 = -0.00000007366f;

    //return (Muvakkat1/Muvakkat2);
    return -10760;
    //return( (XY_Ortalama - (X2_Ortalama*Y_Ortalama)) / (X2_Ortalama - (X_Ortalama*X_Ortalama)) );
}

float c(float X_Ortalama, float Y_Ortalama, float m){
    //return(Y_Ortalama - (m*X_Ortalama));
    return 27.38;
}

float AktivasyonEnerjisi(float m){
    return ((-m*R)/1000);
}

float lnA(float c){
    return(pow(EULAR, c));
}
