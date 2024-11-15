cmake_minimum_required(VERSION 3.27)
project(fmi_gc)

set(CMAKE_CXX_STANDARD 17)

find_package(OpenGL REQUIRED)
find_package(PkgConfig REQUIRED)

# Set Homebrew prefix
set(HOMEBREW_PREFIX "/opt/homebrew")
set(FREEGLUT_PATH "${HOMEBREW_PREFIX}/Cellar/freeglut/3.6.0")

# Set PKG_CONFIG_PATH to locate .pc files
set(ENV{PKG_CONFIG_PATH} "${HOMEBREW_PREFIX}/lib/pkgconfig:${FREEGLUT_PATH}/lib/pkgconfig")

pkg_check_modules(GLEW REQUIRED glew)

# Include directories
include_directories(
        ${HOMEBREW_PREFIX}/include
        ${FREEGLUT_PATH}/include
        shaders/src # Include the "src" folder for loadShaders.h
)

# Link directories
link_directories(
        ${HOMEBREW_PREFIX}/lib
        ${FREEGLUT_PATH}/lib
)

# Add main.cpp and loadShaders.cpp to the executable
add_executable(
        fmi_gc
        laborator2/main.cpp
)

target_include_directories(fmi_gc PRIVATE
        ${GLEW_INCLUDE_DIRS}
)

target_link_directories(fmi_gc PRIVATE
        ${HOMEBREW_PREFIX}/lib
        ${FREEGLUT_PATH}/lib
)

# Link against the specific libraries
target_link_libraries(fmi_gc
        ${OPENGL_LIBRARIES}
        ${GLEW_LIBRARIES}
        "-framework OpenGL"
        ${FREEGLUT_PATH}/lib/libglut.dylib
)

# Set RPATH so the executable can find the libraries at runtime
set_target_properties(fmi_gc PROPERTIES
        BUILD_WITH_INSTALL_RPATH TRUE
        INSTALL_RPATH "${HOMEBREW_PREFIX}/lib;${FREEGLUT_PATH}/lib"
)

# Copy shader files to build directory
configure_file(shaders/example.vert shaders/example.vert COPYONLY)
configure_file(shaders/example.frag shaders/example.frag COPYONLY)
