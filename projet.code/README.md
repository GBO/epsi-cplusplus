# projet.code : Exemple de projet simple pour Visual Studio Code

La tâche de compilation par défaut est définie dans le `code/tasks.json` dans la tâche `C/C++: g++-10 générer le fichier actif`.

Il est possible de configurer cette tâche, notamment :
* `command` : la commande utilisée pour compiler (ici un `g++-10`)
* `args` : les arguments passés au compilateur, et ainsi le fait qu'il compile le fichier courant pour en produire un exécutable (avec le nom de fichier sans extension).