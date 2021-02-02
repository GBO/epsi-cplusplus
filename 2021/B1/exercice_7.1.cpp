#include <vector> // Inclusion de la bibliothèque vector
#include <iostream>
#include <algorithm>
#include <time.h>
#include <random>
#include <cmath>
using namespace std;



class Rectangle {
    private:
        // Les attributs en private par défaut
        int hauteur;
        int largeur;

    public:
        // Les getters / setters (ou accesseurs / mutateurs) des attributs
        int getHauteur() {
            return this->hauteur;
        }
        int getLargeur() {
            return this->largeur;
        }
        void setHauteur(int t_hauteur) {
            this->hauteur = t_hauteur;
        }
        void setLargeur(int t_largeur) {
            this->largeur = t_largeur;
        }

        
        void afficher() {
            // La méthode afficher travaille avec les attributs de l'instance en cours.
            // Instance représentée par le mot-clé this : un pointeur vers l'instance courante.
            // Ici, this est de type Rectangle*
            cout << "Rectangle " << this << " (" << this->hauteur << "m x " << this->largeur << "m) : " << this->getPerimetre() << "m de contour & " << this->getSurface() << "m2" << endl;
        }

        int getPerimetre() {
            // La méthode travaille avec les attributs de l'instance en cours.
            return (this->hauteur + this->largeur) * 2;
        }

        int getSurface();
};

int Rectangle::getSurface()  {
    // La méthode travaille avec les attributs de l'instance en cours.
    // Même si je suis en dehors du corps de la classe.
    // J'ai ici les mêmes droits que dans la méthode getPerimetre définie plus haut.
    return this->hauteur * this->largeur;
}


int main(int argc, char **argv)
{
    // Exercice 7.1
    // Déclaration et instanciation d'un Rectangle.
    Rectangle r1;
    r1.setHauteur(12);
    r1.setLargeur(21);
    r1.afficher();

    // Invocation du constructeur de recopie (un autre constructeur par défaut)
    // Cette ligne est strictement équivalente à la suivante.
    // Rectangle r2 = r1;
    Rectangle r2(r1);

    cout << "---" << endl;

    // On voit que nous avons bien 2 instances (adresses & attributs différents)
    r1.setHauteur(21);
    r1.afficher();
    r2.afficher();

    cout << "---" << endl;

    // Juste on déclare un pointeur
    Rectangle* p1;
    // Là, on instancie un nouveau rectangle dont l'adresse est stockée dans un pointeur.
    p1 = new Rectangle;
    // Là on instancie rien, on crée juste un nouveau pointeur dont le contenu est le même
    // que p1. Donc 2 pointeurs qui pointent sur une seule instance.
    Rectangle* p2 = p1;

    p1->setHauteur(4);
    p1->setLargeur(8);
    
    // On voit que nous avons bien qu'une seule instance pointée par 2 pointeurs différents.
    // Ces 2 lignes invoquent la même méthode sur la même instance : donc résultat strictement
    // identique.
    p1->afficher();
    p2->afficher();

    // On n'oublie pas le delete, bien évidemment (oublié en séance, j'ai honte)
    delete p1;
    // On a besoin de ne le faire qu'une seule fois car un seul new a été fait.
    // Ce qui pose la question de la valeur de p2 (et même de p1) après cette ligne.
    // Et bien, elle reste inchangée : c'est toujours l'adresse qu'on a mis plus haut.
    // Par contre écrire p2->nimportequoi(); va aboutir à n'importe quoi. Il n'y a plus
    // d'instance au bout de la ligne.

    return 0;
}
