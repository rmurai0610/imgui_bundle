cmake_minimum_required(VERSION 3.14)
project(pyimgui VERSION "1.6.0") # Remember to mirror changes to pyproject.toml!

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(VERSION_INFO v1.91.5)

# Find Python
find_package(Python REQUIRED COMPONENTS Interpreter Development)
execute_process(
  COMMAND "${Python_EXECUTABLE}" -m nanobind --cmake_dir
  OUTPUT_STRIP_TRAILING_WHITESPACE OUTPUT_VARIABLE nanobind_ROOT
)
find_package(Freetype REQUIRED)
find_package(nanobind CONFIG REQUIRED)


# imgui 
SET(IMGUI_SOURCES 
    external/imgui/imgui/imgui.cpp
    external/imgui/imgui/imgui_demo.cpp
    external/imgui/imgui/imgui_draw.cpp
    external/imgui/imgui/imgui_tables.cpp
    external/imgui/imgui/imgui_widgets.cpp
    external/imgui/imgui/imgui_stacklayout.cpp
    external/imgui/imgui/misc/cpp/imgui_stdlib.cpp
    external/imgui/imgui/misc/freetype/imgui_freetype.cpp
)


add_library(imgui STATIC ${IMGUI_SOURCES})
target_include_directories(imgui PUBLIC external/imgui/imgui ${FREETYPE_INCLUDE_DIRS})
target_link_libraries(imgui PUBLIC Freetype::Freetype)
target_compile_definitions(imgui PUBLIC IMGUI_BUNDLE_PYTHON_API IMGUI_USER_CONFIG="${CMAKE_CURRENT_LIST_DIR}/imgui_bundle_config.h")
set_target_properties(imgui PROPERTIES POSITION_INDEPENDENT_CODE ON)



# Define the target for the Python module
nanobind_add_module(pyimgui_ext
    STABLE_ABI
    src/module.cpp 
    src/pybind_imgui.cpp 
    src/pybind_imgui_internal.cpp 
    external/imgui/imgui_pywrappers/imgui_internal_pywrappers.cpp  
    external/imgui/imgui_pywrappers/imgui_pywrappers.cpp)
target_include_directories(pyimgui_ext PUBLIC external/imgui/imgui_pywrappers)
target_link_libraries(pyimgui_ext PUBLIC imgui)

install(TARGETS pyimgui_ext LIBRARY DESTINATION pyimgui)

