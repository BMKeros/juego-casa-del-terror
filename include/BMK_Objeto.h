#ifndef BMK_OBJETO_H
#define BMK_OBJETO_H

class BMK_Objeto{
    private:
        int x, y;
        BMK_Imagen *imagen_objeto;
        SDL_Rect contenedor;

    public:

        BMK_Objeto();
        void set_x(int x);
        void set_y(int y);
        int get_x();
        int get_y();
        int get_ancho();
        int get_altura();
        BMK_Imagen *get_imagen_objeto();
        void dibujar(SDL_Surface *pantalla);
        void set_imagen_objeto(const char* path);

};

BMK_Objeto::BMK_Objeto(){
    this->x = 0;
    this->y = 0;
    imagen_objeto = new BMK_Imagen;
}

void BMK_Objeto::set_x(int x){
    this->x = x;
}

void BMK_Objeto::set_y(int y){
    this->y = y;
}

int BMK_Objeto::get_x(){
    return this->x;
}

int BMK_Objeto::get_y(){
    return this->y;
}

int BMK_Objeto::get_ancho(){
    return imagen_objeto->get_imagen()->w;
}

int BMK_Objeto::get_altura(){
    return imagen_objeto->get_imagen()->h;
}

BMK_Imagen *BMK_Objeto::get_imagen_objeto(){
    return this->imagen_objeto;
}

void BMK_Objeto::dibujar(SDL_Surface *pantalla){

    this->contenedor.x = this->get_x();
    this->contenedor.y = this->get_y();

    this->contenedor.w = this->get_ancho();
    this->contenedor.h = this->get_altura();

    SDL_BlitSurface(this->imagen_objeto->get_imagen(),NULL,pantalla,&this->contenedor);
}

void BMK_Objeto::set_imagen_objeto(const char* path){
    this->imagen_objeto->cargar(path);
}


#endif








