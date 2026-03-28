# Ludo-Cpp-Raylib

A work-in-progress Ludo board game.
Built with C++ and Raylib 5.5
## Status
In development, not feature complete.

## Controls
| Input | Action |
|-------|--------|
| Mouse | Select and move pieces |

## Building

### Prerequisites
- MinGW-W64 or Visual Studio 2022
- Git

### Windows (MinGW)
```
build-MinGW-W64.bat
make
```

### Windows (Visual Studio)
```
build-VisualStudio2022.bat
```
Then open the generated `.sln` file.

### Linux
```
cd build
./premake5 gmake
cd ..
make
```

### MacOS
```
cd build
./premake5.osx gmake
cd ..
make
```

## Output
Built binary will be in `bin/`.