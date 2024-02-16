#include <rendering/window.h>
#include <example/randomsystem.h>

#include <particlesystem/particlesystem.h>
#include <particlesystem/particle.h>
#include <particlesystem/emitter.h>
#include <particlesystem/force.h>

#include <glm/vec2.hpp>
#include <glm/vec4.hpp>

#include <fmt/format.h>
#include <cmath>
#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include <ctime>
#include <cstdlib>


int main(int, char**) try {
    rendering::Window window("Particle System v0.0.2 pre-release alpha", 850, 850);

    Particlesystem ps;

    std::vector<glm::vec2> positions;
    std::vector<float> radiuses;
    std::vector<glm::vec4> colors;
    
    float angle = 0.0;

    double prevTime = 0.0;
    bool running = true;

    while (running) {
        window.beginFrame();

        const double t = window.time();
        float dt = t - prevTime;
        prevTime = t;

        // Clear screen with color
        window.clear({0, 0, 0, 1});

        {

            ps.update(dt);

            for (size_t i = 0; i < ps.particles.size(); i++) {
                positions.push_back(ps.particles[i].position);
                radiuses.push_back(ps.particles[i].radius);
                colors.push_back(ps.particles[i].color);
            }

            window.drawPoints(positions, radiuses, colors);

            positions.clear();
            radiuses.clear();
            colors.clear();
        }

        /*************************************************
         *                      UI                       *
         *************************************************/
        {
            {
                window.beginGuiWindow("Particle System");

                if (window.button("Close application")) {
                    running = false;
                }
                /************************************************
                *                   EMITTERS                    *
                *************************************************/
               
                // Directional
                if (window.button("Directional emitter")) {
                    Directional* D = new Directional(angle);
                    D->setAngle(angle);
                    ps.emitters.push_back(D);
                }
                // Slider to set initial angle of directional emitter
                window.sliderFloat("Angle", angle, 0.001f, 6.28f); 
                // std::cout << "Angle: " << angle << std::endl;

                // Uniform
                if (window.button("Uniform emitter")) {
                    ps.emitters.push_back(new Uniform(20));
                }

                // ------------ EFFECTS ------------

                // Gravity effect
                if (window.button("Gravity")) {
                    ps.effects.push_back(new Gravity(1.82));
                }

                // Wind effect
                if (window.button("Wind")) {
                    ps.effects.push_back(new Wind(1.5));
                }

                window.endGuiWindow();
            }
        }

        window.endFrame();
        running = running && !window.shouldClose();
    }

    return EXIT_SUCCESS;
} catch (const std::exception& e) {
    fmt::print("{}", e.what());
    return EXIT_FAILURE;
}

