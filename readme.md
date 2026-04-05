# Cloth Simulation - OpenGL Backend

A high-performance cloth simulation implemented in C++ demonstrating a custom-built OpenGL graphics pipeline from scratch, real-time physics using Verlet integration, and an interactive UI with ImGui.

## Description

This project (`opengl-sim` branch) takes a custom cloth simulation engine and renders it using a completely hand-rolled modern OpenGL pipeline. It simulates realistic cloth dynamics using Verlet integration and Jacobson's method for fast, stable constraints. The simulation allows you to interact with the cloth in a 3D environment using your mouse while manipulating real-time parameters. This project served as a deep dive into advanced C++ concepts, Object-Oriented Programming (OOP), and low-level GPU programming.

## 🛠️ My Experience Building the OpenGL Pipeline from Scratch

Transitioning the rendering engine to a pure OpenGL pipeline was a significant milestone in this project. It involved stepping away from high-level rendering abstractions to build a functional 3D graphics pipeline from the ground up. Key takeaways and features include:

* **Shader Programming:** Wrote custom Vertex and Fragment shaders in GLSL to handle dynamic transformations, projection, and basic lighting models (like Blinn-Phong) so the cloth reacts naturally to scene lighting.
* **Buffer Management (VAO/VBO/EBO):** Implemented an efficient dynamic rendering loop. Since the cloth particles are constantly moving, I had to optimize how often vertex data (positions and calculated normals) is sent to the GPU to avoid CPU-GPU bottlenecking.
* **Camera System:** Built a custom 3D camera class featuring view-projection matrix math to allow navigating around the simulation in 3D space.
* **Dynamic Normal Calculation:** Engineered real-time face/vertex normal calculations on the CPU every frame to ensure smooth shading as the cloth deforms, collapses, or stretches. 
* **Context & UI Integration:** Successfully initialized an OpenGL context (using tools like GLFW/GLEW or SDL2 with GL context) and integrated the ImGui OpenGL3 backend to overlay a profiling and control dashboard seamlessly.

## Physics

The simulation uses **Verlet integration** for calculating the continuous positions of the cloth particles and **Jacobson's method** for constraint solving. This approach allows for incredibly fast and stable physics calculations, preventing the cloth springs from exploding even under harsh user interactions.

## Installation

To build the project, you will need a C++ compiler (e.g., g++) and Make.
1. Clone the repository and checkout the OpenGL branch:
   ```bash
   git clone https://github.com/AishSoni/Cloth-Simulation.git
   cd Cloth-Simulation
   git checkout opengl-sim
   ```
2. Ensure you have the necessary dependencies installed on your system.
3. Run `make` to build the project.

## Usage

Run the generated executable to start the simulation. A window will launch containing the 3D cloth. You can adjust physics parameters via the ImGui overlay.

## Dependencies

* **OpenGL 3.3+** (Core Profile)
* **SDL2 / GLFW** (For window and context creation)
* **GLEW / GLAD** (For loading OpenGL functions)
* **GLM** (For matrix and vector mathematics)
* **ImGui** (For the interactive graphical user interface)

## Controls

* **Mouse Left Click & Drag:** Grab and interact with the cloth particles.
* **UI Panel:** Tweak simulation variables (gravity, constraints, iterations) and rendering modes (wireframe vs. solid).

## Concepts Mastered

This project heavily demonstrates applied C++ and OOP concepts such as classes, inheritance, polymorphism, and dynamic memory management. Visually, it showcases a deep understanding of the graphics rendering pipeline, matrix math, coordinate spaces, and performance profiling.

## Contributing

Contributions are welcome! Please submit a pull request with your changes.

## License

This project is licensed under the MIT License.
