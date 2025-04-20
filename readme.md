
---
## 🌀 miniRT
---

##  Overview

A simple **ray tracing** engine built in **C**, capable of rendering 3D scenes based on a plain-text scene description file. This project reads a `.rt` file, parses various 3D objects, and renders them using the MiniLibX graphical library.
**miniRT** parses and processes a custom scene file containing:

- Ambient lighting
- Camera configuration
- Light sources
- Geometric shapes: Sphere, Plane, Cylinder

These components are interpreted, and the scene is rendered with ray tracing techniques—calculating pixel color by simulating light rays.

---

## 🔧 How It Works

### ✅ Scene File Parsing
1. **Read the file:**  
   Opens and reads the `.rt` scene file using system calls (`open`, `read`, `close`).

2. **Split into elements:**  
   Lines are split and classified (e.g., Ambient, Camera, Sphere...).

3. **Element-specific processing:**  
   - `A` – Ambient light (ratio & RGB)
   - `C` – Camera (position, orientation, FOV)
   - `L` – Light (position, brightness, color)
   - `sp` – Sphere (center, diameter, color)
   - `pl` – Plane (point, normal, color)
   - `cy` – Cylinder (position, axis, diameter, height, color)

Each type has its own dedicated parser to validate and convert inputs to data structures.

---

### 🖼️ Rendering
Rays are generated from the camera and tested against scene objects:
- **Intersections** are calculated for each ray.
- **Lighting** and **shadows** are computed using the Phong reflection model.
- Results are drawn onto the window via **MiniLibX**.

---

## 📁 Project Structure

```bash
miniRT/
│
├── inc/               # Header files
│
├── libtool/           # Libft library
│
├── obj/               # Object files (generated)
│
├── src/
│   ├── draw/          # Rendering logic
│   ├── math/          # Vector math and intersection algorithms
│   └── parss/         # Scene parsing functions
│
├── Makefile
└── README.md
```

---

## 🛠️ Build Instructions

> Requirements: macOS with MiniLibX, a working `make`, and C compiler.

### 🔃 To build the project:
```bash
make
```

### 🧼 To clean object files:
```bash
make clean
```

### 🧨 To remove the binary:
```bash
make fclean
```

### 🔄 To rebuild from scratch:
```bash
make re
```

---

## 📌 Controls

Once running, the window will display the rendered scene. Basic keyboard/mouse interaction can be added for enhancements like:
- Moving the camera
- Rotating objects
- Reloading scenes

> *(Interaction behavior depends on your implementation)*

---

## 🧪 Example Scene File

```txt
A 0.3 255,255,255
C 0,0,15 0,0,1 100      
L -7,8,30 0.6 255,255,255
sp 0,2,30 3 255,0,0
pl 0,-3,0 0,1,0 0,255,255
pl 0,0,90 0,0,1 127,131,188
```

---

## ✍️ Authors

- `nbouljih`
- `faksouss`

---
