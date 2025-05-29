# Cloth Simulation

A simple cloth simulation implemented in C++ using SDL2 and ImGui.

## Description

This project implements a cloth simulation using Verlet integration and Jacobson's method for fast physics calculations. The simulation allows you to interact with the cloth using the mouse and visualize the simulation in real-time. The project demonstrates various C++, OOPs (Object-Oriented Programming), and rendering concepts.

## Installation

To build the project, you will need a C++ compiler (e.g., g++) and Make.

1.  Clone the repository.
2.  Navigate to the project directory.
3.  Run `make` to build the project.

## Usage

Run the executable to start the simulation. You can click and drag the mouse to interact with the cloth.

## Dependencies

*   SDL2
*   ImGui

## Physics

The simulation uses Verlet integration for updating the positions of the cloth particles and Jacobson's method for constraint solving, which allows for fast and stable physics calculations.

## Concepts

This project demonstrates various C++ and OOP concepts such as classes, inheritance, polymorphism, and dynamic memory management. It also utilizes rendering concepts with SDL2, such as textures, surfaces, and rendering loops.

## Controls

*   Mouse Left Click: Drag to interact with the cloth.

## Contributing

Contributions are welcome! Please submit a pull request with your changes.

## License

This project is licensed under the MIT License.