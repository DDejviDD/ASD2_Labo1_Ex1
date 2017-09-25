#include "GraphFromImage.h"

GraphFromImage::GraphFromImage(const bitmap_image& i) : image(i) {}

GraphFromImage::Iterable GraphFromImage::adjacent(int v) const {
    Iterable adjList;
    int LIMITE_INF = 0;
    int LIMITE_SUP = V();
    int idxv = idx(x(v),y(v));
    unsigned char r,g,b;


    image.get_pixel(x(v), y(v),r,g,b);

    if(!(r+b+g))
        return adjList;

    //pixel gauche
    if(x(v) && idxv-1 >= LIMITE_INF && idxv-1 < LIMITE_SUP){
        image.get_pixel(x(v), y(v),r,g,b);
        if(r+g+b)
            adjList.push_back(idxv-1);
    }
    //pixel droit
    if((x(v)<image.width()) && idxv+1 >= LIMITE_INF && idxv+1 < LIMITE_SUP){
        image.get_pixel(x(v), y(v),r,g,b);
        if(r+g+b)
            adjList.push_back(idxv+1);
    }
    //pixel haut-dessus
    if(idxv>=image.width()){
        image.get_pixel(x(v), y(v),r,g,b);
        if(r+g+b)
            adjList.push_back(idxv-image.width());
    }
    //pixel haut-dessous
    if(idxv<(V()-image.width())){
        image.get_pixel(x(v), y(v),r,g,b);
        if(r+g+b)
            adjList.push_back(idxv+image.width());
    }



    return adjList;

}

int GraphFromImage::idx(int x, int y) const {
    return y * image.width() + x;
}

int GraphFromImage::x(int idx) const {
   return idx%image.width();
}

int GraphFromImage::y(int idx) const {
   return idx/image.width();
}

int GraphFromImage::V() const {
   return image.pixel_count();
}
