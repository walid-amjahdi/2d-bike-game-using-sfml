# Leo's Adventure

Leo's Adventure is a single-player 2D C++ game made with SFML. Guide Leo on a bike to retrieve a forgotten backpack before time runs out, while jumping over obstacles.

## Features

- Main menu, story screens, about screen, game-over screen, and two levels.
- Time-limited obstacle courses with collision detection.
- Bike movement, acceleration, jumping, and keyboard navigation.

## Technologies

- C++
- SFML 2.x (the bundled runtime DLL names identify the SFML 2 major version; the precise release is unknown)

## Project structure

```text
.
├── assets/
│   ├── fonts/       # Fredoka font
│   └── images/      # Game backgrounds, sprites, and UI images
├── bin/             # Prebuilt Windows executable and runtime DLLs
├── include/         # C++ headers
├── src/             # C++ implementation files and entry point
├── CMakeLists.txt
├── LICENSE
└── README.md
```

The source entry point is `src/main.cpp`.

## Requirements

- A C++ compiler supported by CMake
- CMake 3.16 or newer
- SFML 2 development libraries with the Graphics, Window, and System components

## Build

Configure and build from the project root:

```powershell
cmake -S . -B build
cmake --build build
```

The CMake build copies the font and image assets next to the produced executable. This is required because the original game code loads assets by filename.

## Run

Run the executable produced in the build directory (its exact subdirectory depends on the generator). A prebuilt Windows executable and its SFML runtime DLLs are also provided in `bin/`; its required asset files are kept alongside it.

## Controls

- Mouse: choose menu buttons.
- `D`: move right in level 1.
- `Q`: move left in level 2.
- `Left Shift`: accelerate while moving.
- `Space`: jump and advance story text.
- `Escape`: return from the current screen where supported.

## Assets and gameplay

All supplied images and the Fredoka font are stored under `assets/`. No sound or music assets are included in this repository. Complete each timed route without hitting obstacles; reaching the backpack begins the return journey, and completing the return finishes the game.
