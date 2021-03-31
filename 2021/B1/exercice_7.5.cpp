#include <iostream> // pour cin / cout
#include <cstdlib>  // pour rand
#include <ctime>    // pour time()
#include <vector>    // pour time()

using namespace std;

/**
 * Piece : Classe parente
 * Décrit les attributs et comportements génériques d'une Piece d'échiquier
 */
class Piece {
protected:
    string nom; // Nom de la pièce
    int x;      // Coordonnées X
    int y;      // Coordonnées Y

public:
    /** Constructeur
     * En paramètre : ce qui définit une Pièce au minimum */
    Piece(string nom, int x, int y) {
        this->nom = nom;
        this->x = x;
        this->y = y;
    }

    /** Afficher une pièce (son nom et ses coordonnées) */
    void afficher() {
        cout << this->nom << ": " << this->x << "x" << this->y << endl;
    }

    /** Déplacer : effectue le déplacement et retourne vrai, sinon retourne faux.
     * Implémentation par défaut : tout déplacement est autorisé.
     */
    virtual bool deplacer(int x, int y) {
        this->x = x;
        this->y = y;
        return true;
    }

    /** Exemple de méthode */
    virtual bool suis_je_fou() {
        return false;
    }
};

/** Une première spécialisation de Piece : le Pion */
class Pion: public Piece {
public:
    /** Obligé de déclarer un constructeur,
     * qui ne fait qu'invoquer le constructeur de Piece avec
     * une constante pour le nom */
    Pion(int x, int y): Piece("Pion", x, y) { }

    /** Seule vraie spécialisation : le déplacement ne se 
     * résout pas de la même manière */
    virtual bool deplacer(int x, int y) {
        // Pour simplifier le seule déplacement autorisé est :
        // +1 vers le "haut", autrement un de plus en y uniquement
        if ((y == (this->y + 1)) && (this->x == x)) {
            this->x = x;
            this->y = y;
            return true;
        } else {
            return false;
        }
    }
};


/** Une deuxième spécialisation de Piece : le Fou */
class Fou: public Piece {
public:
    /** Idem pour le constructeur obligatoire */
    Fou(int x, int y): Piece("Fou", x, y) { }

    /** Idem : le déplacement est spécifique au Fou */
    virtual bool deplacer(int x, int y) {
        // Ici : la même quantité de déplacement horizontal et
        // vertical est requise
        if (abs(this->y - y) == abs(this->x - x)) {
            this->x = x;
            this->y = y;
            return true;
        } else {
            return false;
        }
    }

    /** Notre seul cas de surcharge de la méthode suis_je_fou
     * qui retourne vraie pour le Fou uniquement */
    virtual bool suis_je_fou() {
        return true;
    }

};


int main(int argc, char **argv)
{
    cout << "Exercice 7.5" << endl;
    cout << "Nouvelle illustration de l'héritage et du polymorphisme : 30/03/2021" << endl;

    // Initialisation du générateur de nombre aléatoire
    srand(time(NULL));

    // On teste avec une première Pièce générique
    Piece* piece = new Piece("Une Pièce quelconque", 2, 2);
    piece->afficher();
    if (!piece->deplacer(3, 3)) { cout << "Déplacement interdit !" << endl; }
    piece->afficher();

    // On instancie un Pion, mais on le stocke dans une variable de type Piece
    // Parce que c'est possible :)
    Piece* pion = new Pion(0, 0);
    pion->afficher();
    if (!pion->deplacer(3, 3)) { cout << "Déplacement interdit !" << endl; }
    pion->afficher();
    if (!pion->deplacer(0, 1)) { cout << "Déplacement interdit !" << endl; }
    pion->afficher();
    // On ne peut par contre dans ce cas seulement invoquer des méthodes
    // définies dans Piece. Une methode uniquement déclarer dans Fou ne serait
    // pas accessible ici...
    pion->suis_je_fou();

    Piece* fou = new Fou(0, 0);
    fou->afficher();
    if (!fou->deplacer(3, 3)) { cout << "Déplacement interdit !" << endl; }
    fou->afficher();
    if (!fou->deplacer(0, 1)) { cout << "Déplacement interdit !" << endl; }
    fou->afficher();

    fou->suis_je_fou();

    // Illustration :
    // L'intérêt d'utiliser des variables de type Piece même si elles sont
    // d'une classe héritée : le polymorphisme :)
    vector<Piece*> pieces;
    pieces.push_back(pion);
    pieces.push_back(fou);

    // En tirant une piece au hasard...
    Piece* une_piece_au_hasard = pieces[rand() % pieces.size()];
    // ...je ne suis pas capable de dire ici quelle implémentation de la
    // méthode deplacer est réellement invoquée ici.
    // C'est même inconaissable à la compilation...
    // C'est ça le polymorphisme : la capacité d'invoquer une méthode sans
    // connaitre l'implémentation qui va réellement être invoquée.
    une_piece_au_hasard->deplacer(12, 12);

    // Ici, j'ai évidemment delete toutes les instances que j'ai créé avant
    // Parce qu'il faut toujours faire des delete quand on fait des new ! ;)

    return 0;
}