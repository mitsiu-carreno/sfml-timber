#include <random>
#include <ctime>
#include <iostream>

// Initialize our mersenne twister with a random seed based on the clock
static std::mt19937 mersenne(static_cast<unsigned int>(std::time(nullptr)));

int gen_random(int min, int max)
{
    // Create a reusable random number generator that generates uniform numbers between min and max
    static std::uniform_int_distribution<> dice(min, max);
    
    /*
    int *randoms = new int[totalNumbers];
    for(int count=1; count <= totalNumbers; ++count)
    {

    }
    */
    float newRand = dice(mersenne);
    std::cout << "gen_random min:" << min << " max: " << max  << " rand: " << newRand << std::endl; 
    return newRand;
}