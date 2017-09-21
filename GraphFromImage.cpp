#include "GraphFromImage.h"

GraphFromImage::GraphFromImage(const bitmap_image& i) : image(i) {
    /* A IMPLEMENTER */
   i.width();
   i.height();
}

GraphFromImage::Iterable GraphFromImage::adjacent(int v) const {
    /* A IMPLEMENTER */
}

int GraphFromImage::idx(int x, int y) const {
    return y * image.width() + x;
}

int GraphFromImage::x(int idx) const {
   /* A IMPLEMENTER */
}

int GraphFromImage::y(int idx) const {
    /* A IMPLEMENTER */
}

int GraphFromImage::V() const {
   return image.pixel_count();
}
