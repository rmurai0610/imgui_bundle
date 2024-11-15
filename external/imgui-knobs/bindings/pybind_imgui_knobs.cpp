// Part of ImGui Bundle - MIT License - Copyright (c) 2022-2024 Pascal Thomet - https://github.com/pthom/imgui_bundle
#include <nanobind/nanobind.h>
#include <nanobind/trampoline.h>
#include <nanobind/stl/array.h>
#include <nanobind/stl/string.h>
#include <nanobind/stl/vector.h>
#include <nanobind/stl/optional.h>
#include <nanobind/stl/function.h>
#include <nanobind/stl/shared_ptr.h>
#include <nanobind/stl/unique_ptr.h>
#include <nanobind/stl/map.h>
#include <nanobind/stl/tuple.h>
#include <nanobind/make_iterator.h>
#include <nanobind/ndarray.h>

#include "imgui-knobs/imgui-knobs.h"  // Change this include to the library you are binding

namespace nb = nanobind;

// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!  AUTOGENERATED CODE !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
// <litgen_glue_code>  // Autogenerated code below! Do not edit!

// </litgen_glue_code> // Autogenerated code end
// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!  AUTOGENERATED CODE END !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!



void py_init_module_imgui_knobs(nb::module_& m)
{
    using namespace ImGuiKnobs;

    // !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!  AUTOGENERATED CODE !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    // <litgen_pydef> // Autogenerated code below! Do not edit!
    ////////////////////    <generated_from:imgui-knobs.h>    ////////////////////
    auto pyEnumImGuiKnobFlags_ =
        py::enum_<ImGuiKnobFlags_>(m, "ImGuiKnobFlags_", py::arithmetic(), "")
            .value("no_title", ImGuiKnobFlags_NoTitle, "")
            .value("no_input", ImGuiKnobFlags_NoInput, "")
            .value("value_tooltip", ImGuiKnobFlags_ValueTooltip, "")
            .value("drag_horizontal", ImGuiKnobFlags_DragHorizontal, "");


    auto pyEnumImGuiKnobVariant_ =
        py::enum_<ImGuiKnobVariant_>(m, "ImGuiKnobVariant_", py::arithmetic(), "")
            .value("tick", ImGuiKnobVariant_Tick, "")
            .value("dot", ImGuiKnobVariant_Dot, "")
            .value("wiper", ImGuiKnobVariant_Wiper, "")
            .value("wiper_only", ImGuiKnobVariant_WiperOnly, "")
            .value("wiper_dot", ImGuiKnobVariant_WiperDot, "")
            .value("stepped", ImGuiKnobVariant_Stepped, "")
            .value("space", ImGuiKnobVariant_Space, "");


    auto pyClasscolor_set =
        py::class_<ImGuiKnobs::color_set>
            (m, "color_set", "")
        .def_readwrite("base", &ImGuiKnobs::color_set::base, "")
        .def_readwrite("hovered", &ImGuiKnobs::color_set::hovered, "")
        .def_readwrite("active", &ImGuiKnobs::color_set::active, "")
        .def(py::init<ImColor, ImColor, ImColor>(),
            py::arg("base"), py::arg("hovered"), py::arg("active"))
        .def(py::init<ImColor>(),
            py::arg("color"))
        ;


    m.def("knob",
        [](const char * label, float p_value, float v_min, float v_max, float speed = 0, std::optional<std::string> format = std::nullopt, ImGuiKnobVariant variant = ImGuiKnobVariant_Tick, float size = 0, ImGuiKnobFlags flags = 0, int steps = 10) -> std::tuple<bool, float>
        {
            auto Knob_adapt_const_char_pointer_with_default_null = [](const char * label, float * p_value, float v_min, float v_max, float speed = 0, std::optional<std::string> format = std::nullopt, ImGuiKnobVariant variant = ImGuiKnobVariant_Tick, float size = 0, ImGuiKnobFlags flags = 0, int steps = 10) -> bool
            {
                const char * format_adapt_default_null = nullptr;
                if (format.has_value())
                    format_adapt_default_null = format.value().c_str();

                auto lambda_result = ImGuiKnobs::Knob(label, p_value, v_min, v_max, speed, format_adapt_default_null, variant, size, flags, steps);
                return lambda_result;
            };
            auto Knob_adapt_modifiable_immutable_to_return = [&Knob_adapt_const_char_pointer_with_default_null](const char * label, float p_value, float v_min, float v_max, float speed = 0, std::optional<std::string> format = std::nullopt, ImGuiKnobVariant variant = ImGuiKnobVariant_Tick, float size = 0, ImGuiKnobFlags flags = 0, int steps = 10) -> std::tuple<bool, float>
            {
                float * p_value_adapt_modifiable = & p_value;

                bool r = Knob_adapt_const_char_pointer_with_default_null(label, p_value_adapt_modifiable, v_min, v_max, speed, format, variant, size, flags, steps);
                return std::make_tuple(r, p_value);
            };

            return Knob_adapt_modifiable_immutable_to_return(label, p_value, v_min, v_max, speed, format, variant, size, flags, steps);
        },     py::arg("label"), py::arg("p_value"), py::arg("v_min"), py::arg("v_max"), py::arg("speed") = 0, py::arg("format") = py::none(), py::arg("variant") = ImGuiKnobVariant_Tick, py::arg("size") = 0, py::arg("flags") = 0, py::arg("steps") = 10);

    m.def("knob_int",
        [](const char * label, int p_value, int v_min, int v_max, float speed = 0, std::optional<std::string> format = std::nullopt, ImGuiKnobVariant variant = ImGuiKnobVariant_Tick, float size = 0, ImGuiKnobFlags flags = 0, int steps = 10) -> std::tuple<bool, int>
        {
            auto KnobInt_adapt_const_char_pointer_with_default_null = [](const char * label, int * p_value, int v_min, int v_max, float speed = 0, std::optional<std::string> format = std::nullopt, ImGuiKnobVariant variant = ImGuiKnobVariant_Tick, float size = 0, ImGuiKnobFlags flags = 0, int steps = 10) -> bool
            {
                const char * format_adapt_default_null = nullptr;
                if (format.has_value())
                    format_adapt_default_null = format.value().c_str();

                auto lambda_result = ImGuiKnobs::KnobInt(label, p_value, v_min, v_max, speed, format_adapt_default_null, variant, size, flags, steps);
                return lambda_result;
            };
            auto KnobInt_adapt_modifiable_immutable_to_return = [&KnobInt_adapt_const_char_pointer_with_default_null](const char * label, int p_value, int v_min, int v_max, float speed = 0, std::optional<std::string> format = std::nullopt, ImGuiKnobVariant variant = ImGuiKnobVariant_Tick, float size = 0, ImGuiKnobFlags flags = 0, int steps = 10) -> std::tuple<bool, int>
            {
                int * p_value_adapt_modifiable = & p_value;

                bool r = KnobInt_adapt_const_char_pointer_with_default_null(label, p_value_adapt_modifiable, v_min, v_max, speed, format, variant, size, flags, steps);
                return std::make_tuple(r, p_value);
            };

            return KnobInt_adapt_modifiable_immutable_to_return(label, p_value, v_min, v_max, speed, format, variant, size, flags, steps);
        },     py::arg("label"), py::arg("p_value"), py::arg("v_min"), py::arg("v_max"), py::arg("speed") = 0, py::arg("format") = py::none(), py::arg("variant") = ImGuiKnobVariant_Tick, py::arg("size") = 0, py::arg("flags") = 0, py::arg("steps") = 10);
    ////////////////////    </generated_from:imgui-knobs.h>    ////////////////////

    // </litgen_pydef> // Autogenerated code end
    // !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!  AUTOGENERATED CODE END !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
}
