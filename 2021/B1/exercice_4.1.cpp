#include <vector> // Inclusion de la bibliothèque vector
#include <iostream>
using namespace std;

int main(int argc, char **argv)
{
    // Exercice 4.1
    // Constructeur par défaut : le vector est vide
    vector<int> v1;
    // Multiplicateur de valeurs : `10` fois la valeur `0`
    vector<int> v2(10, 0);
    // Constructeur de copie : créer une copie de v2
    // Peut également s'écrire vector<int> v3 = v2;
    vector<int> v3(v2);
    // Constructeur de recopie partielle
    vector<int> v4(v2.begin(), v2.begin() + 5);

    return 0;
}
