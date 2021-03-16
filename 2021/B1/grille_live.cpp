#include <iostream> // pour cin / cout
#include <cstdlib>  // pour rand
#include <ctime>    // pour time()
#include <vector>    // pour time()

using namespace std;


class Piece {
private:
    string nom;
    int i;
    int j;

public:
    Piece(string nom) {
        this->nom = nom;
        this->i = 0;
        this->j = 0;
    }

    void set_position(int i, int j) {
        this->i = i;
        this->j = j;
    }

    int get_i() { return this->i; }
    int get_j() { return this->j; }

    void afficher() {
        cout << this->nom[0];
    }
};


class GrilleV1 {

private:
    vector<Piece*> tableau;
    int largeur;
    int hauteur;

public:
    GrilleV1(int largeur, int hauteur) {
        this->largeur = largeur;
        this->hauteur = hauteur;
        tableau.resize(hauteur * largeur, nullptr);
    }

    int get_largeur() { return this->largeur; }
    int get_hauteur() { return this->hauteur; }

    int coord_to_index(int i, int j) {
        return (j * this->largeur) + i;
    }

    Piece* get(int i, int j) {
        return this->tableau[this->coord_to_index(i, j)];
    }

    void set(int i, int j, Piece* value) {
        this->tableau[this->coord_to_index(i, j)] = value;
    }

    void afficher() {
        for (int j = 0; j < this->hauteur; j++) {
            for (int i = 0; i < this->largeur; i++) {
                Piece* caze = this->get(i, j);
                if (caze == nullptr) {
                    cout << "~";
                } else {
                    caze->afficher();
                }
                cout << " ";
            }
            cout << endl;
        }
    }

};



class GrilleV2 {

private:
    vector<Piece*> tableau;
    int largeur;
    int hauteur;

public:
    GrilleV2(int largeur, int hauteur) {
        this->largeur = largeur;
        this->hauteur = hauteur;
    }

    int get_largeur() { return this->largeur; }
    int get_hauteur() { return this->hauteur; }

    int coord_to_index(int i, int j) {
        return (j * this->largeur) + i;
    }

    Piece* get(int i, int j) {
        Piece* result = nullptr;
        for (int index = 0; index < this->tableau.size(); index++) {
            if ((i == this->tableau[index]->get_i()) && (j == this->tableau[index]->get_j())) {
                result = this->tableau[index];
                break;
            }
        }
        return result;
    }

    void add(Piece* value) {
        this->tableau.push_back(value);
    }

    void afficher() {
        for (int j = 0; j < this->hauteur; j++) {
            for (int i = 0; i < this->largeur; i++) {
                Piece* caze = this->get(i, j);
                if (caze == nullptr) {
                    cout << "~";
                } else {
                    caze->afficher();
                }
                cout << " ";
            }
            cout << endl;
        }
    }

};


int main(int argc, char **argv)
{
    cout << "Grille LIVE - EPSI - 16/03/2021" << endl;

    // Initialisation du générateur de nombre aléatoire
    srand(time(NULL));

    /*
    int tableau[8][8];
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            cout << tableau[i][j];
        }
    }
    */

    GrilleV1* grille = new GrilleV1(8, 4);
    grille->set(2, 3, new Piece("Fou"));
    grille->set(1, 1, new Piece("Cavalier"));
    grille->get(1, 4);
    grille->afficher();

    cout << " - - - - " << endl;

    GrilleV2* grille2 = new GrilleV2(8, 4);
    Piece* piece = new Piece("Fou");
    piece->set_position(2, 3);
    grille2->add(piece);
    piece = new Piece("Cavalier");
    piece->set_position(1, 1);
    grille2->add(piece);
    grille2->afficher();

    return 0;
}