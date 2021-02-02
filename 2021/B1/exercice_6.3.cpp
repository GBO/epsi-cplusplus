#include <vector> // Inclusion de la bibliothèque vector
#include <iostream>
#include <algorithm>
#include <time.h>
#include <random>
#include <cmath>
using namespace std;

// La fonction développée en exercice 5.4
void inverser_parametres(int& a, int& b) {
    cout << "Invocation par référence :)" << endl;
    int temp = a;
    a = b;
    b = temp;
}

void inverser_parametres(int* a, int* b) {
    cout << "Invocation par pointeur :D" << endl;
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main(int argc, char **argv)
{
    // Exercice 6.3
    int i1 = 6;
    int i2 = 9;
    int* p1 = new int(66);
    int* p2 = new int(99);


    cout << "Avant : " << endl;
    cout << "Entiers : " << i1 << " / " << i2 << endl;
    cout << "Pointeurs : " << *p1 << " / " << *p2 << endl;

    // Invocation par référence
    inverser_parametres(i1, i2);
    // Invocation par pointeur
    inverser_parametres(p1, p2);
    // C'est le compilateur qui décide et qui fait le calcul à partir des types des paramètres.

    cout << "Après 1 : " << endl;
    cout << "Entiers : " << i1 << " / " << i2 << endl;
    cout << "Pointeurs : " << *p1 << " / " << *p2 << endl;

    // *p1 est un int (puisque p1 est un int*). Donc invocation par référence.
    inverser_parametres(*p1, *p2);
    // &i1 est la réference de i1, l'adresse de i1, un pointeur, genre. Donc invocation par pointeur.
    inverser_parametres(&i1, &i2);

    cout << "Après 2 : " << endl;
    cout << "Entiers : " << i1 << " / " << i2 << endl;
    cout << "Pointeurs : " << *p1 << " / " << *p2 << endl;

    // 2 new => 2 delete !
    delete p1;
    delete p2;

    return 0;
}
