# Support de cours EPSI : Langage C++ - Exercices

## 0. Ce qui est attendu

Les exercices de ce support sont de simples problèmes algorithmiques ou de manipulation de l'API C++ : une application  console suffit pour les résoudre.

Il sera demandé à chaque fois de produire un programme validant une liste d'exigences.
Le plus simple est bien souvent de créer un fichier main.cpp contenant une fonction `main` effectuant les opérations demandées.

La structure d'une réponse à un exercice ressemblera donc régulièrement à :
```c++
#include <iostream>
using namespace std;

int main(int argc, char **argv)
{
  cout << "Exercice 1.1" << endl;
  cout << "Hello world!" << endl;
  return 0;
}
```

Avec une notice explicative :
```c++
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
```


## 1. Premiers pas

## Exercice 1.1
Exigences :
* Afficher "Hello EPSI !"

Aides :
* Utilisation de la librairie `iostream`
* Utilisation du flux `std::cout` : sortie standard.
* Utilisation de la constante `std::endl` : caractère de saut de ligne de la plateforme de compilation.
* Utilisation de l'opérateur `<<` : envoi de donnée dans un flux.

## Exercice 1.2
Exigences :
* Calculer le périmètre et l'air d'un champ dont la longueur & la largeur sont demandées à l'utilisateur.

Aides :
* Utilisation du flux `std::cin` : entrée standard.
* Utilisation de l'opérateur `>>` : lecture dans un flux.
* Utilisation d'opérateurs arithmétique & affectations.

## Exercice 1.3
Exigences :
* Demander la saisie de 2 valeurs à stocker dans 2 variables a & b.
* Intervertir les 2 valeurs avant de les afficher (b doit contenir la valeur de a, et a la valeur de b).

Aides :
* Petit problème algorithmique classique.

## Exercice 1.4
Exigences :
* Calculer la moyenne de 5 valeurs saisies par l'utilisateur.

Aides :
* Différence entre `5` et `5.0` : le premier est un entier (`int`) alors que le second est un flottant (`float`).
* Les opérations sont typées : `1 + 1` ne donne pas le même résultat que `1.0 + 1.0`.

---
## 2. Les structures de contrôles

## Exercice 2.1
Exigences :
* Valider que la saisie utilisateur d'un nombre se situe entre 2 bornes arbitraires.

Aides :
* Mise en pratique du `if` : structure de test.

## Exercice 2.2
Exigences :
* Afficher les entiers de 1 à 100.

Aides :
* Mise en pratique du `for` (ou du `while` (ou les deux)) : structure de boucles.

## Exercice 2.3
Exigences :
* Afficher le plus petit entier des 5 saisis par l'utilisateur

Aides :
* Problème algorithmique à base de `for` (ou de `while`).

## Exercice 2.4
Exigences :
* Demander à l'utilisateur de saisir un nombre entre 2 bornes jusqu'à ce que la saisie soit bonne.

Aides :
* Problème algorithmique de `while`.

## Exercice 2.5
Exigences :
* Calculer la moyenne d'une liste de nombre entier positif.
* L'utilisateur peut saisir autant de nombres entiers positifs qu'il veut.
* Un message d'erreur apparaît si l'utilisateur saisit un nombre négatif.
* Pour terminer la saisie l'utilisateur doit saisir 0.
* Afficher un message d'erreur si l'utilisateur n'a rien saisi (s'il est sorti dès le premier tour).

## Exercice 2.6
Exigences : produire une calculatrice en mode console.
* L'utilisateur doit saisir alternativement un nombre puis une opération à travers un petit menu.
* Après chaque saisie de nombre (sauf le premier) on affiche le résultat de l'opération.
* Les opérations sont l'addition, la soustraction et la multiplication.
* A la saisie de l'opération, l'utilisateur peut saisir 0 pour quitter le programme.

Aides :
* Un menu est un texte affiché et ressemblant à "0- Sortie, 1- Addition, 2-Soustraction, 3- Multiplication".
* Le chiffre saisie en dessous correspond à l'entrée du menu.

## Exercice 2.7
Exigences :
* Calculer la factorielle du nombre saisi par l'utilisateur.

Aides :
* [La factorielle d'un entier naturel n est le produit des nombres entiers strictement positifs inférieurs ou égaux à n.](https://fr.wikipedia.org/wiki/Factorielle)



---
## 3. Les tableaux


---
## 4. Les fonctions


---
## 5. Les pointeurs


---
## 6. Les classes


---
## 7. Les vector


