#include <random>
#include <ctime>

int gen_random(int min, int max)
{
    // Initialize our mersenne twister with a random seed based on the clock
    std::mt19937 mersenne(static_cast<unsigned int>(std::time(nullptr)));

    // Create a reusable random number generator that generates uniform numbers between min and max
    std::uniform_int_distribution<> dice(min, max);

    /*
    int *randoms = new int[totalNumbers];
    for(int count=1; count <= totalNumbers; ++count)
    {

    }
    */
    return dice(mersenne);
}