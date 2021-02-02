#include <vector> // Inclusion de la bibliothèque vector
#include <iostream>
using namespace std;

int main(int argc, char **argv)
{
    // Exercice 4.4
    vector<int> v;
    // Les quelques ajouts de l'exercice d'avant
    v.push_back(12);
    v.push_back(666);
    v.insert(v.begin(), 333);
    v.insert(v.begin() + 2, 7);
    v.insert(v.begin() + 2, 3, 6);
    v.insert(v.begin() + 2, v.begin(), v.begin() + 3);

    // Supprimons
    v.pop_back();

    v.erase(v.begin() + 2);

    v.erase(v.begin() + 3, v.end());

    v.clear();

    // Affichage pour preuve ;)
    for (int i = 0; i < v.size(); i++) {
        cout << "Element n°" << i << ": " << v[i] << endl;
    }

    return 0;
}
