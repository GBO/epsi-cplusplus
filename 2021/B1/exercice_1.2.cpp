#include <iostream>
using namespace std;

int main(int argc, char **argv)
{
    // Exercice 1.2
    int largeur, hauteur;

    cout << "Veuillez saisir une largeur : ";
    cin >> largeur;
    cout << "Veuillez saisir une hauteur : ";
    cin >> hauteur;

    // Les parenthèses sont utiles pour gérer l'ordre des opérations
    // Elles servent aussi à la lisibilité dans certains cas.
    cout << "Le périmètre du champ est " << (largeur + hauteur) * 2 << endl;
    cout << "L'air du champ est " << largeur * hauteur << endl;

    return 0;
}
