#include <iostream>
using namespace std;

int main(int argc, char **argv)
{
    // Exercice 3.1
    int tableau[10]; // Pas d'initialisation de contenu, c'est la première chose faite plus bas
    int valeur;

    // `10` est une constante représentant la taille du tableau, que moi, développeur je dois connaitre.
    for (int i = 0; i < 10; i++) {
        cout << "Veuillez saisir une valeur : ";
        // On pourrait se passer de la variable `valeur` ici avec un : `cin >> tableau[i];`
        cin >> valeur;
        tableau[i] = valeur;
    }

    // Le premier élément de mon tableau a l'indice 0
    cout << "Premier élément : " << tableau[0] << endl;
    // Le dernier élément de mon tableau a l'indice taille - 1
    cout << "Dernier élément : " << tableau[9] << endl;

    // Comportement non prédictible (indice en dehors de la plage d'indice possible) :
    // cout << "Un indice inexistant : " << tableau[10] << endl;
    // Drame absolu (où suis-je en train d'écrire) :
    // tableau[10] = 12;

    // `i` est ma variable de boucle qui n'existe qu'à l'intérieur du `for`
    for (int i = 0; i < 10; i++) {
        if (tableau[i] >= 10) {
            cout << "Une valeur supérieure à 10 : " << tableau[i] << endl;
        }
    }

    return 0;
}
