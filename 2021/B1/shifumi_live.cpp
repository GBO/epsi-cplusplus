// Inclusion des librairies
#include <iostream> // pour cin / cout
#include <cstdlib>  // pour rand
#include <ctime>    // pour time()

// Utilisation du namespace std pour s'économiser quelques caractères plus bas.
// Sans cette instruction, il faudrait toujours utiliser `std::cout` au lieu de `cout`
using namespace std;



class Joueur
{
private:
    string nom;

public:
    Joueur(string nom) {
        this->nom = nom;
    }

    string get_nom() {
        return this->nom;
    }

    virtual int choisir() {
        int choix = -1;
        cout << this->nom << ": veuillez choisir Pierre (0), Feuille (1) ou Ciseaux (2) : " << endl;
        while (choix < 0 || choix > 2) {
            cin >> choix;
        }
        return choix;
    }
};

class Bot1 : public Joueur
{
public:
    Bot1(string nom) : Joueur(nom) {
        // Initialisation propre à la classe Bot1
    }

    virtual int choisir() {
        return 0;
    }
};

class Bot2 : public Joueur
{
public:
    Bot2(string nom) : Joueur(nom) {
        // Initialisation propre à la classe Bot1
    }

    virtual int choisir() {
        return rand() % 3;
    }
};

class Shifumi
{
private:
    Joueur *j1;
    Joueur *j2;
    string noms[3];

public:
    Shifumi(Joueur *j1, Joueur *j2)
    {
        this->j1 = j1;
        this->j2 = j2;

        this->noms[0] = "Pierre";
        this->noms[1] = "Feuille";
        this->noms[2] = "Ciseaux";
    }

    void round()
    {
        int choixj1 = j1->choisir();
        int choixj2 = j2->choisir();

        cout << j1->get_nom() << " a choisi " << this->noms[choixj1] << "..." << endl;
        cout << j2->get_nom() << " a choisi " << this->noms[choixj2] << "..." << endl;

        if (choixj1 == choixj2) {
            cout << "Egalité !" << endl;
        } else if ((choixj1 == 0 && choixj2 == 2) || (choixj1 > choixj2)) {
            cout << j1->get_nom() << " gagne !" << endl;
        } else {
            cout << j2->get_nom() << " gagne !" << endl;
        }
    }

    void match()
    {
    }
};

// Un main dans lequel j'invoque quelques fonctions d'exercice...
int main(int argc, char **argv)
{
    cout << "TD Noté de Ghislain BOUCHET - EPSI - 09/02/2021" << endl;

    // Initialisation du générateur de nombre aléatoire
    srand(time(NULL));

    Joueur* ghislain = new Bot1("Ghislain");
    Joueur* georges = new Bot2("Georges");

    Shifumi* jeu = new Shifumi(ghislain, georges);

    jeu->round();
    jeu->round();
    jeu->round();
    jeu->round();
    jeu->round();

    return 0;
}