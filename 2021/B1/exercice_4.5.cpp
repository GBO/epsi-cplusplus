#include <vector> // Inclusion de la bibliothèque vector
#include <iostream>
#include <algorithm>
#include <time.h>
#include <random>
using namespace std;

int main(int argc, char **argv)
{
    // Exercice 4.5
    vector<int> v;
    // Les quelques ajouts de l'exercice d'avant
    v.push_back(0);
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);
    v.push_back(6);
    v.push_back(7);
    v.push_back(8);
    v.push_back(9);


    cout << "Avant random :" << endl;
    // Affichage pour preuve ;)
    for (int i = 0; i < v.size(); i++) {
        cout << "Element n°" << i << ": " << v[i] << endl;
    }

    // On mélange !
    // Solution sur mon poste :
    random_device rd;
    mt19937 g(rd());
    shuffle(v.begin(), v.end(), g);

    // Solution sur un Code::Blocks :
    // srand(time(NULL));
    // random_shuffle(v.begin(), v.end(), g);

    // Dans les 2 cas, penser à inclure les librairies nécessaires : <algorithm> (et <time.h> éventuellement)

    cout << endl << "Après random :" << endl;
    // Affichage pour preuve ;)
    for (int i = 0; i < v.size(); i++) {
        cout << "Element n°" << i << ": " << v[i] << endl;
    }

    // On trie simplement avec la fonction `sort`
    // Rien à faire de mieux parce que l'API C++ sait déjà comparer deux entiers (int)
    // Ce ne sera pas toujours le cas (l'implémentation d'un comparateur peut être nécessaire)
    sort(v.begin(), v.end());

    cout << endl << "Après tri :" << endl;
    // Affichage pour preuve ;)
    for (int i = 0; i < v.size(); i++) {
        cout << "Element n°" << i << ": " << v[i] << endl;
    }

    return 0;
}
