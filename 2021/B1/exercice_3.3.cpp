#include <iostream>
using namespace std;

int main(int argc, char **argv)
{
    // Exercice 3.3
    int tableau[10] = {1, 2, 3, 4, 6, 6, 6, 8, 9, 10};

    // Demander à l'utilisateur la valeur à chercher dans le tableau
    int valeur;
    cout << "Veuillez saisir une valeur : ";
    cin >> valeur;

    cout << "Solution à plusieurs boucles : " << endl;

    // Solution Quentin, en plusieurs boucles
    // Premièrement on remplace la valeur par des 0
    for (int i = 0; i < 10; i++) {
        if (tableau[i] == valeur) {
            tableau[i] = 0;
        }
    }

    // Ensuite on décale dès qu'on tombe sur un 0
    int j = 0;
    for (int i = 0; i < 10; i++) {
        if (tableau[i] != 0) {
            tableau[j] = tableau[i];
            j++;
        }
    }
    // On remplit la fin du tableau avec des 0
    while (j < 10) {
        tableau[j] = 0;
        j++;
    }

    // Affichage
    cout << "Mes valeurs : ";
    for (int i = 0; i < 10; i++) {
        cout << tableau[i] << ", ";
    }
    cout << endl;

    cout << "Solution à une seule boucle : " << endl;

    // Solution alternative en une boucle :
    int tableau2[10] = {1, 2, 3, 4, 6, 6, 6, 8, 9, 10};
    // On utiliser `decalage` qui servira à calculer l'indice à recopier
    int decalage = 0;
    // On traite tous éléments
    for (int i = 0; i < 10; i++) {
        while (tableau2[i + decalage] == valeur) {
            // Quand on détecte une valeur, on incrémente le décalage
            // Et on l'augmente tant qu'on est sur ladite valeur
            decalage++;
        }
        if (decalage > 0) {
            if ((i + decalage) > 10) {
                // Le décalage nous emmène au delà du tableau...
                // C'est qu'on est en train de traiter les derniers éléments du tableau
                // A remplir avec des 0
                tableau2[i] = 0;
            } else {
                // Sinon, on recopie simplement le contenu du tableau au décalage indiqué
                tableau2[i] = tableau2[i + decalage];
            }
        }
    }

    // Affichage
    cout << "Mes valeurs : ";
    for (int i = 0; i < 10; i++) {
        cout << tableau2[i] << ", ";
    }
    cout << endl;

    return 0;
}
