#include <particlesystem/force.h>
#include <particlesystem/particle.h>
#include <particlesystem/emitter.h>

// Add gravity to all particles
void Gravity::applyForce(std::vector<Particle>& particles) {
    for (size_t i = 0; i < particles.size(); i++) {
            particles[i].velocity.y -= float(0.001) * gravity;
    }
}

// Add wind to all particles
void Wind::applyForce(std::vector<Particle>& particles) {
    for (size_t i = 0; i < particles.size(); i++) {   
        particles[i].velocity.x += float(0.001) * power;
    }
}

