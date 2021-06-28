# TDN1 - 28/06/2021
Sources: https://github.com/GBO/epsi-cplusplus/blob/master/2021/B1/TDN/2021-06-28_Rattrapage.md

**Attendu en fin de session** :
* Une application console C++ dans un unique fichier .cpp dont le nom commence par **votre nom de famille** et contenant les sources des différents exercices.
* Les classes qu’il est demandé de produire seront créées en début de fichier, les tests d’utilisation de ces classes seront mis dans la fonction `main` du fichier CPP, l’exercice clairement identifié.

**Critères de notation** :
* Originalité du code produit : dans le sens donner l'impression que le code est bien de l'auteur, et non un copier/coller barbare. Ce peut être mis en évidence par une bonne docucmentation du code, mettant en évidence la maitrise de ce qui est écrit.
* Lisibilité du code (commentaires dans le code, sortie explicite, …).
* Respect des exigences *Attendu en fin de session*.
* Respect des exigences de chaque exercice.
* Résultat attendu prouvé par un test.

**Conseils** :
* Lisez bien les intitulés : le respect de toutes les exigences est important.
* Ne restez pas bloqué sur un problème, essayez de contourner (retourner une valeur statique pour un calcul en respectant les consignes par exemple).
* Utilisez l’aide à votre disposition.
* Pour les instances de vos classes : utilisez des pointeurs pour en stocker les réfénces. Ca vous simplifiera la vie.
  * Dit autrement : faites toujours des `MaClasse* p = new MaClasse(...);`.

# Général (2 points)
Note sur l'aspect général de la copie :
* Lisibilité
* Respects des exigences

# Exercice 1 (10 points)
**Exigences** :
* Ecrire une classe `Combattant` :
  * Avec les attributs suivants et leurs accesseurs (getter) sans mutateurs (setter) :
    * String : `nom` (le nom du combattant).
    * Entier non signé : `force`, `vitesse` (les caractéristiques).
    * Entier : `vie` (le niveau de vie du combattant).
  * Un constructeur prenant en paramètre le nom et les caractéristiques et interdisant une somme des caractéristiques supérieure à 20. La `vie` du `Combattant` est initialisée à 100.
  * Implémenter les méthodes suivantes :
    * `afficher` permettant d'afficher le `Combattant` (son nom) et ses caractéristiques.
    * `attaquer` prenant en paramètre un `Combattant` adverse et infligeant les dégâts à ce dernier : le nombre de dégâts infligés est égal à la `force` de l'attaquant.
    * `subir` prenant en paramètre un nombre de dégâts et affectant la `vie` du `Combattant` subissant les dégâts.

**Tests** :
* Instancier 2 objets de la classe `Combattant` et les afficher dans la console (avec la méthode `afficher()`).

# Exercice 2 (8 points)
**Exigences** :
* Ecrire une classe `Arene` :
  * Permettant à 2 `Combattant`s de rentrer dans l'`Arene` (une méthode `entrer`).
  * Permettant de dérouler le combat jusqu'à la défaite d'un des `Combattant`s (une méthode `combat`) :
    * Le premier `Combattant` à attaquer est le plus rapide.
    * Le combat s'arrête dès que la `vie` d'un `Combattant` tombe à zéro (ou en dessous).
    * Le combat se termine par l'annonce du vainqueur.

**Tests** :
* Instancier 2 `Combattant`s
* Instancier une `Arene`
* Faire entrer les `Combattant` dans l'`Arene`
* Déclencher les hostilités
