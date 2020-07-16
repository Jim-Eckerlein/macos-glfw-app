#include <stdio.h>
#include <stdlib.h>
#include <GLFW/glfw3.h>

int main(int argc, const char * argv[]) {
    if (!glfwInit()) {
        printf("Could not initialize GLFW\n");
        exit(-1);
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLFWwindow *window = glfwCreateWindow(800, 600, "Hello world", NULL, NULL);
    if (window == NULL) {
        printf("Could not create window");
        exit(-1);
    }
    
    glfwMakeContextCurrent(window);
    glClearColor(0.1f, 0.1f, 0.1f, 0.0f);

    GLuint buffer;
    glGenBuffers(1, &buffer);
    printf("Buffer: %d\n", buffer);

    GLuint program = glCreateProgram();
    printf("Program: %d\n", program);

    while (!glfwWindowShouldClose(window)) {
        glClear(GL_COLOR_BUFFER_BIT);
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
}

