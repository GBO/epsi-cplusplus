#include <vector> // Inclusion de la bibliothèque vector
#include <iostream>
#include <algorithm>
#include <time.h>
#include <random>
#include <cmath>
using namespace std;

// Le type des paramètres est suffixé par un et commercial (&)
// Les paramètres sont donc passés par références (c'est l'adresse de la valeur qui est passée et non pas
// juste la valeur comme un paramètre classique)
void inverser_parametres(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

// Il est possible de surcharger une fonction : plusieurs définitions avec des types 
// différents pour que le compilateur puisse distinguer les appels.
void inverser_parametres(double& a, double& b) {
    double temp = a;
    a = b;
    b = temp;
}


int main(int argc, char **argv)
{
    // Exercice 5.4
    int swap_a = 666, swap_b = 333;

    cout << "Avant : " << swap_a << " / " << swap_b << endl;
    inverser_parametres(swap_a, swap_b);
    cout << "Après : " << swap_a << " / " << swap_b << endl;

    // Cette ligne ne compile pas : erreur de type
    // `0` et `1` sont des constantes et ne peuvent donc pas être passées, car une constante
    // ne peut être convertie en `int&`
    // inverser_parametres(0, 1);

    return 0;
}
