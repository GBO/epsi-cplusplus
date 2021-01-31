// Inclusion de la librairie iostream qui permet d'utiliser entre autre `cin` & `cout`
#include <iostream>
// Utilisation du namespace std pour s'économiser quelques caractères plus bas.
// Sans cette instruction, il faudrait toujours utiliser `std::cout` au lieu de `cout`
using namespace std;

// Déclaration et implémentation de la fonction `main`, le point d'entrée de l'application
int main(int argc, char **argv)
{
  // Envoyer la chaîne de caratères "Exercice 1.1" dans le flux `cout` (sortie
  // standard) puis `endl` (constante également fournie par `iostream` et
  // contenant le caractère de saut de ligne de la plateforme de compilation).
  cout << "Exercice 1.1" << endl;
  // La même chose mais avec la chaîne de caratères "Hello world!.
  cout << "Hello world!" << endl;
  // Interrompre la fonction et lui faire retourner la valeur 0
  // `main` étant le point d'entrée de l'application, c'est également sa srotie.
  // On termine l'exécution du programme  ici.
  // Le 0 sera également retourné comme valeur de sortie de l'application.
  return 0;
}
