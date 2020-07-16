cmake_minimum_required(VERSION 3.15)
project(glfw_app)

add_executable(app main.c)

# Set C11 standard:
set_target_properties(app PROPERTIES LINKER_LANGUAGE C C_STANDARD 11)

# Silence OpenGL deprecation warnings:
target_compile_definitions(app PUBLIC GL_SILENCE_DEPRECATION)

# Link against GLFW 3:
target_link_directories(app PUBLIC glfw3/lib/)
target_include_directories(app PUBLIC glfw3/include/)
target_link_libraries(app glfw3)

# Link against macOS frameworks, required by GLFW 3:
target_link_libraries(app "-framework Cocoa" "-framework IOKit")

# Link against macOS' OpenGL framework:
target_link_libraries(app "-framework OpenGL")
