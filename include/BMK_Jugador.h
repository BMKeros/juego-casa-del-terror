#ifndef BMK_JUGADOR_H
#define BMK_JUGADOR_H

#include "BMK_Librerias.h"

class BMK_Jugador {
    private:
        char *nombre;
        float puntaje;
        //BMK_Inventario *inventario;
        BMK_Sprites *cuerpo;
        coordenada posicion;
        SDL_Rect contenedor;

        //Atributos para saber cuando cambiar el sprite de direccion
        int sprite_actual;
        bool cambia_sprite;

    public:
        BMK_Jugador(int x, int y);
        ~BMK_Jugador();
        void set_nombre(char *nombre);
        char *get_nombre();
        void set_puntaje(float puntaje);
        float get_puntaje();
        coordenada get_posicion();
        void set_posicion(coordenada posicion);
        //BMK_Inventario *get_inventario();

        //Metodos manejo de sprites
        void cargar_sprite(const char *path);

        //Metodos dibujar
        void dibujar(SDL_Surface *pantalla);
        void cambiar_direccion_sprite(int direccion);

        //Metodos para el movimiento del jugador
        int colision(coordenada posicion,int mapa[MAX_X][MAX_Y]);
        coordenada alterar_coordenada(int direccion);
        bool cambiar_posicion(coordenada destino, int mapa[MAX_X][MAX_Y]);
        bool mover_jugador(int direccion,int mapa[MAX_X][MAX_Y]);

};


BMK_Jugador::BMK_Jugador(int x, int y){
    this->cuerpo = new BMK_Sprites(MAX_SPRITE_JUGADOR);
    this->posicion.x = x;
    this->posicion.y = y;
    this->sprite_actual = 0;
    this->cambia_sprite = false;
}

BMK_Jugador::~BMK_Jugador(){
    delete this->nombre;
//    delete this->inventario;
    this->cuerpo->liberar_recurso();
}

void BMK_Jugador::set_nombre(char *nombre){
    this->nombre = nombre;
}

char *BMK_Jugador::get_nombre(){
    return this->nombre;
}

void BMK_Jugador::set_puntaje(float puntaje){
    this->puntaje = puntaje;
}

float BMK_Jugador::get_puntaje(){
    return this->puntaje;
}

coordenada BMK_Jugador::get_posicion(){
    return this->posicion;
}

void BMK_Jugador::set_posicion(coordenada _posicion){
    this->posicion = _posicion;
}

//BMK_Inventario *BMK_Jugador::get_inventario(){
//    return this->inventario;
//}

//Manejo de los sprite cuerpo
void BMK_Jugador::cargar_sprite(const char *path){
    this->cuerpo->cargar_frame(path);
}

//Dibujar
void BMK_Jugador::dibujar(SDL_Surface *pantalla){

    this->contenedor.y = (this->posicion.x+1)*MAX_PIXEL;
    this->contenedor.x = (this->posicion.y+1)*MAX_PIXEL;
    this->contenedor.w = this->cuerpo->get_ancho();
    this->contenedor.h = this->cuerpo->get_alto();

    SDL_SetColorKey(this->cuerpo->get_sprite_actual(),SDL_SRCCOLORKEY,SDL_MapRGB(this->cuerpo->get_sprite_actual()->format,COLOR_FONDO_JUGADOR));

    SDL_BlitSurface(this->cuerpo->get_sprite_actual(),NULL,pantalla,&this->contenedor);

}

//Cambiamos la direccion del sprite
void BMK_Jugador::cambiar_direccion_sprite(int direccion){
//Lo comenta la probrar con los metodos nativos de la clase BMK_Sprite
    /*switch(direccion){
        case ARRIBA:
            if(this->cambia_sprite && this->sprite_actual == 5){
                this->sprite_actual = 4;
            }
            else{
                this->cambia_sprite = true;
                this->sprite_actual = 5;
            }
        break;

        case ABAJO:
            if(this->cambia_sprite && this->sprite_actual == 5){
                this->sprite_actual = 4;
            }
            else{
                this->cambia_sprite = true;
                this->sprite_actual = 5;
            }
        break;

        case IZQUIERDA:
            if(this->cambia_sprite && this->sprite_actual == 3){
                this->sprite_actual = 2;
            }
            else{
                this->cambia_sprite = true;
                this->sprite_actual = 3;
            }
        break;

        case DERECHA:
            if(this->cambia_sprite && this->sprite_actual == 1){
                this->sprite_actual = 0;
            }
            else{
                this->cambia_sprite = true;
                this->sprite_actual = 1;
            }
        break;
    }*/

switch(direccion){
        case ARRIBA:
            if(this->cambia_sprite && this->cuerpo->get_posicion_frame_actual() == 5){
                this->cuerpo->set_frame_actual(4);
            }
            else{
                this->cambia_sprite = true;
                this->cuerpo->set_frame_actual(5);
            }
        break;

        case ABAJO:
            if(this->cambia_sprite && this->cuerpo->get_posicion_frame_actual() == 5){
                this->cuerpo->set_frame_actual(4);
            }
            else{
                this->cambia_sprite = true;
                this->cuerpo->set_frame_actual(5);
            }
        break;

        case IZQUIERDA:
            if(this->cambia_sprite && this->cuerpo->get_posicion_frame_actual() == 3){
                this->cuerpo->set_frame_actual(2);
            }
            else{
                this->cambia_sprite = true;
                this->cuerpo->set_frame_actual(3);
            }
        break;

        case DERECHA:
            if(this->cambia_sprite && this->cuerpo->get_posicion_frame_actual() == 1){
                this->cuerpo->set_frame_actual(0);
            }
            else{
                this->cambia_sprite = true;
                this->cuerpo->set_frame_actual(1);
            }
        break;
    }

}

//Movimientos
coordenada BMK_Jugador::alterar_coordenada(int direccion){
    coordenada temporal = this->posicion;

    switch(direccion){
        case ARRIBA:
            temporal.x--;
        break;

        case ABAJO:
            temporal.x++ ;
        break;

        case IZQUIERDA:
            temporal.y--;
        break;

        case DERECHA:
            temporal.y++;
        break;
    }
    return temporal;
}

//Cambia de posicion y dibuja el personaje
bool BMK_Jugador::cambiar_posicion(coordenada destino, int mapa[MAX_X][MAX_Y]){
    if(mapa[destino.x][destino.x] == 0){
        this->set_posicion(destino);
        return true;
    }
    return false;
}

bool BMK_Jugador::mover_jugador(int direccion,int mapa[MAX_X][MAX_Y]){
    bool retorno = false;
    switch(direccion){
        case ARRIBA:
            this->cambiar_direccion_sprite(ARRIBA);
            retorno = this->cambiar_posicion(this->alterar_coordenada(ARRIBA),mapa);
        break;
        case ABAJO:
            this->cambiar_direccion_sprite(ABAJO);
            retorno = this->cambiar_posicion(this->alterar_coordenada(ABAJO),mapa);
        break;
        case IZQUIERDA:
            this->cambiar_direccion_sprite(IZQUIERDA);
            retorno = this->cambiar_posicion(this->alterar_coordenada(IZQUIERDA),mapa);
        break;
        case DERECHA:
            this->cambiar_direccion_sprite(DERECHA);
            retorno = this->cambiar_posicion(this->alterar_coordenada(DERECHA),mapa);
        break;
    }
    return retorno;
}
#endif
