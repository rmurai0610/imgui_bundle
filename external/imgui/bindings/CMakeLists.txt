cmake_minimum_required(VERSION 3.14)

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
    ../imgui/imgui.cpp
    ../imgui/imgui_demo.cpp
    ../imgui/imgui_draw.cpp
    ../imgui/imgui_tables.cpp
    ../imgui/imgui_widgets.cpp
    ../imgui/imgui_stacklayout.cpp
    ../imgui/misc/cpp/imgui_stdlib.cpp
    ../imgui/misc/freetype/imgui_freetype.cpp
)


add_library(imgui STATIC ${IMGUI_SOURCES})
target_include_directories(imgui PUBLIC ../imgui ${FREETYPE_INCLUDE_DIRS})
target_link_libraries(imgui PUBLIC Freetype::Freetype)
target_compile_definitions(imgui PUBLIC IMGUI_DEFINE_MATH_OPERATORS IMGUI_BUNDLE_PYTHON_API)
set_target_properties(imgui PROPERTIES POSITION_INDEPENDENT_CODE ON)



# Define the target for the Python module
nanobind_add_module(_pyimgui
    STABLE_ABI
    src/module.cpp 
    src/pybind_imgui.cpp 
    src/pybind_imgui_internal.cpp 
    ../imgui_pywrappers/imgui_internal_pywrappers.cpp  
    ../imgui_pywrappers/imgui_pywrappers.cpp)
target_include_directories(_pyimgui PUBLIC ../imgui_pywrappers)
target_link_libraries(_pyimgui PUBLIC imgui)

install(TARGETS _pyimgui LIBRARY DESTINATION pyimgui)

