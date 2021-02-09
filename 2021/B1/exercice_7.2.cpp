#include <vector> // Inclusion de la bibliothèque vector
#include <iostream>
#include <fstream>
#include <algorithm>
#include <time.h>
#include <random>
#include <cmath>
using namespace std;



class Fichier {
    private:
        string nom;

    public:
        Fichier(string nom) {
            cout << "Bonjour " << nom << endl;
            this->nom = nom;
        }

        ~Fichier() {
            cout << "Au revoir " << endl;
        }

        void ecrire(string contenu) {
            cout << "Je vais écrire '" << contenu << "' dans " << this->nom << endl;
            
            ofstream ostrm(this->nom, ios::binary);
            ostrm << contenu << endl;
        }

        void lire() {
            // read back
            ifstream istrm(this->nom);
            string s;
            string contenu = "";
            // Solution à base de operator>> (donc donnée formattée)
            // Dans notre cas, il va lire mot par mot (en considérant les espaces comme délimiteur)
            // La solution n'est pas idéale, et 
            // while (istrm >> s) {
            //     contenu += s + " ";
            // }

            // Solution simple à base de getline et plus complète par rapport à notre besoin.
            // C'était bien en utilisant le getline, mais pas la méthode getline de ifstream.
            // C'est la fonction getline de la lib string plus simplement ^_^'
            // Source : https://cpp.developpez.com/faq/cpp/?page=Manipulation-des-fichiers#Comment-faire-pour-lire-un-fichier-ligne-par-ligne
            // Reference : https://en.cppreference.com/w/cpp/string/basic_string/getline
            while (getline(istrm, s)) {
                contenu += s;
            }

            cout << "Le contenu lu : " << contenu << '\n';
        }
};


int main(int argc, char **argv)
{
    // Exercice 7.2
    Fichier* f = new Fichier("un_fichier.txt");

    f->ecrire("Un contenu quelconque");
    f->lire();

    cout << "Avant le delete" << endl;
    delete f;
    cout << "Après le delete" << endl;

    return 0;
}
