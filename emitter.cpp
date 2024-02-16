#include <particlesystem/emitter.h>
#include <particlesystem/particle.h>

#include <iostream>
#include <cstdlib>
#include <ctime>

bool Emitter::tick(double dt) {
    time += dt;
    if (time > delay) {
        time = 0;
        return true;
    }
    return false;
}

void Directional::addParticle(std::vector<Particle>& particles, float dt) {
    delay = 0.25;

    Particle particle;
    particle.position = {-0.5, 0.5};
    particle.lifetime = 5;
    particle.color = {0.2, 1, 0.2, 1};

    // Emitter
    Particle E;
    E.position = particle.position;
    E.radius = 25;
    E.color = {1, 0.2, 0.2, 1};
    E.velocity = {0.0, 0.0};
    particles.push_back(E);

    if (tick(dt)) {
    
        angle = this->getAngle();
        particle.velocity.y = float(sin(angle));
        particle.velocity.x = float(cos(angle));

        particle.radius = float(10);

        particles.push_back(particle);
    }
}

void Directional::setAngle(float newAngle) { angle = newAngle; }

float Directional::getAngle() const { return angle; }

void Uniform::addParticle(std::vector<Particle>& particles, float dt) {
    delay = 0.5;
    
    const int numParticles = 30;
    const float step = 2 * 3.14 / numParticles;
    
    Particle particle;
    particle.position = {0.5, 0.5};
    particle.lifetime = 5;
    particle.color = {0.2, 0.2, 1, 1};

    // Emitter
    Particle E;
    E.position = particle.position;
    E.radius = 25;
    E.color = {1, 0.2, 0.2, 1};
    E.velocity = {0.0, 0.0};
    particles.push_back(E);

    if (tick(dt)) {
        for (int i = 0; i < numParticles; i++) {
            particle.velocity.y = sin(step * i);
            particle.velocity.x = cos(step * i);
            particle.radius = float(10);
            particles.push_back(particle);
        }
    }
}


