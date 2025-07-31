# `fdf`

![42 school project](https://img.shields.io/badge/42-Project-4285F4?style=for-the-badge&logo=42)

---

## Introduction

This project is part of the **42 school curriculum**. The goal of `fdf` is to create a program that reads a 3D map from a file and displays a wireframe model of the landscape on a graphical window. The project is an introduction to graphics programming and the use of the **ML42** library.

The program should be able to:

-   Read map data from a `.fdf` file.
-   Transform the 3D coordinates into a 2D projection.
-   Draw lines between the points to create a wireframe model.
-   Allow for different projections (e.g., isometric).

---

## How It Works

The `fdf` program operates in a few key stages:

1.  **Map Parsing**: The program reads a `.fdf` file, which contains a grid of numbers representing the Z-axis (height) of the map. It stores this data in a suitable data structure, like a 2D array or a linked list of points.

2.  **3D to 2D Projection**: Each point $(x, y, z)$ from the map is transformed into a 2D point $(x', y')$ on the screen. The transformation can be a simple parallel projection or a more complex isometric projection to give a sense of depth.

3.  **Drawing**: The program uses the ML42 library to draw lines between the projected 2D points. These lines connect adjacent points in the grid (e.g., `(x, y)` to `(x+1, y)` and `(x, y)` to `(x, y+1)`), creating the wireframe effect.

4.  **User Interaction**: The program handles keyboard and mouse events to allow the user to control the view. Common features include zooming in/out, changing the projection angle, or moving the map.

---

## Installation and Usage

To run `fdf`, you will need to have the **ML42** library installed and properly configured.

### Compilation

You can compile your program using the provided `Makefile`.

```bash
make
```

### Running the Program

The program takes a `.fdf` map file as an argument.

```bash
./fdf maps/42.fdf
```

### Example Map File (`42.fdf`)

```
0 0 0 0 0
0 0 4 0 0
0 4 0 4 0
0 0 4 0 0
0 0 0 0 0
```

---

## Project Contributor

-   **Ruben Finnerud** - [rubenfin](https://github.com/rubenfin)

---
