#include <iostream>
#include "cloud.hpp"
#include "constants.hpp"
#include "random_generator.hpp"

// If cloud is offscreen and needs to reset values
void setNewCloudPosition(Cloud &cloud, sf::Time dt)
{
    if(!cloud.isActive)
    {
        // Set a new scale for the cloud between 1/10 of the screen heigth and 1/3 of the screen height (randomly generated)
        int newCloudScale = gen_random(getWindowHeight()*0.10, getWindowHeight()*0.30);
        std::cout << newCloudScale << std::endl;
        cloud.spriteCloud.setScale(
            newCloudScale/cloud.spriteCloud.getLocalBounds().height,
            newCloudScale/cloud.spriteCloud.getLocalBounds().height
        );

        // How fast the cloud will be
        cloud.speed = gen_random(50, 200);

        // How high the cloud will be
        int height = gen_random(0, (getWindowHeight()*0.45)-cloud.spriteCloud.getGlobalBounds().height);

        cloud.spriteCloud.setPosition(getWindowWidth(), height);
        cloud.isActive = true;
    }
    else
    {
        // Move the cloud
        cloud.spriteCloud.setPosition(
            cloud.spriteCloud.getPosition().x - (cloud.speed * dt.asSeconds()),
            cloud.spriteCloud.getPosition().y
        );

        // Has the cloud reach the right edge of the screen?
        if(cloud.spriteCloud.getPosition().x < -100){
            // Set it up ready to be a hole new cloud on the left edge
            cloud.isActive = false;
        }
    }
}
