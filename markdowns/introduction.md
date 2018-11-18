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

La libraire toolbox offre une série de fonction permettant de manipuler les images `BMP`:
```c
Image_Nfo LoadImage(const char[200]);
Image_Nfo Create_Image(int, int);
void SaveImage(const char[200], Image_Nfo);
void GetImgTab(Image_Nfo, rgba *);
void SetImgTab(Image_Nfo, rgba *);
void display_Img(Image_Nfo);
```

:::Image_Nfo LoadImage(const char[200])
La fonction `LoadImage` prend en paramètre une chaîne de caractère représentant le nom de l'image et son emplacement si il est différent de celui d'exécution.

La fonction retour une `struct Image_Nfo`. Celle-ci contient différentes informations sur l'image (y compris l'image). Les plus intéressantes sont `w`, la largeur de l'image et `h`, la hauteur de l'image.
:::

:::Image_Nfo Create_Image(int, int)
La fonction `Create_Image` prend en paramètre deux entiers représentant la largeur et la hauteur d'une image.

La fonction retour une `struct Image_Nfo`. Celle-ci permettra de construire une image à partir de rien.
:::

:::void SaveImage(const char[200], Image_Nfo)
La fonction `SaveImage` prend en paramètre une chaîne de caractère représentant le nom de l'image à sauver et une `Image_Nfo` contenant les informations de l'image qui sera sauvée.
:::

:::void GetImgTab(Image_Nfo, rgba *)
La fonction `GetImgTab` prend en paramètre une `Image_Nfo` et l'adresse d'un tableau de `rgba` de la taille de l'image à traiter. Après exécution le tableau de `rgba` contiendra chaque pixel de l'image.
:::

:::void SetImgTab(Image_Nfo, rgba *)
La fonction `SetImgTab` prend en paramètre une `Image_Nfo` et l'adresse d'un tableau de `rgba`. Elle va ré-écrire le tableau dans la `Image_Nfo`.
:::

:::void display_Img(Image_Nfo)
La fonction `display_Img` prend en paramètre une `Image_Nfo` et l'affiche dans une fenêtre.
:::

### Exemple

```c
#include <string.h>
#include "toolsbox.h"

int main(int argc, char *argv[])
{
    Image_Nfo image;
    rgba tableau[256][256];

    image = LoadImage("monfichier.bmp"); //ou image = Create_Image(256,256);

	GetImgTab(image,tableau);
	/**************************
	** Traitement de tableau **
	**************************/
	SetImgTab(image,tab);
	
	SaveImage("fichier.bmp",image);
	display_Img(image);
	waitAndQuit();
	
	return 0;
}
```