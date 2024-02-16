#pragma once

#include <particlesystem/particle.h>
#include <particlesystem/emitter.h>
#include <particlesystem/force.h>

#include <vector>
#include <glm/vec2.hpp>


class Particlesystem {
public:
void update(float dt);

std::vector<Emitter*> emitters;

std::vector<Effect*> effects;

std::vector<Particle> particles;
};
