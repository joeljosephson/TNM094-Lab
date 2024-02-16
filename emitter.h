#pragma once

#include <particlesystem/particle.h>
#include <particlesystem/emitter.h>
#include <particlesystem/force.h>

#include <vector>
#include <glm/vec2.hpp>
#include <glm/vec4.hpp>

class Emitter {
public:

    double time;
    double delay;

    bool tick(double dt);

    virtual void addParticle(std::vector<Particle>& particles, float dt) = 0;


};

class Directional : public Emitter {

public:
    Directional(float angle) : Emitter(), angle(angle) {}

    void addParticle(std::vector<Particle>& particles, float dt) override;
    float getAngle() const;
    void setAngle(float newAngle);

private:
    float angle;
};

class Uniform : public Emitter {

public:
    Uniform(int amount) : Emitter(), amount(amount) {}
    void addParticle(std::vector<Particle>& particles, float dt) override;
    int amount;
    ~Uniform();
};

//class Explosion : public Emitter {
//
//public:
//    Explosion(int amount) : Emitter(), amount(amount) {}
//    void addParticle(std::vector<Particle>& particles, float dt) override;
//    int amount;
//};
