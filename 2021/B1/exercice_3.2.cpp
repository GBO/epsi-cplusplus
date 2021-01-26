#include <iostream>
using namespace std;

int main(int argc, char **argv)
{
    // Exercice 3.2
    // Le { ... } sert à initialiser les éléments du tableau.
    // Attention au nombre d'élément dans le tableau par rapport à la taille déclarée ;)
    // int tableau[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int tableau[10] = {6, 6, 6, 6, 6, 6, 6, 6, 6, 6};

    // Demander à l'utilisateur la valeur à chercher dans le tableau
    int valeur;
    cout << "Veuillez saisir une valeur : ";
    cin >> valeur;

    // Recherche
    bool trouve = false;
    // On pourrait utiliser un `for`, mais la condition de sortie est un peu trop cachée.
    // Pour plus de lisibilité on préfèrera le `while` dans ce cas
    // for (int i = 0; (i < 10) && !trouve; i++) {
    int i = 0;
    while ((i < 10) && !trouve) {
        if (tableau[i] == valeur) {
            cout << "Votre valeur est bien dans le tableau :) " << endl;
            trouve = true;
        }
        i++;
    }

    // Deuxième avantage du flag `trouve` : on sait à la sortie de la boucle que si une
    // valeur a été trouvée ou pas.
    if (!trouve) {
        cout << "Votre valeur n'est pas dans le tableau :'( " << endl;
    }

    return 0;
}
