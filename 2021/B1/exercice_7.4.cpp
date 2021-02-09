#include <vector> // Inclusion de la bibliothèque vector
#include <iostream>
#include <fstream>
#include <algorithm>
#include <time.h>
#include <random>
#include <cmath>
using namespace std;

/** Un Node représente la tête de notre liste chaînée.
 * Toutes les opérations de la liste chaînées sont disponibles au niveau du Node.
 * On parcourt ainsi toute la liste par appels successifs aux éléments suivants.
 */
class Node {
    private:
        int valeur;
        Node* suivant;

    public:
        /** Constructeur de Node
         * Permet de recopier intégralement un Node
         */
        Node(int valeur = 0, Node* suivant = nullptr) {
            this->valeur = valeur;
            this->suivant = suivant;
        }

        /** Destructeur
         * Il est requis car détruire un Node, c'est détruire son suivant également...
         * Qui détruira son suivant, etc, etc...
         * 
         * On est obligé de faire ça. C'est le choix d'implémentation qui veut ça.
         * suivant est un pointeur de Node, il doit donc être alloué. Il doit donc être libéré.
         */
        ~Node() {
            if (this->suivant != nullptr) {
                delete this->suivant;
            }
        }

        /** Retourner un élément de la liste
         * La méthode n'est pas demandée, mais on sent bien qu'elle sera nécessaire pour l'utilisateur
         * Elle permet par ailleurs de simplifier quelques méthodes ensuite
         */
        Node* get(int indice) {
            Node* result = nullptr; // Valeur par défaut qui sera retournée si non
            if (indice == 0) {
                // Indice 0 : c'est moi même !
                return this;

            } else if (this->suivant != nullptr) {
                // On demande au suivant de régler le problème
                return this->suivant->get(indice - 1);

            } else {
                // On retourne nullptr lorsque l'indice ne peut être atteint.
                // `indice` ici n'est pas encore égal à zero, et pourtant, il n'y
                // a plus de suivant à qui repasser la balle...
                return nullptr;

            }
        }

        /** Retourner la fin.
         * C'est un get particulier qui cherche simplement le dernier élément.
         */
        Node* end() {
            if (this->suivant == nullptr) {
                // Pas de suivant, on a atteint la fin !
                return this;
            } else {
                // Sinon, on demande au suivant...
                return this->suivant->end();
            }
        }

        void add(int valeur) {
            // Je suis le dernier : je peux ajouter !
            if (this->suivant == nullptr) {
                this->suivant = new Node(valeur);
            } else {
                // Je ne suis pas le dernier : je demande au suivant
                // this->suivant->add(valeur);
                // Ou directement au dernier :
                this->end()->add(valeur);
            }
        }

        void insert(int valeur, int indice) {
            // Insérer à ma place : je sais faire.
            if (indice == 0) {
                this->suivant = new Node(this->valeur, this->suivant);
                this->valeur = valeur;
            
            // Insérer ailleurs, je vais demander de l'aide aux suivants s'ils existent.
            //
            // Version avec recherche intégrée
            // } else if (this->suivant != nullptr) {
            //     this->suivant->insert(valeur, indice - 1);
            // } else {
            //     cout << "ERREUR insert : L'indice est en dehors de la liste !" << endl;
            // }

            // Version en passant directement au bon élément
            } else {
                Node* node = this->get(indice);
                if (node != nullptr) {
                    node->insert(valeur, 0);
                } else {
                    cout << "ERREUR insert : L'indice est en dehors de la liste !" << endl;
                }
            }
        }

        void remove(int indice) {
            if (indice == 0) {
                // On touche là, le gros défaut d'implémentation : ma liste doit avoir au moins
                // un élément. Je ne peux donc pas supprimer le dernier élément :/
                if (this->suivant != nullptr) {
                    Node* a_supprimer = this->suivant;
                    this->valeur = this->suivant->valeur;
                    this->suivant = this->suivant->suivant;
                    delete a_supprimer;
                } else {
                    cout << "ERREUR remove : La liste ne peut pas être vide !" << endl;
                }

            // Idem que pour insert : je demande de l'aide !
            } else if (this->suivant != nullptr) {
                this->suivant->remove(indice - 1);

            } else {
                cout << "ERREUR remove : L'indice est en dehors de la liste !" << endl;

            }
        }

        int count() {
            // Si je suis le dernier, je me compte et ça fait 1
            if (this->suivant == nullptr) {
                return 1;

            // ...Sinon, je suis un de plus que le suivant !
            } else {
                return 1 + this->suivant->count();

            }
        }

        void display() {
            // Je m'affiche
            cout << "Valeur : " << this-> valeur << endl;
            // Et je demande au suivant de s'afficher (s'il existe)
            if (this->suivant != nullptr) {
                this->suivant->display();
            }
        }
};



int main(int argc, char **argv)
{
    // Exercice 7.4

    Node* node = new Node(42);

    cout << "Etape 1" << endl;
    node->display();
    cout << "On se compte : " << node->count() << endl;

    cout << "Etape 2" << endl;
    node->add(666);
    node->display();
    cout << "On se compte : " << node->count() << endl;

    cout << "Etape 3" << endl;
    node->insert(333, 0);
    node->display();
    cout << "On se compte : " << node->count() << endl;

    cout << "Etape 4" << endl;
    node->remove(1);
    node->display();
    cout << "On se compte : " << node->count() << endl;

    delete node;

    return 0;
}
