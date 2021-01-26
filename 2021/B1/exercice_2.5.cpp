#include <iostream>
using namespace std;

int main(int argc, char **argv)
{
    // Exercice 2.5
    double somme = 0.0; // Pour faire une opération à virgule flottante plus bas
    int nb = 0;
    int valeur = 1; // Pour entrer dans la boucle en dessous

    // Condition du "tant que" : la valeur est différente de zéro
    // Pour sortir lorsque l'utilisateur saisi 0
    while (valeur != 0) {
        cout << "Veuillez saisir une valeur : ";
        cin >> valeur;
        // On ne fait le calcul que lorsque la saisie est correcte (entier positif)
        if (valeur > 0) {
            // Totalement équivalent à : somme = somme + valeur;
            somme += valeur;
            // Totalement équivalent à : nb = nb + 1;
            nb++;
        } else if (valeur < 0) {
            // Le cas d'erreur demandé dans les exigences
            cout << "Vous ne pouvez pas saisir de nombre négatif !" << endl;
        }
    }

    // Attention au == vs. =
    // == : opérateur de comparaison (égalité pour être précis)
    // = : opérateur d'affectation. Il s'avère que l'affectation retourne un résultat : la valeure affectée
    if (nb == 0) {
        cout << "Vous n'avez rien saisi !" << endl;
    } else {
        // On fait la moyenne et on l'affiche.
        // L'utilisation de la variable `moyenne` est très discutable car elle ne sert qu'une fois.
        // Une solution la plus pertinente serait de s'en passer :
        // cout << "La moyenne est " << somme / nb << endl;
        double moyenne = somme / nb;
        cout << "La moyenne est " << moyenne << endl;
    }

    return 0;
}
