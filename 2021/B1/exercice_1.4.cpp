#include <iostream>
using namespace std;

int main(int argc, char **argv)
{
    // Exercice 1.4
    // Principe à éviter en général : mettre des numéros à des variables ou des fonctions 
    // veut souvent dire qu'on oublie d'utiliser un tableau, ou un paramètre en plus...
    int v1, v2, v3, v4, v5;

    // Les instructions sont séparées par des points-virgules.
    // On peut donc en mettre plusieurs sur la même ligne.
    // Attention, à la lisibilité, c'est généralement une mauvaise idée ^_^'
    cout << "Veuillez saisir une valeur : "; cin >> v1;
    cout << "Veuillez saisir une valeur : "; cin >> v2;
    cout << "Veuillez saisir une valeur : "; cin >> v3;
    cout << "Veuillez saisir une valeur : "; cin >> v4;
    cout << "Veuillez saisir une valeur : "; cin >> v5;

    // L'opération devient une opération à virgule flottante grace à l'utilisation de la
    // constante `5.0` (au lieu de `5` qui est entier)
    // On stocke le résultat dans une variable typée double 
    // un nombre à virgule flottante double précision (que je conseille en général à la place du float)
    double moyenne = (v1 + v2 + v3 + v4 + v5) / 5.0;

    // Encore une fois le cout peut recevoir un peu n'importe quoi : un double, ici :)
    cout << "La moyenne est " << moyenne << endl;

    return 0;
}
