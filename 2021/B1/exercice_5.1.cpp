#include <vector> // Inclusion de la bibliothèque vector
#include <iostream>
#include <algorithm>
#include <time.h>
#include <random>
#include <cmath>
using namespace std;

// Déclaration d'une fonction prenant 4 paramètre `int` et retournant un `double`
double calculer_distance(int x1, int y1, int x2, int y2) {
    // Le calcul et le retour peuvent se faire en une seule ligne
    // Donc on ne se prive pas.
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

int main(int argc, char **argv)
{
    // Exercice 5.1
    // A noter que ces variables ont une portée correspondant au corps du `main`.
    // Elles ne sont donc accessibles que dans cette fonction.
    // `x1` dans la fonction `calculer_distance` n'est pas la même variable.
    int x1, y1, x2, y2;

    x1 = 0; y1 = 0; x2 = 1; y2 = 0;
    cout << "Distance : " << x1 << "x" << y1 << " / " << x2 << "x" << y2 << " : " << calculer_distance(x1, y1, x2, y2) << endl;

    // Juste pour l'exemple : il est possible d'invoquer la fonction avec des constantes (`2` ici).
    calculer_distance(x1, y1, 2, 2);

    x1 = 0; y1 = 0; x2 = 0; y2 = 1;
    cout << "Distance : " << x1 << "x" << y1 << " / " << x2 << "x" << y2 << " : " << calculer_distance(x1, y1, x2, y2) << endl;

    x1 = 0; y1 = 0; x2 = 1; y2 = 1;
    cout << "Distance : " << x1 << "x" << y1 << " / " << x2 << "x" << y2 << " : " << calculer_distance(x1, y1, x2, y2) << endl;

    return 0;
}
