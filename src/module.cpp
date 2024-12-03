#include <string>
#include <vector>

#include <nanobind/nanobind.h>
#include <nanobind/stl/string.h>
#include <nanobind/stl/vector.h>

namespace nb = nanobind;


#define STRINGIFY(x) #x
#define MACRO_STRINGIFY(x) STRINGIFY(x)


namespace nb = nanobind;


void py_init_module_imgui_main(nb::module_& m);
void py_init_module_imgui_internal(nb::module_& m);


// This builds the native python module `_imgui_bundle`
// it will be wrapped in a standard python module `imgui_bundle`
NB_MODULE(pyimgui_ext, m) {
    #ifdef VERSION_INFO
    m.attr("__version__") = MACRO_STRINGIFY(VERSION_INFO);
    #else
    m.attr("__version__") = "dev";
    #endif
    py_init_module_imgui_main(m);
    auto module_imgui_internal =  m.def_submodule("internal");
    py_init_module_imgui_internal(module_imgui_internal);
}
