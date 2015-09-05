#ifndef BMK_JUEGO_H
#define BMK_JUEGO_H

#include "BMK_Constantes.h"
#include "BMK_Mapa.h"
#include "BMK_Sprites.h"
#include "BMK_Jugador.h"


class BMK_Juego: public BMK_ModuloSDL {
    private:
        SDL_Surface *pantalla_principal;

        BMK_Mapa *mapa;
        BMK_Sprites *materiales;
        BMK_Imagen pared,piso;
        BMK_Objeto *objetos;
        BMK_Jugador *jugador;

    public:
        BMK_Juego();
        ~BMK_Juego();


        void cargar_imagenes();
        void cargar_sonidos();
        void cargar_musicas();

        void cargar_pantalla();
        void cargar_mapas();
        void cargar_sprites();

        void eventos();
        void iniciar_juego();

};

BMK_Juego::BMK_Juego(){

    this->materiales = new BMK_Sprites[2];
    this->mapa = new BMK_Mapa;
    this->objetos = new BMK_Objeto[2];
    this->jugador = new BMK_Jugador(8,9);

    this->iniciar_sistema(SDL_INIT_VIDEO|SDL_INIT_TIMER|SDL_INIT_AUDIO);
    this->set_titulo_ventana("La Casa Del Terror  Ver.0.1 (BMKeros)",NULL);

}

BMK_Juego::~BMK_Juego(){
    this->pared.borrar();
    this->piso.borrar();
    this->objetos[0].get_imagen_objeto()->borrar();
    this->objetos[1].get_imagen_objeto()->borrar();
    this->detener_sistema();
    delete this->jugador;
}

void BMK_Juego::cargar_imagenes(){

    this->pared.cargar(PATH_PARED);
    this->piso.cargar(PATH_PISO);
    this->objetos[0].set_imagen_objeto(PATH_PISO);
    this->objetos[1].set_imagen_objeto(PATH_PARED_IN);

    this->materiales->agregar_frame(piso);
    this->materiales->agregar_frame(pared);

    ///Cargamos las imagenes del jugador
    jugador->cargar_sprite(PATH_IMG_SPRITE_0);
    jugador->cargar_sprite(PATH_IMG_SPRITE_1);
    jugador->cargar_sprite(PATH_IMG_SPRITE_2);
    jugador->cargar_sprite(PATH_IMG_SPRITE_3);
    jugador->cargar_sprite(PATH_IMG_SPRITE_4);
    jugador->cargar_sprite(PATH_IMG_SPRITE_6);
    //jugador->cargar_sprite(PATH_IMG_SPRITE_7);
    //jugador->cargar_sprite(PATH_IMG_SPRITE_8);

}

void BMK_Juego::cargar_pantalla(){
    this->pantalla_principal = this->iniciar_modo_grafico(ANCHO,ALTO,COLORES,SDL_HWSURFACE);
}

void BMK_Juego::cargar_mapas(){
    this->mapa->crear_mapa();
    this->mapa->crear_mapa_inventario();
}

void BMK_Juego::cargar_sprites(){
    this->mapa->dibujar_mapa(this->materiales,this->pantalla_principal);
    this->mapa->dibujar_mapa_inventario(this->objetos,this->pantalla_principal);
    this->jugador->dibujar(this->pantalla_principal);
}

void BMK_Juego::iniciar_juego(){
    SDL_Flip(this->pantalla_principal);
}




#endif
