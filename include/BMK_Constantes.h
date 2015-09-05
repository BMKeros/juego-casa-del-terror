#ifndef BMK_CONSTANTES_H
#define BMK_CONSTANTES_H

//Rectangulo de juego
#define MAX_X 14
#define MAX_Y 19

//Rectangulo del inventario
#define MAX_IN_X 14
#define MAX_IN_Y 6
//Rectangulo de inventario

//Pixeles de la imagen
#define MAX_PIXEL 32


//Definimos las caracteristicas de la ventana
#define ANCHO 900
#define ALTO 600
#define COLORES 32


//Direcciones de imagenes
#define PATH_PISO "/home/hostelix/Escritorio/sprites/piso.bmp"
#define PATH_PARED "/home/hostelix/Escritorio/sprites/paredV.bmp"

#define PATH_OBJ_IN_1 "/home/hostelix/Escritorio/sprites/piso.bmp"
#define PATH_PARED_IN "/home/hostelix/Escritorio/sprites/materiales/pared_metal1.bmp"


//Imagenes sprites jugador
#define PATH_IMG_SPRITE_0 "/home/hostelix/Escritorio/sprites/jugador/jugador_inicial.bmp"
#define PATH_IMG_SPRITE_1 "/home/hostelix/Escritorio/sprites/jugador/jugador_derecha_1.bmp"
#define PATH_IMG_SPRITE_2 "/home/hostelix/Escritorio/sprites/jugador/jugador_derecha_2.bmp"
#define PATH_IMG_SPRITE_3 "/home/hostelix/Escritorio/sprites/jugador/jugador_izquierda_1.bmp"
#define PATH_IMG_SPRITE_4 "/home/hostelix/Escritorio/sprites/jugador/jugador_izquierda_2.bmp"
#define PATH_IMG_SPRITE_5 "/home/hostelix/Escritorio/sprites/jugador/jugador_abajo_1.bmp"
#define PATH_IMG_SPRITE_6 "/home/hostelix/Escritorio/sprites/jugador/jugador_abajo_2.bmp"
#define PATH_IMG_SPRITE_7 "/home/hostelix/Escritorio/sprites/jugador/jugador_arriba_1.bmp"
#define PATH_IMG_SPRITE_8 "/home/hostelix/Escritorio/sprites/jugador/jugador_arriba_2.bmp"





//Direcciones
#define ARRIBA 8
#define ABAJO 2
#define DERECHA 4
#define IZQUIERDA 6


//Numero maximo de sprites del jugador
#define MAX_SPRITE_JUGADOR 9


//Color de fondo del sprites jugador
#define COLOR_FONDO_JUGADOR 255,0,255

//Estructura de coodenadas
typedef struct coord{
    int x, y;
}coordenada;


#endif // BMK_CONSTANTES_H
