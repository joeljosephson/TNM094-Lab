#include "particlesystem/particlesystem.h"
#include <particlesystem/particle.h>
#include <particlesystem/emitter.h>
#include <particlesystem/force.h>


#include <vector>



void Particlesystem::update(float dt) {

    for (size_t i = 0; i < particles.size(); i++) {
        particles[i].lifetime -= dt;
        particles[i].position += particles[i].velocity * dt;

        if (particles[i].lifetime <= 0) {
            particles.erase(particles.begin() + int(i));
        }
    }

    for (size_t i = 0; i < emitters.size(); i++) {
        emitters[i]->addParticle(particles, dt);
    }

    for (size_t j = 0; j < effects.size(); j++) {
        effects[j]->applyForce(particles);
    }
}
