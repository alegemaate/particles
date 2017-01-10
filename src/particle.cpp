#include "particle.h"

// Constructor
particle::particle( int x, int y, vec2 velocity, vec2 acceleration, int size, int colorStart, int colorEnd, int life){
  this -> x = x;
  this -> y = y;

  this -> velocity = velocity;
  this -> acceleration = acceleration;

  this -> colorStart = colorStart;
  this -> colorEnd = colorEnd;
  mix_colors();

  this -> size = size;
  this -> life = this -> life_start = life;

  type = CIRCLE;

  this -> image = NULL;
}

// Make new color
void particle::mix_colors(){
  // For readability
  int r_1 = getr(colorStart);
  int r_2 = getr(colorEnd);
  int g_1 = getg(colorStart);
  int g_2 = getg(colorEnd);
  int b_1 = getb(colorStart);
  int b_2 = getb(colorEnd);

  this -> color = makecol( (r_1 * life + r_2 * (life_start - life)) / life_start,
                           (g_1 * life + g_2 * (life_start - life)) / life_start,
                           (b_1 * life + b_2 * (life_start - life)) / life_start);
}

// Is dead
bool particle::dead(){
  if( life <= 0)
    return true;
  return false;
}

// Set image
void particle::set_image( BITMAP *image){
  this -> image = image;
  this -> type = IMAGE;
}

// Logic
void particle::update( int dt){
  if( !dead()){
    life -= dt;
    x += velocity.x * dt;
    y += velocity.y * dt;
    velocity.x += acceleration.x * dt;
    velocity.y += acceleration.y * dt;
    mix_colors();
  }
}

// Draw
void particle::draw( BITMAP* tempBitmap){
  if( !dead()){
    if( type == IMAGE && image != NULL){
      //set_trans_blender( 255, 255, 255, int(float(life)/life_start * 255));
      set_alpha_blender();
      //circlefill( tempBitmap, x, y, image -> w / 2, color);
      draw_trans_sprite( tempBitmap, image, x - image -> w / 2, y - image -> w / 2);
    }
    else if( type == PIXEL){
      putpixel( tempBitmap, x, y, color);
    }
    else if( type == CIRCLE){
      circlefill( tempBitmap, x, y, size/2, color);
    }
    else if( type == SQUARE){
      rectfill( tempBitmap, x, y, x + size, y + size, color);
    }
  }
}