#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#ifdef _WIN32
#include <windows.h>
#endif
#include <algorithm>
#include <string>
#include <iomanip>

using namespace std;

/*******************************************************************************
 * Gestion des couleurs de sortie console
 */

#ifdef _WIN32
HANDLE hstdout;
#endif

#ifdef _WIN32
  #define BLEU 9
  #define BLANC 15
  #define ROUGE 12
  #define VERT 10
#else
  #define BLEU 34
  #define BLANC 0
  #define ROUGE 31
  #define VERT 32
#endif

void setcolor(int color) {
    #ifdef _WIN32
    SetConsoleTextAttribute(hstdout, color);
    #else
    cout << "\033[" + to_string(color) + "m";
    #endif
}

void log(string text, int color = BLANC) {
    setcolor(color);
    cout << text;
}

void logln(string text, int color = BLANC) {
    log(text + "\n", color);
}


/*******************************************************************************
 * Classe Combattant
 *
 * Représente un combattant de notre arène.
 * Permet d'attaquer un autre combattant et de subir des dégâts
 */
class Combattant {
private:
    string nom;
    string arme;
    int attaque;
    int defense;
    int vie;
public:

    /**
     * Constructeur
     * @param n : Le nom
     * @param ar : L'arme
     * @param n : Le niveau d'attaque
     * @param n : Le niveau de défense
     */
    Combattant(string n, string ar, int a, int d) {
        this->nom = n;
        this->arme = ar;
        this->attaque = a;
        this->defense = d;
        this->vie = 100;
    }

    /** Getter */
    string getNom() { return this->nom; }
    string getArme() { return this->arme; }
    int getAttaque() { return this->attaque; }
    int getDefense() { return this->defense; }
    int getVie() { return this->vie; }

    /**
     * Afficher le combattant et ses stats
     */
    void afficher() {
        log(this->nom, BLEU);
        log("(" + to_string(this->attaque) + "/" + to_string(this->defense) + ") [" + to_string(this->vie) + "] ");
    }

    /**
     * Attaquer un autre combattant
     * @param adversaire à attaquer
     */
    void attaquer(Combattant &adversaire) {
        int degats = this->attaque;
        this->afficher();
        log("donne un coup de ");
        log(this->arme, ROUGE);
        log(" à ");
        adversaire.afficher();
        adversaire.subit(degats);
    }

    /**
     * Subir des dégats (pondérés par la défense du combattant
     * @param degats : le nombre de dégats à subir
     */
    void subit(int degats) {
        int d = degats * ((100.0 - this->defense) / 100.0);
        log(": ");
        log(to_string(d), ROUGE);
        log(" degats.");
        this->vie -= d;
    }
};


/*******************************************************************************
 * Classe Arene
 *
 * Représente notre arène.
 * Possède une liste de combattant (vivant) et une liste de morts au combat
 * Permet de recruter des combattants, et de lancer la baston
 */
class Arene {
private:
    vector<Combattant*> combattants;
    vector<Combattant*> morts;

public:

    /**
     * Destructeur
     * Libère les instances de Combattants créés pendant la phase de recrutement
     */
    ~Arene() {
        for (unsigned int i = 0; i < this->combattants.size(); i++) {
            delete this->combattants[i];
        }
        for (unsigned int i = 0; i < this->morts.size(); i++) {
            delete this->morts[i];
        }
    }

    /**
     * Recruter un combattant (et l'instancie)
     * @param n : Le nom du combattant
     * @param ar : L'arme du combattant
     * @param n : Le niveau d'attaque du combattant
     * @param n : Le niveau de défense du combattant
     */
    void recruter(string n, string ar, int a, int d) {
        log("Nouveau combattant : ");
        Combattant* c = new Combattant(n, ar, a, d);
        c->afficher(); log(": ");
        logln(c->getArme(), ROUGE);
        this->combattants.push_back(c);
    }

    /**
     * Recruter un combattant (et l'instancie)
     * @param n : Le nom du combattant
     * @param ar : L'arme du combattant
     * @param n : Le niveau d'attaque du combattant
     * @param n : Le niveau de défense du combattant
     */
    void baston() {
        int tour = 1;
        int survivant;
        random_shuffle(this->combattants.begin(), this->combattants.end());
        while (this->combattants.size() > 1) {
            survivant = this->round(tour++);
        }
        logln(""); logln("");
        logln("... And the survivor is ..."); logln("");
        this->combattants[survivant]->afficher(); logln(""); logln("");
        logln(""); logln("");
        logln("... And the deads are ..."); logln("");
        for (unsigned int i = 0; i < this->morts.size(); i++) {
            this->morts[i]->afficher();
        }
        logln("");
    }

    /**
     * Effectue un round de baston
     * Chaque combattant (encore vivant) a l'opportunité d'en attaquer un autre
     * @return le numéro dernier combattant ayant levé la main
     */
    int round(int tour) {
        unsigned int survivant, adversaire;
        logln("");
        logln("ROUND " + to_string(tour), VERT);
        // On ne fait pas un for classique, car la liste combattant évolue pendant la baston...
        // Les règles d'incrémentation du i sont donc complexes.
        unsigned int i = 0;
        while (i < this->combattants.size()) {
            survivant = i;
            adversaire = rand() % (this->combattants.size() - 1);
            if (adversaire >= i) {
                adversaire++;
            }
            this->combattants[i]->attaquer(*(this->combattants[adversaire]));
            // Gestion de la mort de l'adversaire (on enlève le combattant et le stock avec les morts)
            if (this->combattants[adversaire]->getVie() <= 0) {
                log(" Qui meurt :'(");
                this->morts.push_back(this->combattants[adversaire]);
                this->combattants.erase(this->combattants.begin() + adversaire, this->combattants.begin() + adversaire + 1);
                // On modifie le tableau, donc on incrémente que lorsqu'on a enlevé un élément après le combattant courant.
                if (adversaire > i) { i++; }
            } else {
                // Pas de modification de tableau, on incrémente
                i++;
            }
            logln("");
        }
        return survivant;
    }

};

/*******************************************************************************
 * MAIN ENTRANCE
 */
int main()
{
    #ifdef _WIN32
    // Passe la console en UTF8 pour ne plus avoir de problèmes d'accents
    SetConsoleOutputCP(CP_UTF8);
    // Récupère le STD_OUTPUT_HANDLE pour manipuler les couleurs de sortie
    hstdout = GetStdHandle(STD_OUTPUT_HANDLE);
    #endif

    char buffer[9]; // 8 caractères + 1 cartère de fin de chaine

    // Récupérer la date courante
    time_t rawtime;
    time(&rawtime);
    struct tm * timeinfo = localtime(&rawtime);

    // La transformer en chaine de caractère
    strftime(buffer, 9, "%d%m%Y", timeinfo);
    string date(buffer);

    // Intro et question du jour
    logln("BATTLE ROYALE EPSI 2021 : B1 !");
    logln("Quelle date de match (toujours le même résultat pour une date donnée) ? (par défaut, aujourdhui : " + date + " (saisir 0))");
    int seed;
    cin >> seed;

    // Si l'utilisateur saisit 0 on prend la date précalculée
    if (seed == 0) {
        seed = stoi(date);
    }

    // On initalise avec notre "graine"
    srand(seed);

    // Et BASTON !!
    Arene arene;
    int nbCombattant = 31;
    string noms[31] = {"Adrien", "Alexandre", "Amaury", "Antoine", "Axel", "Baptiste", "Cameron L", "Cameron R", "Diana", "Eline", "Elouan", "Enzo", "Erwann", "Félix", "Hassan", "Inès", "Maël", "Magalie", "Mathurin", "Noé", "Paul", "Quentin D", "Quentin R", "Romain C", "Romain D", "Thomas G", "Thomas H", "Thomas T", "Valentin", "Warren", "Yohane"};
    string armes[6] = {"hâche", "katana", "dague", "hallebarde", "masse", "marteau"};
    int stat;
    for (int i = 0; i < nbCombattant; i++ ) {
        stat = 10 + (rand() % 11);
        arene.recruter(noms[i], armes[rand() % 6], stat, 30 - stat);
    }
    arene.baston();

    return 0;
}
