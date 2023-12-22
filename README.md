<div align="center">
  <img height="450" src="https://raw.githubusercontent.com/Kurama77190/GET_NEXT_LINE/main/images/GNL%20LOGO.png"  />
</div>

![Language](https://img.shields.io/badge/language-C-blue)
![Progress](https://img.shields.io/badge/progress-completed-green)

# GET_NEXT_LINE CHAINÉE | BEN TAYEB SAMY

## Table des Matières
- [Description](#description)
- [Objectifs](#objectifs)
- [Avantages des Listes Chaînées Static pour GNL](#avantages-des-listes-chaînées-static-pour-gnl)
- [Défis Techniques](#défis-techniques)
- [Importance du Projet](#importance-du-projet)
- [Utilisation](#utilisation)
- [Compilation](#compilation)
- [Exemple de Sortie](#exemple-de-sortie)

## Description
Le projet Get Next Line (GNL) de l'école 42 consiste à développer une fonction en C pour lire une ligne terminée par un retour à la ligne ('\n') depuis un fichier ou un descripteur de fichier. Le défi réside dans la capacité à traiter n'importe quel fichier, indépendamment de sa taille ou de son contenu, et à retourner une ligne à la fois jusqu'à la fin du fichier.

## Objectifs
- Développer une compréhension approfondie de la lecture de fichiers en C.
- Gérer efficacement la mémoire et les chaînes de caractères.
- Affronter des problèmes de programmation réels et pratiques.

## Avantages des Listes Chaînées Static pour GNL
L'implémentation de GNL avec des listes chaînées offre plusieurs avantages :
### 1. Gestion Dynamique de la Mémoire
Les listes chaînées permettent une allocation de mémoire dynamique, adaptant la taille de mémoire aux besoins réels, idéale pour les lignes de longueurs variables.
### 2. Flexibilité
Elles offrent une manipulation flexible des données, facilitant l'ajout ou la suppression d'éléments, ce qui est avantageux pour des fichiers variés.
### 3. Efficacité pour les Grandes Lignes
Les listes chaînées sont souvent plus efficaces que les buffers statiques pour les fichiers avec de longues lignes, en évitant de relire plusieurs fois le même segment.
### 4. Facilité de Manipulation des Données
Elles simplifient la manipulation des lignes lues, comme l'assemblage de segments ou la gestion des fins de ligne.
### 5. Réduction de la Redondance de Données
Contrairement aux buffers statiques, elles minimisent le stockage de données redondantes.

## Défis Techniques
- **Bufferisation** : Gérer la lecture de fichiers avec une taille de buffer définie.
- **Efficacité** : Optimiser la fonction pour gérer de grandes quantités de données efficacement.
- **Robustesse** : Assurer une gestion correcte des cas variés comme les fichiers vides ou les erreurs de lecture.

## Importance du Projet
GNL est un jalon crucial dans l'apprentissage des étudiants de 42, les confrontant à des défis de programmation réels. Il sert de fondation solide pour des projets plus avancés en programmation C, particulièrement dans la manipulation des chaînes de caractères et la gestion des fichiers.

## Utilisation
Pour utiliser GNL, incluez la fonction `get_next_line` dans votre projet C. Voici un exemple de fichier `main.c` :

```c
#include "get_next_line.h"

int main(void)
{
    int fd;
    char *line;

    fd = open("../src/simple.txt", O_RDONLY);
    while (1)
    {
        line = get_next_line(fd);
        if (line == NULL)
            break;
        printf("%s", line);
        free(line);
    }
    close(fd);
    return 0;
}
```
## Compilation
Pour compiler le programme, utilisez la ligne de commande suivante, en remplaçant <files>.c par vos fichiers source :
``` compilation
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 <files>.c
```

## Exemple de Sortie
En utilisant le fichier simple.txt contenant le texte "Hello World$ GoodBye!", voici un exemple de sortie de GNL :

``` output
Hello World$
GoodBye!
```
