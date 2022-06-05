# SFML-Timber clone
This repo is created to store the codebase and files necessary to create a clone of the game Timber Guy, this is following the Beginning C++ Game Programming by John Horton
---

## Set-up
Install and setup SFML from the official website [SFML](https://www.sfml-dev.org/index.php)

## Compiling and running
```
$ make -j           // Compile, link and runs the application
$ make run          // Runs the existing binary (in bin/)
$ make clean        // Delete the binary (in bin/)
$ make hardclean    // Delete the objects (in build/) and the binary (in bin/)
```

## Compiling
```cpp
$ g++ src/main.cpp -o bin/sfml-app -lsfml-graphics -lsfml-window -lsfml-system
$ clang++ -framework Foundation main.cpp ResourcePath.mm -o sfml-app -lsfml-graphics -lsfml-window -lsfml-system -lstdc++ && ./sfml-app 
$ clang++ -framework Foundation src/main.cpp -I include -o bin/sfml-app -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio -lstdc++ && ./bin/sfml-app
```

## Compiling linux
```cpp
$ g++ src/constants.cpp  src/first_window.cpp src/hud.cpp src/main.cpp src/move_bee.cpp src/move_clouds.cpp src/random_generator.cpp -o bin/timber -I include/ -I include/entities/ -I include/ResourcePath/ -I ../SFML-2.5.1/include/ -L ../SFML-2.5.1/lib/ -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio
$ export LD_LIBRARY_PATH=../SFML-2.5.1/lib/ && ./bin/timber
```
