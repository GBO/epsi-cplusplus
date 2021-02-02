#include <vector> // Inclusion de la bibliothèque vector
#include <iostream>
#include <algorithm>
#include <time.h>
#include <random>
#include <cmath>
using namespace std;

int main(int argc, char **argv)
{
    // Exercice 6.1
    // Un pointeur vers un entier tout initialisé en une seule ligne.
    // On aurait également pu écrire :
    // int* p1;
    // p1 = new int;
    // *p1 = 666
    int* p1 = new int(666);
    // Un pointeur vers un pointeur ^_^'
    // C'est possible et ça se manipule tout pareil.
    int** p2 = new int*(p1);

    // On affiche le pointeur et la valeur pointée (*p1)
    cout << "Un entier : " << *p1 << ", et son adresse : " << p1 << endl;
    // On affiche le pointeur, la valeur pointée (*p2) et la valeur pointée par la valeur pointée (**p2) :)
    cout << "Un entier : " << **p2 << ", un pointeur d'entier : " << *p2 << ", et son adresse : " << p2 << endl;

    // A chaque new son delete !
    delete p1;
    delete p2;

    return 0;
}
