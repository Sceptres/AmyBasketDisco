# Amy, Bucket, and Disco
## Description
This project loads 3 different meshes, "Amy", the bucket, and the floor and renders them in the scene, where 3 spotlights rotate to show amy being in a disco. This project uses the following frameworks and libraries:

1. GLFW3
2. GLAD
3. GLM
4. TinyObjLoader

The app has the following keyboard controls:
1. Press p on your keyboard to capture the screen into a ppm image
2. Press b to render the world in debug mode (Render all geometry as lines)
3. Press esc to close the window

Below is the youtube video of the project
[![YouTube](http://i.ytimg.com/vi/lN7RMLmTI94/hqdefault.jpg)](https://www.youtube.com/watch?v=lN7RMLmTI94)

## Setup
To setup the project, you need to setup the GLFW3, GLAD, GLM, and TinyObjLoader libraries. Follow the steps in the following link to setup GLFW3, GLAD, and other system specific dependencies, https://learnopengl.com/Getting-started/Creating-a-window. Furthermore, the `glad.c` file must be placed in the `src/` folder. You can use the official glm github page to install and setup the library https://github.com/g-truc/glm. For the TinyObjLoader library, you can visit the github repo here to see its setup https://github.com/tinyobjloader/tinyobjloader.

After setting up all the libraries, open `Makefile` and add your include and lib paths.
```Make
INCDIR = # Include dir that contains glfw3, glad, GLM, TinyObjLoader header files
LIBDIR = # Lib dir that contains glfw3 library files
```

## How to run
To run this project, execute the `run.sh` shell script. This will build and start the application. You can also build the application yourself by running `make` command in the root directory of the project.
``` sh
make
```
After building the project, the executable will be found in the `src/` folder. For the executable to propery run the application, you must run the executable from within the `src/` folder.
```sh
cd src/
./AmyBucketDisco
```
