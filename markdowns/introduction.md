# Introduction

L’objectif de cette séance est de manipuler des tableaux. Pour ce faire, vous allez travailler sur des images. En effet, une image est un  à deux dimensions représentant dans chaque élément une couleur.

Pour pouvoir manipuler les images, nous allons à nouveau utiliser la librairie toolbox.

## Les images

Comme mentionner précédent une image est un tableau dans lequel chaque élément représente une couleur.
Il s’agit en fait d’un tableau de structure  `struct RGBA`.

Définition de la structure : 
```c
struct RGBA {
    unsigned char red;    // Composante rouge
    unsigned char green;  // Composante verte
    unsigned char blue;   // Composante bleue
    unsigned char alpha;  // La transparence, nous ne nous en occuperont pas
};
```
Grâce à un `typedef` nous pourrons déclarer une variable de type `struct RGBA` en introduisant :
```c
rgba ma_variable;
```

Comme vous pouvez le voir chaque composant de couleur est codée sur un `unsigned char`, il s'agit donc d'une valeur comprise entre 0 et 255 :
- `0` étant l'absence de cette composante de couleur;
- `255` étant l'intensité maximale de cette composante de couleur.

## Toolbox

La libraire toolbox offre une série de fonction permettant de manipuler les images :
```c
Image_Nfo LoadImage(const char[200]);
Image_Nfo Create_Image(int, int);
void SaveImage(const char[200], Image_Nfo);
void SetImgTab(Image_Nfo, rgba *);
void GetImgTab(Image_Nfo, rgba *);
void display_Img(Image_Nfo);
```

1. Introduire la notion d'image en comment elles sont représentées sur un ordinateur
1. Introduire les fonctions disponnibles dans toolbox