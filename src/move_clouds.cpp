#include "cloud.hpp"
#include "random_generator.hpp"

// If cloud is offscreen and needs to reset values
void setNewCloudPosition(Cloud &cloud, sf::Time dt)
{
    if(!cloud.isActive)
    {
        // How fast the cloud will be
        cloud.speed = gen_random(200, 400);

        // How high the cloud will be
        float height = gen_random(0, cloud.spriteCloud.getGlobalBounds().height * 2);

        cloud.spriteCloud.setPosition(300, height);
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
