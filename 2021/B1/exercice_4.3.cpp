#include <vector> // Inclusion de la bibliothèque vector
#include <iostream>
using namespace std;

int main(int argc, char **argv)
{
    // Exercice 4.3
    vector<int> v;

    // Simple ajout à la fin
    v.push_back(12);
    v.push_back(666);

    // Insertion à une position (iterator) donnée
    v.insert(v.begin(), 333);
    v.insert(v.begin() + 2, 7);

    // Insertion avec multiplicateur de valeur (comme à l'init)
    v.insert(v.begin() + 2, 3, 6);

    // Insertion d'un range de valeur (borne de fin exclue)
    v.insert(v.begin() + 2, v.begin(), v.begin() + 3);

    // Affichage pour preuve ;)
    for (int i = 0; i < v.size(); i++) {
        cout << "Element n°" << i << ": " << v[i] << endl;
    }

    return 0;
}
