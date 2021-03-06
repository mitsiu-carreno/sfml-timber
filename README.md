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