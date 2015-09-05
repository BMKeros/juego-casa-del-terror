#ifndef BMK_MODULOSDL_H
#define BMK_MODULOSDL_H

#include "BMK_Mensajes.h"

class BMK_ModuloSDL
{

    private:

    public:
        BMK_ModuloSDL();
        virtual ~BMK_ModuloSDL();
        bool iniciar_sistema(Uint32 sistema);
        bool iniciar_subSistema(Uint32 subsistema);
        SDL_Surface *iniciar_modo_grafico(int ancho, int alto, int num_colores,Uint32 modo);
        void set_titulo_ventana(const char *titulo, char *icono);
        void set_icono_ventana(SDL_Surface *icono, Uint8 *mascara);
        void detener_sistema();
        void detener_subSistema(Uint32 subsistema);
};


BMK_ModuloSDL::BMK_ModuloSDL()
{
    //ctor
}

BMK_ModuloSDL::~BMK_ModuloSDL()
{
    //dtor
}

bool BMK_ModuloSDL::iniciar_sistema(Uint32 sistema){
    if(SDL_Init(sistema) < 0){
        printf(ERROR_INICIAR_SISTEMA,SDL_GetError());
        exit(1);
        return false;
    }
    return true;
}

bool BMK_ModuloSDL::iniciar_subSistema(Uint32 subsistema){
    if(SDL_InitSubSystem(subsistema) < 0){
        printf(ERROR_INICIAR_SUBSISTEMA,SDL_GetError());
        exit(1);
        return false;
    }
    return true;
}

SDL_Surface *BMK_ModuloSDL::iniciar_modo_grafico(int ancho, int alto, int num_colores,Uint32 modo){
    SDL_Surface *tmp;
    tmp = SDL_SetVideoMode(ancho,alto,num_colores,modo);

    if(tmp){
        return tmp;
    }
    exit(1);
    return NULL;
}

void BMK_ModuloSDL::set_titulo_ventana(const char *titulo, char *icono){
    SDL_WM_SetCaption(titulo, icono);
}


void BMK_ModuloSDL::set_icono_ventana(SDL_Surface *icono, Uint8 *mascara){
    SDL_WM_SetIcon(icono, mascara);
}

void BMK_ModuloSDL::detener_sistema(){
    SDL_Quit();
}

void BMK_ModuloSDL::detener_subSistema(Uint32 subsistema){
    SDL_QuitSubSystem(subsistema);
}


#endif // BMK_MODULOSDL_H
