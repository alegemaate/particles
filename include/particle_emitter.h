/*
 * Particle Emitter
 * Allan Legemaate
 * 07/01/2017
 * A better particle system
 */
#ifndef PARTICLE_EMITTER_H
#define PARTICLE_EMITTER_H

#include <vector>

#include "vec2.h"
#include "particle.h"
#include "tools.h"

class particle_emitter{
  public:
    // Constructor
    particle_emitter();
    particle_emitter( vec2 min_pos, vec2 max_pos);

    // Destructor
    virtual ~particle_emitter();

    // Create particle
    void create_particle( int type);

    // Move
    void move_to( vec2 position);

    // Update
    void update( int dt);

    // Draw
    void draw( BITMAP *temp_image);
  protected:

  private:
    // Fuzzy image
    BITMAP *image;
    BITMAP *videoBitmap;

    // Velocity
    vec2 launch_velocity;

    // Emitter area
    vec2 min_pos;
    vec2 max_pos;

    // Create particle
    void create_particle( int x, int y);

    int type;

    // Particles
    std::vector <particle> particles;
};

#endif // PARTICLE_EMITTER_H