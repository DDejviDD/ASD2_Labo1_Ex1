#include "GraphFromImage.h"

GraphFromImage::GraphFromImage(const bitmap_image& i) : image(i) {
}

GraphFromImage::Iterable GraphFromImage::adjacent(int v) const {
   // renvoie une liste de sommets adjacents
   Iterable adjList;
   unsigned char r, g, b, r2, g2, b2;

   image.get_pixel(x(v), y(v), r, g, b);

   //pixel gauche
   if (x(v)) {
      image.get_pixel(x(v) - 1, y(v), r2, g2, b2);

      if (r == r2 && g == g2 && b == b2)
         adjList.push_back(v - 1);
   }

   //pixel droit
   if ((unsigned) x(v)<(image.width() - 1)) {
      image.get_pixel(x(v) + 1, y(v), r2, g2, b2);
      
      if (r == r2 && g == g2 && b == b2)
         adjList.push_back(v + 1);
   }
   //pixel haut-dessus
   // (unsigned) v >= image.width()
   if (y(v)) {
      image.get_pixel(x(v), y(v) - 1, r2, g2, b2);
      if (r == r2 && g == g2 && b == b2)
         adjList.push_back(v - image.width());
   }
   //pixel haut-dessous
   //(unsigned) v < (V() - image.width())
   if ((unsigned) y(v) < (image.height()-1)) {
      image.get_pixel(x(v), y(v) + 1, r2, g2, b2);
      if (r == r2 && g == g2 && b == b2)
         adjList.push_back(v + image.width());
   }



   return adjList;


}

int GraphFromImage::idx(int x, int y) const {
   return y * image.width() + x;
}

int GraphFromImage::x(int idx) const {
   return idx % image.width();
}

int GraphFromImage::y(int idx) const {
   return idx / image.width();
}

int GraphFromImage::V() const {
   return image.pixel_count();
}
