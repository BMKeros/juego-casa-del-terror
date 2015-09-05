#include "BMK_Librerias.h"

int main ( int argc, char** argv )
{
/**
    SDL_Surface * hola;
    BMK_ModuloSDL *modulo = new BMK_ModuloSDL;
    BMK_Sprites *material = new BMK_Sprites[1];
    BMK_Imagen l1,l2;
    l1.cargar("/home/hostelix/Escritorio/sprites/piso.bmp");
    l2.cargar("/home/hostelix/Escritorio/sprites/paredV.bmp");

    material->agregar_frame(l1);
    material->agregar_frame(l2);


    modulo->iniciar_sistema(SDL_INIT_VIDEO);
    modulo->set_titulo_ventana("HOLA MUNDO", NULL);
    hola = modulo->iniciar_modo_grafico(900,600,32,SDL_HWSURFACE);

    BMK_Mapa *mapa = new BMK_Mapa();
    mapa->iniciar_mapa();
    mapa->crear_mapa();
    mapa->dibujar_mapa(material,hola);
    SDL_Flip(hola);
    SDL_Delay(SDL_GetTicks()*10);
    l1.borrar();
    l2.borrar();**/

    BMK_Juego *casa_del_terror = new BMK_Juego;

    atexit(SDL_Quit);

    casa_del_terror->cargar_imagenes();
    casa_del_terror->cargar_pantalla();
    casa_del_terror->cargar_mapas();
    casa_del_terror->cargar_sprites();
    casa_del_terror->iniciar_juego();
    SDL_Delay(SDL_GetTicks()*10);
}
