// Inclusion des librairies
#include <iostream> // pour cin / cout
#include <cstdlib> // pour rand
#include <ctime> // pour time()
#include <vector>

using namespace std;



class Etudiant {
  private:
    string nom;
    int vie;
    int attaque;
  
  public:
    Etudiant(string nom) {
      this->nom = nom;
      this->vie = 100;
      this->attaque = 7 + (rand() % 7);
    }

    void afficher() {
      cout << this->nom << "(" << this->vie << "/" << this->attaque << ")";
    }

    void attaquer(Etudiant* cible) {
      this->afficher();
      cout << " attaque ";
      cible->afficher();
      cout << endl;

      cible->subir(this->attaque);
    }

    void subir(int degats) {
      this->afficher();
      cout << " subit " << degats << " dégats !" << endl;

      this->vie -= degats;
    }

    bool ko() {
      return (this->vie < 1);
    }
};

class Arene {
  private:
    vector<Etudiant*> etudiants;
    vector<Etudiant*> etudiants_ko;
  
  public:

    void entrer(Etudiant* e) {
      e->afficher();
      cout << " entre dans l'arène..." << endl;
      this->etudiants.push_back(e);
    }

    void afficher() {
      cout << "L'arène (" << this->etudiants.size() << ") : ";
      for (int i = 0; i < this->etudiants.size(); i++) {
        this->etudiants[i]->afficher();
        cout << ", ";
      }
      cout << endl;
      if (this->etudiants_ko.size() > 1) {
        cout << "Les vaincus (" << this->etudiants_ko.size() << ") : ";
        for (int i = 0; i < this->etudiants_ko.size(); i++) {
          cout << (i + 1) << ": ";
          this->etudiants_ko[i]->afficher();
          cout << ", ";
        }
        cout << endl;
      }
    }

    void round() {
      int attaquant = 0;
      int cible = 0;
      while (attaquant == cible) {
        attaquant = rand() % this->etudiants.size();
        cible = rand() % this->etudiants.size();
      }

      this->etudiants[attaquant]->attaquer(this->etudiants[cible]);
      if (this->etudiants[cible]->ko()) {
        this->etudiants_ko.push_back(this->etudiants[cible]);
        this->etudiants.erase(this->etudiants.begin() + cible);
      }
    }

    void match() {
      int round = 1;
      while (this->etudiants.size() > 1) {
        cout << "ROUND " << round << " : " << endl;
        this->round();
        round++;
      }
      this->etudiants[0]->afficher();
      cout << " gagne le match !" << endl;
    }


};

// Un main dans lequel j'invoque quelques fonctions d'exercice...
int main(int argc, char **argv)
{
  // Initialisation du générateur de nombre aléatoire
  srand(time(NULL));

  cout << "Arene B1 - 2021" << endl;

  Arene* arene = new Arene;
  arene->entrer(new Etudiant("Adrien"));
  arene->entrer(new Etudiant("Alexandre"));
  arene->entrer(new Etudiant("Amaury"));
  arene->entrer(new Etudiant("Antoine"));
  arene->entrer(new Etudiant("Axel"));
  arene->entrer(new Etudiant("Baptiste"));
  arene->entrer(new Etudiant("Cameron L"));
  arene->entrer(new Etudiant("Cameron R"));
  arene->entrer(new Etudiant("Diana"));
  arene->entrer(new Etudiant("Eline"));
  arene->entrer(new Etudiant("Elouan"));
  arene->entrer(new Etudiant("Enzo"));
  arene->entrer(new Etudiant("Erwann"));
  arene->entrer(new Etudiant("Félix"));
  arene->entrer(new Etudiant("Hassan"));
  arene->entrer(new Etudiant("Inès"));
  arene->entrer(new Etudiant("Maël"));
  arene->entrer(new Etudiant("Magalie"));
  arene->entrer(new Etudiant("Mathurin"));
  arene->entrer(new Etudiant("Noé"));
  arene->entrer(new Etudiant("Paul"));
  arene->entrer(new Etudiant("Quentin D"));
  arene->entrer(new Etudiant("Quentin R"));
  arene->entrer(new Etudiant("Romain C"));
  arene->entrer(new Etudiant("Romain D"));
  arene->entrer(new Etudiant("Thomas G"));
  arene->entrer(new Etudiant("Thomas H"));
  arene->entrer(new Etudiant("Thomas T"));
  arene->entrer(new Etudiant("Valentin"));
  arene->entrer(new Etudiant("Warren"));
  arene->entrer(new Etudiant("Yohane"));

  arene->afficher();
  arene->match();
  arene->afficher();


  

  return 0;
}

