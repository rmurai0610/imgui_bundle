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

#define IMGUI_DEFINE_MATH_OPERATORS
#include "imgui_toggle/imgui_toggle.h"
#include "imgui_toggle/imgui_toggle_palette.h"
#include "imgui_toggle/imgui_toggle_renderer.h"
#include "imgui_toggle/imgui_toggle_presets.h"

namespace nb = nanobind;

// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!  AUTOGENERATED CODE !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
// <litgen_glue_code>  // Autogenerated code below! Do not edit!

// </litgen_glue_code> // Autogenerated code end
// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!  AUTOGENERATED CODE END !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!



void py_init_module_imgui_toggle(nb::module_& m)
{
    using namespace ImGui;


    // !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!  AUTOGENERATED CODE !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    // <litgen_pydef> // Autogenerated code below! Do not edit!
    ////////////////////    <generated_from:imgui_toggle.h>    ////////////////////
    m.def("toggle",
        [](const char * label, bool v, const std::optional<const ImVec2> & size = std::nullopt) -> std::tuple<bool, bool>
        {
            auto Toggle_adapt_mutable_param_with_default_value = [](const char * label, bool * v, const std::optional<const ImVec2> & size = std::nullopt) -> bool
            {

                const ImVec2& size_or_default = [&]() -> const ImVec2 {
                    if (size.has_value())
                        return size.value();
                    else
                        return ImVec2();
                }();

                auto lambda_result = ImGui::Toggle(label, v, size_or_default);
                return lambda_result;
            };
            auto Toggle_adapt_modifiable_immutable_to_return = [&Toggle_adapt_mutable_param_with_default_value](const char * label, bool v, const std::optional<const ImVec2> & size = std::nullopt) -> std::tuple<bool, bool>
            {
                bool * v_adapt_modifiable = & v;

                bool r = Toggle_adapt_mutable_param_with_default_value(label, v_adapt_modifiable, size);
                return std::make_tuple(r, v);
            };

            return Toggle_adapt_modifiable_immutable_to_return(label, v, size);
        },
        nb::arg("label"), nb::arg("v"), nb::arg("size") = nb::none(),
        "---\nPython bindings defaults:\n    If size is None, then its default value will be: ImVec2()");

    m.def("toggle",
        [](const char * label, bool v, ImGuiToggleFlags flags, const std::optional<const ImVec2> & size = std::nullopt) -> std::tuple<bool, bool>
        {
            auto Toggle_adapt_mutable_param_with_default_value = [](const char * label, bool * v, ImGuiToggleFlags flags, const std::optional<const ImVec2> & size = std::nullopt) -> bool
            {

                const ImVec2& size_or_default = [&]() -> const ImVec2 {
                    if (size.has_value())
                        return size.value();
                    else
                        return ImVec2();
                }();

                auto lambda_result = ImGui::Toggle(label, v, flags, size_or_default);
                return lambda_result;
            };
            auto Toggle_adapt_modifiable_immutable_to_return = [&Toggle_adapt_mutable_param_with_default_value](const char * label, bool v, ImGuiToggleFlags flags, const std::optional<const ImVec2> & size = std::nullopt) -> std::tuple<bool, bool>
            {
                bool * v_adapt_modifiable = & v;

                bool r = Toggle_adapt_mutable_param_with_default_value(label, v_adapt_modifiable, flags, size);
                return std::make_tuple(r, v);
            };

            return Toggle_adapt_modifiable_immutable_to_return(label, v, flags, size);
        },
        nb::arg("label"), nb::arg("v"), nb::arg("flags"), nb::arg("size") = nb::none(),
        "---\nPython bindings defaults:\n    If size is None, then its default value will be: ImVec2()");

    m.def("toggle",
        [](const char * label, bool v, ImGuiToggleFlags flags, float animation_duration, const std::optional<const ImVec2> & size = std::nullopt) -> std::tuple<bool, bool>
        {
            auto Toggle_adapt_mutable_param_with_default_value = [](const char * label, bool * v, ImGuiToggleFlags flags, float animation_duration, const std::optional<const ImVec2> & size = std::nullopt) -> bool
            {

                const ImVec2& size_or_default = [&]() -> const ImVec2 {
                    if (size.has_value())
                        return size.value();
                    else
                        return ImVec2();
                }();

                auto lambda_result = ImGui::Toggle(label, v, flags, animation_duration, size_or_default);
                return lambda_result;
            };
            auto Toggle_adapt_modifiable_immutable_to_return = [&Toggle_adapt_mutable_param_with_default_value](const char * label, bool v, ImGuiToggleFlags flags, float animation_duration, const std::optional<const ImVec2> & size = std::nullopt) -> std::tuple<bool, bool>
            {
                bool * v_adapt_modifiable = & v;

                bool r = Toggle_adapt_mutable_param_with_default_value(label, v_adapt_modifiable, flags, animation_duration, size);
                return std::make_tuple(r, v);
            };

            return Toggle_adapt_modifiable_immutable_to_return(label, v, flags, animation_duration, size);
        },
        nb::arg("label"), nb::arg("v"), nb::arg("flags"), nb::arg("animation_duration"), nb::arg("size") = nb::none(),
        "---\nPython bindings defaults:\n    If size is None, then its default value will be: ImVec2()");

    m.def("toggle",
        [](const char * label, bool v, ImGuiToggleFlags flags, float frame_rounding, float knob_rounding, const std::optional<const ImVec2> & size = std::nullopt) -> std::tuple<bool, bool>
        {
            auto Toggle_adapt_mutable_param_with_default_value = [](const char * label, bool * v, ImGuiToggleFlags flags, float frame_rounding, float knob_rounding, const std::optional<const ImVec2> & size = std::nullopt) -> bool
            {

                const ImVec2& size_or_default = [&]() -> const ImVec2 {
                    if (size.has_value())
                        return size.value();
                    else
                        return ImVec2();
                }();

                auto lambda_result = ImGui::Toggle(label, v, flags, frame_rounding, knob_rounding, size_or_default);
                return lambda_result;
            };
            auto Toggle_adapt_modifiable_immutable_to_return = [&Toggle_adapt_mutable_param_with_default_value](const char * label, bool v, ImGuiToggleFlags flags, float frame_rounding, float knob_rounding, const std::optional<const ImVec2> & size = std::nullopt) -> std::tuple<bool, bool>
            {
                bool * v_adapt_modifiable = & v;

                bool r = Toggle_adapt_mutable_param_with_default_value(label, v_adapt_modifiable, flags, frame_rounding, knob_rounding, size);
                return std::make_tuple(r, v);
            };

            return Toggle_adapt_modifiable_immutable_to_return(label, v, flags, frame_rounding, knob_rounding, size);
        },
        nb::arg("label"), nb::arg("v"), nb::arg("flags"), nb::arg("frame_rounding"), nb::arg("knob_rounding"), nb::arg("size") = nb::none(),
        "---\nPython bindings defaults:\n    If size is None, then its default value will be: ImVec2()");

    m.def("toggle",
        [](const char * label, bool v, ImGuiToggleFlags flags, float animation_duration, float frame_rounding, float knob_rounding, const std::optional<const ImVec2> & size = std::nullopt) -> std::tuple<bool, bool>
        {
            auto Toggle_adapt_mutable_param_with_default_value = [](const char * label, bool * v, ImGuiToggleFlags flags, float animation_duration, float frame_rounding, float knob_rounding, const std::optional<const ImVec2> & size = std::nullopt) -> bool
            {

                const ImVec2& size_or_default = [&]() -> const ImVec2 {
                    if (size.has_value())
                        return size.value();
                    else
                        return ImVec2();
                }();

                auto lambda_result = ImGui::Toggle(label, v, flags, animation_duration, frame_rounding, knob_rounding, size_or_default);
                return lambda_result;
            };
            auto Toggle_adapt_modifiable_immutable_to_return = [&Toggle_adapt_mutable_param_with_default_value](const char * label, bool v, ImGuiToggleFlags flags, float animation_duration, float frame_rounding, float knob_rounding, const std::optional<const ImVec2> & size = std::nullopt) -> std::tuple<bool, bool>
            {
                bool * v_adapt_modifiable = & v;

                bool r = Toggle_adapt_mutable_param_with_default_value(label, v_adapt_modifiable, flags, animation_duration, frame_rounding, knob_rounding, size);
                return std::make_tuple(r, v);
            };

            return Toggle_adapt_modifiable_immutable_to_return(label, v, flags, animation_duration, frame_rounding, knob_rounding, size);
        },
        nb::arg("label"), nb::arg("v"), nb::arg("flags"), nb::arg("animation_duration"), nb::arg("frame_rounding"), nb::arg("knob_rounding"), nb::arg("size") = nb::none(),
        "---\nPython bindings defaults:\n    If size is None, then its default value will be: ImVec2()");

    m.def("toggle",
        [](const char * label, bool v, const ImGuiToggleConfig & config) -> std::tuple<bool, bool>
        {
            auto Toggle_adapt_modifiable_immutable_to_return = [](const char * label, bool v, const ImGuiToggleConfig & config) -> std::tuple<bool, bool>
            {
                bool * v_adapt_modifiable = & v;

                bool r = ImGui::Toggle(label, v_adapt_modifiable, config);
                return std::make_tuple(r, v);
            };

            return Toggle_adapt_modifiable_immutable_to_return(label, v, config);
        },     nb::arg("label"), nb::arg("v"), nb::arg("config"));


    auto pyEnumToggleFlags_ =
        nb::enum_<ImGuiToggleFlags_>(m, "ToggleFlags_", nb::is_arithmetic(), "ImGuiToggleFlags: A set of flags that adjust behavior and display for ImGui::Toggle().")
            .value("none", ImGuiToggleFlags_None, "")
            .value("animated", ImGuiToggleFlags_Animated, "The toggle's knob should be animated.")
            .value("bordered_frame", ImGuiToggleFlags_BorderedFrame, "The toggle should have a border drawn on the frame.")
            .value("bordered_knob", ImGuiToggleFlags_BorderedKnob, "The toggle should have a border drawn on the knob.")
            .value("shadowed_frame", ImGuiToggleFlags_ShadowedFrame, "The toggle should have a shadow drawn under the frame.")
            .value("shadowed_knob", ImGuiToggleFlags_ShadowedKnob, "The toggle should have a shadow drawn under the knob.")
            .value("a11y", ImGuiToggleFlags_A11y, "The toggle should draw on and off glyphs to help indicate its state.")
            .value("bordered", ImGuiToggleFlags_Bordered, "Shorthand for bordered frame and knob.")
            .value("shadowed", ImGuiToggleFlags_Shadowed, "Shorthand for shadowed frame and knob.")
            .value("default", ImGuiToggleFlags_Default, "The default flags used when no ImGuiToggleFlags_ are specified.");


    auto pyEnumToggleA11yStyle_ =
        nb::enum_<ImGuiToggleA11yStyle_>(m, "ToggleA11yStyle_", nb::is_arithmetic(), "ImGuiToggleA11yStyle: Styles to draw A11y labels.")
            .value("label", ImGuiToggleA11yStyle_Label, "A11y glyphs draw as text labels.")
            .value("glyph", ImGuiToggleA11yStyle_Glyph, "A11y glyphs draw as power-icon style \"I/O\" glyphs.")
            .value("dot", ImGuiToggleA11yStyle_Dot, "A11y glyphs draw as a small dot that can be colored separately from the frame.")
            .value("default", ImGuiToggleA11yStyle_Default, "Default: text labels.");


    auto pyClassImGuiToggleStateConfig =
        nb::class_<ImGuiToggleStateConfig>
            (m, "ToggleStateConfig", "")
        .def(nb::init<>()) // implicit default constructor
        .def_rw("frame_border_thickness", &ImGuiToggleStateConfig::FrameBorderThickness, "The thickness the border should be drawn on the frame when ImGuiToggleFlags_BorderedFrame is specified in `Flags`.")
        .def_rw("frame_shadow_thickness", &ImGuiToggleStateConfig::FrameShadowThickness, "The thickness the shadow should be drawn on the frame when ImGuiToggleFlags_ShadowedFrame is specified in `Flags`.")
        .def_rw("knob_border_thickness", &ImGuiToggleStateConfig::KnobBorderThickness, "The thickness the border should be drawn on the frame when ImGuiToggleFlags_BorderedKnob is specified in `Flags`.")
        .def_rw("knob_shadow_thickness", &ImGuiToggleStateConfig::KnobShadowThickness, "The thickness the shadow should be drawn on the frame when ImGuiToggleFlags_ShadowedKnob is specified in `Flags`.")
        .def_ro("label", &ImGuiToggleStateConfig::Label, " The label drawn on the toggle to show the toggle is in the when ImGuiToggleFlags_A11yLabels is specified in `Flags`.\n If left null, default strings will be used.")
        .def_rw("knob_inset", &ImGuiToggleStateConfig::KnobInset, " The number of pixels the knob should be inset into the toggle frame.\n With a round (circle) knob, an average of each offset will be used.\n With a rectangular knob, each offset will be used in it's intended direction.")
        .def_rw("knob_offset", &ImGuiToggleStateConfig::KnobOffset, "A custom amount of pixels to offset the knob by. Positive x values will move the knob towards the inside, negative the outside.")
        .def_ro("palette", &ImGuiToggleStateConfig::Palette, " An optional custom palette to use for the colors to use when drawing the toggle. If left null, theme colors will be used.\n If any of the values in the palette are zero, those specific colors will default to theme colors.")
        ;


    auto pyClassImGuiToggleConfig =
        nb::class_<ImGuiToggleConfig>
            (m, "ToggleConfig", "ImGuiToggleConfig: A collection of data used to customize the appearance and behavior of a toggle widget.")
        .def(nb::init<>()) // implicit default constructor
        .def_rw("flags", &ImGuiToggleConfig::Flags, "Flags that control the toggle's behavior and display.")
        .def_rw("a11y_style", &ImGuiToggleConfig::A11yStyle, "What style of A11y glyph to draw on the widget.")
        .def_rw("animation_duration", &ImGuiToggleConfig::AnimationDuration, "The a duration in seconds that the toggle should animate for. If 0, animation will be disabled.")
        .def_rw("frame_rounding", &ImGuiToggleConfig::FrameRounding, "A scalar that controls how rounded the toggle frame is. 0 is square, 1 is round. (0, 1) default 1.0")
        .def_rw("knob_rounding", &ImGuiToggleConfig::KnobRounding, "A scalar that controls how rounded the toggle knob is. 0 is square, 1 is round. (0, 1) default 1.0")
        .def_rw("width_ratio", &ImGuiToggleConfig::WidthRatio, "A ratio that controls how wide the toggle is compared to it's height. If `Size.x` is non-zero, this value is ignored.")
        .def_rw("size", &ImGuiToggleConfig::Size, " A custom size to draw the toggle with. Defaults to (0, 0). If `Size.x` is zero, `WidthRatio` will control the toggle width.\n If `Size.y` is zero, the toggle height will be set by `ImGui::GetFrameHeight()`.")
        .def_rw("on", &ImGuiToggleConfig::On, "Specific configuration data to use when the knob is in the on state.")
        .def_rw("off", &ImGuiToggleConfig::Off, "Specific configuration data to use when the knob is in the off state.")
        ;
    ////////////////////    </generated_from:imgui_toggle.h>    ////////////////////


    ////////////////////    <generated_from:imgui_toggle_presets.h>    ////////////////////
    m.def("default_style",
        ImGuiTogglePresets::DefaultStyle, " The default, unmodified style.\n(private API)");

    m.def("rectangle_style",
        ImGuiTogglePresets::RectangleStyle, " A style similar to default, but with rectangular knob and frame.\n(private API)");

    m.def("glowing_style",
        ImGuiTogglePresets::GlowingStyle, " A style that uses a shadow to appear to glow while it's on.\n(private API)");

    m.def("ios_style",
        ImGuiTogglePresets::iOSStyle,
        nb::arg("size_scale") = 1.0f, nb::arg("light_mode") = false,
        " A style that emulates what a toggle on iOS looks like.\n(private API)");

    m.def("material_style",
        ImGuiTogglePresets::MaterialStyle,
        nb::arg("size_scale") = 1.0f,
        " A style that emulates what a Material Design toggle looks like.\n(private API)");

    m.def("minecraft_style",
        ImGuiTogglePresets::MinecraftStyle,
        nb::arg("size_scale") = 1.0f,
        " A style that emulates what a toggle close to one from Minecraft.\n(private API)");
    ////////////////////    </generated_from:imgui_toggle_presets.h>    ////////////////////


    ////////////////////    <generated_from:imgui_toggle_palette.h>    ////////////////////
    auto pyClassImGuiTogglePalette =
        nb::class_<ImGuiTogglePalette>
            (m, "TogglePalette", " ImGuiTogglePalette: A collection of colors used to customize the rendering of a toggle widget.\n   Leaving any ImVec4 as default (zero) will allow the theme color to be used for that member.")
        .def(nb::init<>()) // implicit default constructor
        .def_rw("knob", &ImGuiTogglePalette::Knob, "The default knob color.")
        .def_rw("knob_hover", &ImGuiTogglePalette::KnobHover, "The default knob color, used when when the knob is hovered.")
        .def_rw("frame", &ImGuiTogglePalette::Frame, "The background color of the toggle frame.")
        .def_rw("frame_hover", &ImGuiTogglePalette::FrameHover, "The background color of the toggle frame when the toggle is hovered.")
        .def_rw("frame_border", &ImGuiTogglePalette::FrameBorder, "The background color of the toggle frame's border used when ImGuiToggleFlags_BorderedFrame is specified.")
        .def_rw("frame_shadow", &ImGuiTogglePalette::FrameShadow, "The shadow color of the toggle frame.")
        .def_rw("knob_border", &ImGuiTogglePalette::KnobBorder, "The background color of the toggle knob's border used when ImGuiToggleFlags_BorderedKnob is specified.")
        .def_rw("knob_shadow", &ImGuiTogglePalette::KnobShadow, "The shadow color of the toggle knob.")
        .def_rw("a11y_glyph", &ImGuiTogglePalette::A11yGlyph, "The color of the accessibility label or glyph.")
        ;


    m.def("union_palette",
        ImGui::UnionPalette,
        nb::arg("target"), nb::arg("candidate"), nb::arg("colors"), nb::arg("v"),
        "(private API)");

    m.def("blend_palettes",
        ImGui::BlendPalettes,
        nb::arg("result"), nb::arg("a"), nb::arg("b"), nb::arg("blend_amount"),
        "(private API)");
    ////////////////////    </generated_from:imgui_toggle_palette.h>    ////////////////////


    ////////////////////    <generated_from:imgui_offset_rect.h>    ////////////////////
    auto pyClassImOffsetRect =
        nb::class_<ImOffsetRect>
            (m, "ImOffsetRect", "Helper: ImOffsetRect A set of offsets to apply to an ImRect.")
        .def(nb::init<>())
        .def(nb::init<const ImVec2 &, const ImVec2 &>(),
            nb::arg("top_left"), nb::arg("bottom_right"))
        .def(nb::init<const ImVec4 &>(),
            nb::arg("v"))
        .def(nb::init<float, float, float, float>(),
            nb::arg("top"), nb::arg("left"), nb::arg("bottom"), nb::arg("right"))
        .def(nb::init<float>(),
            nb::arg("all"))
        .def("get_size",
            &ImOffsetRect::GetSize, "(private API)")
        .def("get_width",
            &ImOffsetRect::GetWidth, "(private API)")
        .def("get_height",
            &ImOffsetRect::GetHeight, "(private API)")
        .def("get_average",
            &ImOffsetRect::GetAverage, "(private API)")
        .def("mirror_horizontally",
            &ImOffsetRect::MirrorHorizontally, "(private API)")
        .def("mirror_vertically",
            &ImOffsetRect::MirrorVertically, "(private API)")
        .def("mirror",
            &ImOffsetRect::Mirror, "(private API)")
        ;
    ////////////////////    </generated_from:imgui_offset_rect.h>    ////////////////////

    // </litgen_pydef> // Autogenerated code end
    // !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!  AUTOGENERATED CODE END !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

    /*
    // The golden ratio.
    m.attr("Phi") = C::Phi;

    // d") = 2r
    m.attr("DiameterToRadiusRatio") = C::DiameterToRadiusRatio;

    // Animation is disabled with a animation_duration of 0.
    m.attr("AnimationDurationDisabled") = C::AnimationDurationDisabled;

    // The default animation duration, in seconds. (0.1f: 100 ms.)
    m.attr("AnimationDurationDefault") = C::AnimationDurationDefault;

    // The lowest allowable value for animation duration. (0.0f: Disabled animation.)
    m.attr("AnimationDurationMinimum") = C::AnimationDurationMinimum;

    // The default frame rounding value. (1.0f: Full rounding.)
    m.attr("FrameRoundingDefault") = C::FrameRoundingDefault;

    // The minimum frame rounding value. (0.0f: Full rectangle.)
    m.attr("FrameRoundingMinimum") = C::FrameRoundingMinimum;

    // The maximum frame rounding value. (1.0f: Full rounding.)
    m.attr("FrameRoundingMaximum") = C::FrameRoundingMaximum;

    // The default knob rounding value. (1.0f: Full rounding.)
    m.attr("KnobRoundingDefault") = C::KnobRoundingDefault;

    // The minimum knob rounding value. (0.0f: Full rectangle.)
    m.attr("KnobRoundingMinimum") = C::KnobRoundingMinimum;

    // The maximum knob rounding value. (1.0f: Full rounding.)
    m.attr("KnobRoundingMaximum") = C::KnobRoundingMaximum;

    // The default height to width ratio. (Phi: The golden ratio.)
    m.attr("WidthRatioDefault") = C::WidthRatioDefault;

    // The minimum allowable width ratio. (1.0f: Toggle width==height, not very useful but interesting.)
    m.attr("WidthRatioMinimum") = C::WidthRatioMinimum;

    // The maximum allowable width ratio. (10.0f: It starts to get silly quickly.)
    m.attr("WidthRatioMaximum") = C::WidthRatioMaximum;

    // The default amount of pixels the knob should be inset into the toggle frame. (1.5f in each direction: Pleasing to the eye.)
    m.attr("KnobInsetDefault") = C::KnobInsetDefault;

    // The minimum amount of pixels the knob should be negatively inset (outset) from the toggle frame. (-100.0f: Big overgrown toggle.)
    m.attr("KnobInsetMinimum") = C::KnobInsetMinimum;

    // The maximum amount of pixels the knob should be inset into the toggle frame. (100.0f: Toggle likely invisible!)
    m.attr("KnobInsetMaximum") = C::KnobInsetMaximum;

    // The default thickness for borders drawn on the toggle frame and knob.
    m.attr("BorderThicknessDefault") = C::BorderThicknessDefault;

    // The default thickness for shadows drawn under the toggle frame and knob.
    m.attr("ShadowThicknessDefault") = C::ShadowThicknessDefault;

    // The default a11y string used when the toggle is on.
    m.attr("LabelA11yOnDefault") = C::LabelA11yOffDefault;

    // The default a11y string used when the toggle is off.
    m.attr("LabelA11yOffDefault") = C::LabelA11yOffDefault;
    */
}
