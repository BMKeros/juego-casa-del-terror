#ifndef BMK_MAPA_H
#define BMK_MAPA_H

#include "BMK_Constantes.h"
#include "BMK_Sprites.h"
#include "BMK_Objeto.h"

class BMK_Mapa {
    private:
        int mapa[MAX_X][MAX_Y];
        int mapa_inventario[MAX_IN_X][MAX_IN_Y];

    public:
        BMK_Mapa();
        ~BMK_Mapa();
        void iniciar_mapa();
        void crear_mapa();
        void crear_mapa_inventario();
        void dibujar_mapa(BMK_Sprites *materiales,SDL_Surface *pantalla);
        void dibujar_mapa_inventario(BMK_Objeto *objetos,SDL_Surface *pantalla);
        void set_objeto_mapa(int x , int y, int objeto);
        int get_objeto_mapa(int x, int y);
        void set_pantalla(SDL_Surface *pantalla);

};


BMK_Mapa::BMK_Mapa(){
    this->iniciar_mapa();
}

BMK_Mapa::~BMK_Mapa(){

}

void BMK_Mapa::iniciar_mapa(){
    for(int i=0; i<MAX_X; i++){
        for(int j=0; j<MAX_Y; j++){
            this->mapa[i][j] = 0;
        }
    }

    for(int i=0; i<MAX_IN_X; i++){
        for(int j=0; j<MAX_IN_Y; j++){
            this->mapa_inventario[i][j] = 0;
        }
    }
}

void BMK_Mapa::crear_mapa(){

    for(int i=0 ; i<MAX_X ; i++) {
        for (int j=0 ; j<MAX_Y ; j++) {
            //Creamos paredes
            if(i<MAX_Y && j==0) this->mapa[i][j] = 1;
            else if(i==MAX_X-1 && j<MAX_Y) this->mapa[i][j] =1;
            else if(i==0 && j<MAX_Y) this->mapa[i][j] =1;
            else if(i<MAX_Y && j==MAX_Y-1) this->mapa[i][j] =1;
        }
    }

}

void BMK_Mapa::crear_mapa_inventario(){

    for(int i=0 ; i<MAX_IN_X ; i++) {
        for (int j=0 ; j<MAX_IN_Y ; j++) {
            //Creamos paredes
            if(i<MAX_IN_X && j==0) this->mapa_inventario[i][j] = 1;
            else if(i==MAX_IN_X-1 && j<MAX_Y) this->mapa_inventario[i][j] =1;
            else if(i==0 && j<MAX_IN_Y) this->mapa_inventario[i][j] =1;
            else if(i<MAX_IN_X && j==MAX_IN_Y-1) this->mapa_inventario[i][j] =1;
        }
    }

}

void BMK_Mapa::dibujar_mapa(BMK_Sprites *materiales,SDL_Surface *pantalla){
    SDL_Rect r;
    for(int i=0 ; i<MAX_X ; i++){
        for(int j=0 ; j<MAX_Y ; j++){

            materiales->set_frame_actual(this->mapa[i][j]);

            r.x=(j+1)*MAX_PIXEL;
            r.y=(i+1)*MAX_PIXEL;
            r.h = materiales->get_alto();
            r.w = materiales->get_ancho();
            SDL_BlitSurface(materiales->get_sprite_actual(), NULL, pantalla, &r);
        }
    }
}

void BMK_Mapa::dibujar_mapa_inventario(BMK_Objeto *objetos,SDL_Surface *pantalla){
    SDL_Rect r;
    int tmp;
    for(int i=0 ; i<MAX_IN_X ; i++){
        for(int j=0 ; j<MAX_IN_Y ; j++){

            tmp= this->mapa_inventario[i][j];

            r.x=(j+21)*MAX_PIXEL;
            r.y=(i+1)*MAX_PIXEL;
            r.h = objetos[tmp].get_altura();
            r.w = objetos[tmp].get_ancho();
            SDL_BlitSurface(objetos[tmp].get_imagen_objeto()->get_imagen(), NULL, pantalla, &r);
        }
    }
}

void BMK_Mapa::set_objeto_mapa(int x, int y, int objeto){
    this->mapa[x][y] = objeto;
}

int BMK_Mapa::get_objeto_mapa(int x, int y){
    return this->mapa[x][y];
}
#endif // BMK_MAPA_H
