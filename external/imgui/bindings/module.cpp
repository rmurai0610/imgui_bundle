#include <nanobind/nanobind.h>


#define STRINGIFY(x) #x
#define MACRO_STRINGIFY(x) STRINGIFY(x)


namespace nb = nanobind;


void py_init_module_imgui_main(nb::module_& m);
void py_init_module_imgui_internal(nb::module_& m);


// This builds the native python module `_imgui_bundle`
// it will be wrapped in a standard python module `imgui_bundle`
NB_MODULE(example, m)
{
    #ifdef VERSION_INFO
    m.attr("__version__") = MACRO_STRINGIFY(VERSION_INFO);
    #else
    m.attr("__version__") = "dev";
    #endif
    auto module_imgui =  m.def_submodule("imgui");
    py_init_module_imgui_main(module_imgui);

    auto module_imgui_internal =  module_imgui.def_submodule("internal");
    py_init_module_imgui_internal(module_imgui_internal);

}
