#pragma once

#include <particlesystem/particle.h>
#include <particlesystem/emitter.h>
#include <particlesystem/force.h>

#include <vector>
#include <glm/vec2.hpp>

#pragma once
class Effect {
public:
    virtual void applyForce(std::vector<Particle>& particles) = 0;
};

class Gravity : public Effect {

public:
    Gravity(float gravity) : Effect(), gravity(gravity) {}

    void applyForce(std::vector<Particle>& particles) override;

    float gravity;
};

class Wind : public Effect {
public:
    Wind(float power) : Effect(), power(power) {}

    void applyForce(std::vector<Particle>& particles) override;
   
    float power;
};
