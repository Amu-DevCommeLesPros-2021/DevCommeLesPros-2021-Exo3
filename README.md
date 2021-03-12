![](https://github.com/Amu-DevCommeLesPros-2021/DevCommeLesPros-2021-Exo3/workflows/Run%20tests/badge.svg)

# DevCommeLesPros-2021-Exo3

Modèle de départ pour exercices d'introduction au travail par équipe avec GitHub et de l'utilisation de l'intégration continue.

<!-- TOC depthfrom:2 -->

- [Préparation](#pr%C3%A9paration)
    - [Pour créer le dépôt un membre du binôme](#pour-cr%C3%A9er-le-d%C3%A9p%C3%B4t-un-membre-du-bin%C3%B4me)
    - [Pour cloner le dépôt deux membres du binôme](#pour-cloner-le-d%C3%A9p%C3%B4t-deux-membres-du-bin%C3%B4me)
- [Objectif](#objectif)
- [Instructions de travail](#instructions-de-travail)
    - [Ce qui est permis](#ce-qui-est-permis)
    - [Ce qui ne l'est pas](#ce-qui-ne-lest-pas)
    - [En tout temps](#en-tout-temps)
- [Évaluation](#%C3%A9valuation)
- [Questions-Réponses](#questions-r%C3%A9ponses)
    - [«J'ai un problème !»](#%C2%ABjai-un-probl%C3%A8me-%C2%BB)
    - [«Le fichier main.c échoue la compilation avec une erreur d'arithmétique de pointeur.»](#%C2%ABle-fichier-mainc-%C3%A9choue-la-compilation-avec-une-erreur-darithm%C3%A9tique-de-pointeur%C2%BB)
    - [«J'ai des problèmes avec la manipulation de mémoire dynamique.»](#%C2%ABjai-des-probl%C3%A8mes-avec-la-manipulation-de-m%C3%A9moire-dynamique%C2%BB)

<!-- /TOC -->

## Préparation

Ces intructions présupposent que vous avez déjà suivi les instructions du [zérotième exercice](https://github.com/Amu-DevCommeLesPros-2021/DevCommeLesPros-2021-Exo0) pour la création d'un compte GitHub et l'installation des programmes et extensions nécéssaires.

Pour cet exercice, vous devez travailler en binôme sur un même dépôt.
Choisissez qui du binôme créera le dépôt.
Par la suite, ce même dépôt sera cloné par les deux membres du binôme.

### Pour créer le dépôt (un membre du binôme)
1. Créez votre dépôt sur github.com en utilisant [ce dépôt-ci](https://github.com/Amu-DevCommeLesPros-2021/DevCommeLesPros-2021-Exo3) comme modèle.
    - Suivez [ces instructions](https://docs.github.com/en/free-pro-team@latest/github/creating-cloning-and-archiving-repositories/creating-a-repository-from-a-template).
    - Choisissez l'option `Private` à l'étape 5.
1. Ajoutez le professeur comme collaborateur à votre dépôt.
    - Suivez [ces instructions](https://docs.github.com/en/free-pro-team@latest/github/setting-up-and-managing-your-github-user-account/inviting-collaborators-to-a-personal-repository).
    - Nom d'utilisateur à ajouter : `thierryseegers`.
1. Ajoutez votre co-équipier·ère comme collaborateur à votre dépôt.
    - Suivez les instructions de l'étape précédente.
    - Votre co-équipier·ère recevra un mail avec un lien pour accepter votre invitation.

### Pour cloner le dépôt (deux membres du binôme)
1. Clonez le dépôt vers votre espace de travail local.
    - Suivez [ces instructions](https://docs.github.com/en/free-pro-team@latest/github/creating-cloning-and-archiving-repositories/cloning-a-repository).
    - Attention à ne pas cloner https://github.com/Amu-DevCommeLesPros-2021/DevCommeLesPros-2021-Exo3 mais bien votre dépôt nouvellement créé.
1. Lancez Visual Studio Code.
    - À l'invite de commandes:
        - `$ cd [nom de votre dépôt]`
        - `$ code .`

## Objectif

En C++, la structure de données `vector<>` est une structure qui s'apparent au tableau en C.
Une différence qui en fait sa force est que le vecteur peut modifier sa propre taille au besoin.
C'est un tableau dynamique.
En C, un tableau déclaré comme `int nombres[10]` ne peut contenir que 10 `int`.
Impossible d'en ajouter un onzième.
Ce n'est pas le cas avec un vecteur.
Par exemple, avec la fonction membre `push_back` on peut continuer d'ajouter autant de `int` qu'il est possible.
La mémoire sous-jacente du vecteur *s'ajustera d'elle-même*.
Cet exercice vous propose d'implémenter vous-même une imitation de `vector<>` en C.

Pour commencer, le programme de test de cet exercice a tous ses tests commentés.
Il vous faudra les décommenter à mesure qui vous implémenterez les fonctionalités de la bibliothèque `libvector`.

Vous devrez :
1. Modifier l'URL en tête de ce document `README.md` pour refléter l'URL de votre dépôt.
    - L'URL doit ressembler à `https://github.com/[nom-de-votre-compte]/[nom-de-votre-depot]/workflows/Run%20tests/badge.svg`.
    - Cet URL présente un «badge» qui réflete l'état de santé de votre dépôt.
1. Compléter le fichier `makefile` :
    - Compléter les cibles déjà définies.
        - La cible `check` doit dépendre de la cible `build/test` et doit lancer le programme de test.
        - **Il est impératifs que les cibles `build/libvector.a`, `build/test` et `check` soient définies pour la bonne exécution de cet exercice.**
    - Ajouter d'autres cibles à votre guise.
1. Implémenter correctement toutes les fonctions de la bibliothèque logicielle `libvector` pour que le programme `build/test` affiche que tous les tests décommentés passent avec succès et retourne `0` à l'invite de commande.

## Instructions de travail

Chacun des membres du binôme devra suivre ces instructions au moins une fois.

1. Créez une nouvelle branche qui servira de branche de travail pour réparer une première suite de tests.
    - `$ git branch [nom de la branche]`
    - `$ git checkout [nom de la branche]`
    - Exemple : `$ git branch implementation-make_vector-size-capacity`, `$ git checkout implementation-make_vector-size-capacity`.
1. Au fur et à mesure de vos modifications au code, intégrez-les au dépôt local avec une description des modifications apportées.
    - `$ git add [fichiers]`
    - `$ git commit -m "Description des modifications apportées"`
    - Exemple : `$ git add lib/vecteur.c`, `$ git commit -m "Passe les tests pour make_vector, size et capacity."`
1. Périodiquement, publiez votre branche de votre dépôt local à votre dépôt sur github.com.
    - `$ git push origin [nom de la branche]`
    - Exemple : `$ git push origin implementation-make_vector-size-capacity`.
1. Lorsqu'une suite de tests est réparée, ouvrez un «Pull Request» sur GitHub pour fusionner la branche de travail à la branche `master`.
    - Suivez [ces instructions](https://docs.github.com/en/free-pro-team@latest/desktop/contributing-and-collaborating-using-github-desktop/creating-an-issue-or-pull-request).
    - Décrivez les bénéfices apportés par ce Pull Request en suivant les suggestions du modèle («Modification(s) apportée(s)», «Problème(s) résolu(s)», «Vérification(s) et test(s)»).
1. Attendez que le service d'Intégration Continue lance un compilation de votre base de code et le test.
    - Vous devriez voir une «fenêtre» apparaître comme celle-ci :
    ![Intégration Conitnue enclenchée](https://user-images.githubusercontent.com/1580647/75868664-a806f900-5e08-11ea-8fd5-cc1df9f6ca42.png)
1. Assurez-vous que le résultat de la compilation et du test automatique par le service d'Intégration Continu soit positif !
    - La fenêtre précédente devrait devenir comme celle-ci :
    ![Intégration Conitnue réussie](https://user-images.githubusercontent.com/1580647/75868675-b05f3400-5e08-11ea-93b1-87756c4dc80f.png)
1. Si le résultat échoue, vous devez réparer le problème sur votre branche dans votre dépôt local et apporter les modifications nécéssaires.
    - Si la fenêtre vous montre ceci, **vous ne devez pas fusionner votre branche** :
    ![Intégration Conitnue échoue](https://user-images.githubusercontent.com/1580647/75869715-421b7100-5e0a-11ea-81b1-50854cc01c7b.png)
1. Demandez à votre co-équipier(ère) de passer en revue vos modifications, de suggérer des améliorations si besoin est et, ultimement, d'approuver.
    - Suivez [ces instructions](https://docs.github.com/en/free-pro-team@latest/github/collaborating-with-issues-and-pull-requests/requesting-a-pull-request-review) pour demander une révision.
    - Suivez [ces instructions](https://docs.github.com/en/free-pro-team@latest/github/collaborating-with-issues-and-pull-requests/commenting-on-a-pull-request) quand on vous demande de faire une révision.
1. **Quand la compilation et les test automatiques auront réussi et que votre co-équipier·ère aura approuvé votre Pull Request**, fusionnez la branche de travail sur GitHub.
    - Suivez [ces instructions](https://docs.github.com/en/free-pro-team@latest/github/collaborating-with-issues-and-pull-requests/merging-a-pull-request#merging-a-pull-request-on-github).
    - Choisissez `Create a merge commit` à l'étape 3.
1. Revenez sur la branche `master` de votre dépôt local et synchronisez-la avec la branche `master` de votre dépôt sur GitHub.
    - `$ git checkout master`
    - `$ git pull origin master`
1. Répétez ces étapes jusqu'à ce que tous les tests soient activés (décommentés).

Avec la commande `$ git log --all --decorate --graph --pretty=format:"%ar (%an) %s"`, l'historique de votre travail devrait au fil du temps ressembler à ceci (lire du bas vers le haut) :

```
*   1 hour ago (origin/master, origin/HEAD, master) Merge pull request #4 from MickeyMouse/implementation-iterateurs
|\
| * 3 hours ago (DonalDuck) Passe tous les tests d'itérateurs.
| * 4 hours ago (DonalDuck) Passe les tests d'itérateurs que le vecteur est de taille 0.
|/
*   1 day ago Merge pull request #3 from MickeyMouse/implementation-make_vector-size-capacity
|\
| * 1 day ago (Donald Duck) Ne plante plus dans la fonction destroy.
| * 1 day ago (Donald Duck) Passe les premiers test de size et capacity.
| * 1 day ago (Donald Duck) Passe les premiers test de creation d'un vecteur.
|/
*   2 days ago (Mickey Mouse) Merge pull request #2 from MickeyMouse/implementation-makefile
|\
| * 2 days ago (Mickey Mouse) Peut invoquer check pour lancer le programme de test.
| * 2 days ago (Mickey Mouse) Peut compiler, lancer et déboguer le programme test.
| * 2 days ago (Mickey Mouse) Peut compiler la bibliothèque libvecteur.a.
|/
*   3 days ago (Donald Duck) Merge pull request #1 from MickeyMouse/correction-URL
|\
| * 3 days ago (Donald Duck) Corrigé URL du badge en tête du README comme demandé.
|/
* 3 days ago Initial commit
```

Remarquez que les deux collaborateurs contribuent au même dépôt.

### Ce qui est permis

- De modifier le fichier `README.md` pour modifier l'URL du badge en en-tête.
- De modifier le fichier `makefile` pour compiler et lier les cibles prédéfinies et ajouter d'autres cibles si nécessaire.
- De modifier le fichier `lib/vector_types.h` pour ajouter au contenu des structures `vector` et `iterator` si nécessaire.
- De modifier le fichier `lib/vector_api.c` afin d'implémenter les fonctions qu'il contient.
- De modifier le fichier `test/main.c` pour activer (décommenter) le plus de tests possible.

### Ce qui ne l'est pas
- De modifier les fichiers d'en-tête `lib/vector.h` et `lib/vector_api.h`.
- D'utiliser `goto` et d'avoir des «boucles infinies» du style `while(1)`. Pourquoi ? La réponse est [ici](https://github.com/Amu-DevCommeLesPros-2021/DevCommeLesPros-2021-Exo1#pourquoi-pas-de-goto-ou-de-boucles-infinies-).

### En tout temps
- Votre code doit réussir 100% des tests activés (décommentés), même si ce n'est pas l'entièreté des tests, avant d'être intégré dans la branche `master`.
- Le badge apparaissant tout en haut de ce document doit afficher `passing`.

## Évaluation

L'évaluation portera sur :

1. Le suivi des instructions de travail.
    - Je dois voir des contributions à la base de code par tous les membres de votre groupe.
1. Le nombre de tests réussis.
    - Vos fichiers `lib/vector_types.h` et `lib/vector_api.c` seront compilés et liés avec le fichier `lib/vector_api.h` intact et avec le fichier `test/main.c` ayant tous ses tests activés (décommentés).
1. La qualité des modifications apportées.

Attention !
*Seul le code de la branche `master` de votre dépôt commun sur [GitHub](https://github.com) compte !*

## Questions-Réponses

### «J'ai un problème !»

Voyez les indications données dans le [premier exercice](https://github.com/Amu-DevCommeLesPros-2021/DevCommeLesPros-2021-Exo1#jai-un-probl%C3%A8me-) à ce sujet.

### «Le fichier `main.c` échoue la compilation avec une erreur d'arithmétique de pointeur.»

Si vous avez une erreur qui ressemble à ceci pour la ligne 67 du fichier `main.c` :

```
error: arithmetic on a pointer to void is a GNU extension [-Werror,-Wpointer-arith]
TEST(b1.element + size(v1) * sizeof(int) == e1.element);
     ~~~~~~~~~~ ^
```

Ajoutez l'option `-Wno-pointer-arith` à la ligne de commande de `gcc` pour passer outre :

```
gcc [autre options] -Wno-pointer-arith [etc.]
```
### «J'ai des problèmes avec la manipulation de mémoire dynamique.»

Un excellent outil disponible pour Linux est [`valgrind`](https://valgrind.org/).
En autres choses, `valgrind` peut faire une analyse de possibles erreurs de mémoires de notre programme.
Ce n'est pas une analsye du code mais une analyse ex post facto une fois que notre programme a terminé son exécution.
Un bon petit tuto se trouve [ici](https://stackoverflow.com/questions/5134891/how-do-i-use-valgrind-to-find-memory-leaks).
