// Inclusion des librairies
#include <iostream> // pour cin / cout
#include <cstdlib> // pour rand
#include <ctime> // pour time()

// Utilisation du namespace std pour s'économiser quelques caractères plus bas.
// Sans cette instruction, il faudrait toujours utiliser `std::cout` au lieu de `cout`
using namespace std;

bool est_premier(int nombre) {
  int nb_diviseur = 2;

  for (int i = 2; i < nombre; i++) {
    if (nombre % i == 0) {
      nb_diviseur++;
    }
  }

  return nb_diviseur == 2;
}


/** Un petit bloc de commentaire pour passer quelques infos sur l'exercice 1.
 * La fonction identifie clairement l'exercice...
 */
void exercice1() {
  // Ca nous empêche pas de le sortir sur la console au cas où.
  cout << "Exercice 1" << endl;
  // Ici une résolution du problème posé par l'exercice 1

  int nombre_de_nombre_premier;
  cout << "Combien de nombre premier afficher ? " << endl;
  cin >> nombre_de_nombre_premier;

  int compteur = 0;
  int i = 0;
  while (compteur < nombre_de_nombre_premier) {

    if (est_premier(i)) {
      cout << "Un nombre premier : " << i << endl;
      compteur++;
    }

    i++;
  }
}




// Un main dans lequel j'invoque quelques fonctions d'exercice...
int main(int argc, char **argv)
{
  cout << "TD Noté de Ghislain BOUCHET - EPSI - 09/02/2021" << endl;

  // Initialisation du générateur de nombre aléatoire
  srand(time(NULL));
  // Génération de nombres aléatoires
  int alea = rand();
  cout << "Nombre aléatoire brut : " << alea << endl;
  alea = rand() % 100;
  cout << "Nombre aléatoire entre 0 (inclu) et 99 (inclu) : " << alea << endl;

  // Et c'est parti !
  exercice1();

  return 0;
}

