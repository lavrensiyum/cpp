/////////////////////////////
// Kadir YILDIZ 2200333___ //
/////////////////////////////

#include <iostream>

using namespace std;

int MatrixCarpim(int dizi1[], int dizi2[], int boyut1, int boyut2);
void MatrixYazdir(int dizi3[]);

int main() {
    int a[4] = { 2, -1, -1, 1 };
    int b[4] = { -1, 3, 3, 2 };
    int Sonuc1[5];
    int Sonuc2[5];

    cout << "A matrixi:";
    MatrixYazdir(a);

    cout << endl << "B matrixi:";
    MatrixYazdir(b);
    cout << endl << endl;

    cout << "A*B matrixinin carpimi: ";
    Sonuc1[4] = MatrixCarpim(a, b, 4, 4);

    cout << "B*A matrixin carpimi: ";
    Sonuc2[4] = MatrixCarpim(b, a, 4, 4);

    cout << endl;
    system("pause");
    return 46;
}

int MatrixCarpim(int dizi1[], int dizi2[], int boyut1, int boyut2) {
    int x1 = 0, x2 = 0, x3 = 0, x4 = 0;
    //int y1=0, y2=0, y3=0, y4=0;

    x1 = ((dizi1[0] * dizi2[0]) + (dizi1[1] * dizi2[2]));
    cout << x1 << ", ";
    x2 = ((dizi1[0] * dizi2[1]) + (dizi1[1] * dizi2[3]));
    cout << x2 << ", ";
    x3 = ((dizi1[2] * dizi2[0]) + (dizi1[3] * dizi2[2]));
    cout << x3 << ", ";
    x4 = ((dizi1[2] * dizi2[1]) + (dizi1[3] * dizi2[3]));
    cout << x4 << "." << endl;

    return 46;
}

void MatrixYazdir(int dizi3[]){
    for (int i = 0; i < 4; i++){
        if(i == 3){
            cout << " " << dizi3[i] << ".";
        }else{
            cout << " " << dizi3[i] << ",";
        }
    }
}
