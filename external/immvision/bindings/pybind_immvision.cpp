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

namespace nb = nanobind;


#ifndef IMGUI_BUNDLE_WITH_IMMVISION
void py_init_module_immvision(nb::module_& m)
{
    m.def("immvision_not_available", []() { return std::string("immvision_not_available: imgui_bundle was compiled without immvision"); });
}
#else

#include "immvision/immvision.h"
#include "immvision/internal/cv/cv_drawing_utils.h"
#include "opencv2/core/core.hpp"
#include "cvnp_nano/cvnp_nano.h"


// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!  AUTOGENERATED CODE !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
// <litgen_glue_code>  // Autogenerated code below! Do not edit!

// </litgen_glue_code> // Autogenerated code end
// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!  AUTOGENERATED CODE END !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

namespace ImmVision {
    namespace ImageDrawing
    {
        cv::Mat _DrawLutGraph(const std::vector<double>& x, const std::vector<double>& y, cv::Size size);
    }
}


void py_init_module_immvision(nb::module_& m)
{
    m.def("_draw_lut_graph", ImmVision::ImageDrawing::_DrawLutGraph);

    using namespace ImmVision;

    // !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!  AUTOGENERATED CODE !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    // <litgen_pydef> // Autogenerated code below! Do not edit!
    ////////////////////    <generated_from:immvision.h>    ////////////////////
    m.def("use_rgb_color_order",
        ImmVision::UseRgbColorOrder, "(private API)");

    m.def("use_bgr_color_order",
        ImmVision::UseBgrColorOrder, "(private API)");

    m.def("is_using_rgb_color_order",
        ImmVision::IsUsingRgbColorOrder, " Returns True if we are using RGB color order\n(private API)");

    m.def("is_using_bgr_color_order",
        ImmVision::IsUsingBgrColorOrder, " Returns True if we are using BGR color order\n(private API)");

    m.def("is_color_order_undefined",
        ImmVision::IsColorOrderUndefined, " Returns True if the color order is undefined (i.e. UseRgbColorOrder or UseBgrColorOrder was not called)\n(private API)");

    m.def("push_color_order_rgb",
        ImmVision::PushColorOrderRgb, "(private API)");

    m.def("push_color_order_bgr",
        ImmVision::PushColorOrderBgr, "(private API)");

    m.def("pop_color_order",
        ImmVision::PopColorOrder, "(private API)");


    auto pyEnumColorMapStatsTypeId =
        nb::enum_<ImmVision::ColorMapStatsTypeId>(m, "ColorMapStatsTypeId", nb::is_arithmetic(), "Are we using the stats on the full image, on the Visible ROI, or are we using Min/Max values")
            .value("from_full_image", ImmVision::ColorMapStatsTypeId::FromFullImage, "")
            .value("from_visible_roi", ImmVision::ColorMapStatsTypeId::FromVisibleROI, "");


    auto pyClassColormapScaleFromStatsData =
        nb::class_<ImmVision::ColormapScaleFromStatsData>
            (m, "ColormapScaleFromStatsData", " Scale the Colormap according to the Image  stats\n\nIMMVISION_API_STRUCT")
        .def("__init__", [](ImmVision::ColormapScaleFromStatsData * self, ImmVision::ColorMapStatsTypeId ColorMapStatsType = ImmVision::ColorMapStatsTypeId::FromFullImage, double NbSigmas = 1.5, bool UseStatsMin = false, bool UseStatsMax = false)
        {
            new (self) ImmVision::ColormapScaleFromStatsData();  // placement new
            auto r = self;
            r->ColorMapStatsType = ColorMapStatsType;
            r->NbSigmas = NbSigmas;
            r->UseStatsMin = UseStatsMin;
            r->UseStatsMax = UseStatsMax;
        },
        nb::arg("color_map_stats_type") = ImmVision::ColorMapStatsTypeId::FromFullImage, nb::arg("nb_sigmas") = 1.5, nb::arg("use_stats_min") = false, nb::arg("use_stats_max") = false
        )
        .def_rw("color_map_stats_type", &ImmVision::ColormapScaleFromStatsData::ColorMapStatsType, "Are we using the stats on the full image, the visible ROI, or are we using Min/Max values")
        .def_rw("nb_sigmas", &ImmVision::ColormapScaleFromStatsData::NbSigmas, "If stats active (either on ROI or on Image), how many sigmas around the mean should the Colormap be applied")
        .def_rw("use_stats_min", &ImmVision::ColormapScaleFromStatsData::UseStatsMin, "If ColorMapScaleType==ColorMapStatsType::FromMinMax, then ColormapScaleMin will be calculated from the matrix min value instead of a sigma based value")
        .def_rw("use_stats_max", &ImmVision::ColormapScaleFromStatsData::UseStatsMax, "If ColorMapScaleType==ColorMapStatsType::FromMinMax, then ColormapScaleMax will be calculated from the matrix min value instead of a sigma based value")
        ;


    auto pyClassColormapSettingsData =
        nb::class_<ImmVision::ColormapSettingsData>
            (m, "ColormapSettingsData", " Colormap Settings (useful for matrices with one channel, in order to see colors mapping float values)\n\nIMMVISION_API_STRUCT")
        .def("__init__", [](ImmVision::ColormapSettingsData * self, std::string Colormap = "None", double ColormapScaleMin = 0., double ColormapScaleMax = 1., const std::optional<const ImmVision::ColormapScaleFromStatsData> & ColormapScaleFromStats = std::nullopt, std::string internal_ColormapHovered = "")
        {
            new (self) ImmVision::ColormapSettingsData();  // placement new
            auto r = self;
            r->Colormap = Colormap;
            r->ColormapScaleMin = ColormapScaleMin;
            r->ColormapScaleMax = ColormapScaleMax;
            if (ColormapScaleFromStats.has_value())
                r->ColormapScaleFromStats = ColormapScaleFromStats.value();
            else
                r->ColormapScaleFromStats = ImmVision::ColormapScaleFromStatsData();
            r->internal_ColormapHovered = internal_ColormapHovered;
        },
        nb::arg("colormap") = "None", nb::arg("colormap_scale_min") = 0., nb::arg("colormap_scale_max") = 1., nb::arg("colormap_scale_from_stats") = nb::none(), nb::arg("internal_colormap_hovered") = ""
        )
        .def_rw("colormap", &ImmVision::ColormapSettingsData::Colormap, " Colormap, see available Colormaps with AvailableColormaps()\n Work only with 1 channel matrices, i.e len(shape)==2")
        .def_rw("colormap_scale_min", &ImmVision::ColormapSettingsData::ColormapScaleMin, "")
        .def_rw("colormap_scale_max", &ImmVision::ColormapSettingsData::ColormapScaleMax, "")
        .def_rw("colormap_scale_from_stats", &ImmVision::ColormapSettingsData::ColormapScaleFromStats, " If ColormapScaleFromStats.ActiveOnFullImage or ColormapScaleFromStats.ActiveOnROI,\n then ColormapScaleMin/Max are ignored, and the scaling is done according to the image stats.\n ColormapScaleFromStats.ActiveOnFullImage is True by default")
        .def_rw("internal_colormap_hovered", &ImmVision::ColormapSettingsData::internal_ColormapHovered, "Internal value: stores the name of the Colormap that is hovered by the mouse")
        ;


    auto pyClassMouseInformation =
        nb::class_<ImmVision::MouseInformation>
            (m, "MouseInformation", " Contains information about the mouse inside an image\n\nIMMVISION_API_STRUCT")
        .def("__init__", [](ImmVision::MouseInformation * self, bool IsMouseHovering = false, const std::optional<const cv::Point2d> & MousePosition = std::nullopt, const std::optional<const cv::Point> & MousePosition_Displayed = std::nullopt)
        {
            new (self) ImmVision::MouseInformation();  // placement new
            auto r = self;
            r->IsMouseHovering = IsMouseHovering;
            if (MousePosition.has_value())
                r->MousePosition = MousePosition.value();
            else
                r->MousePosition = cv::Point2d(-1., -1.);
            if (MousePosition_Displayed.has_value())
                r->MousePosition_Displayed = MousePosition_Displayed.value();
            else
                r->MousePosition_Displayed = cv::Point(-1, -1);
        },
        nb::arg("is_mouse_hovering") = false, nb::arg("mouse_position") = nb::none(), nb::arg("mouse_position_displayed") = nb::none()
        )
        .def_rw("is_mouse_hovering", &ImmVision::MouseInformation::IsMouseHovering, "Is the mouse hovering the image")
        .def_rw("mouse_position", &ImmVision::MouseInformation::MousePosition, " Mouse position in the original image/matrix\n This position is given with float coordinates, and will be (-1., -1.) if the mouse is not hovering the image")
        .def_rw("mouse_position_displayed", &ImmVision::MouseInformation::MousePosition_Displayed, " Mouse position in the displayed portion of the image (the original image can be zoomed,\n and only show a subset if it may be shown).\n This position is given with integer coordinates, and will be (-1, -1) if the mouse is not hovering the image")
        ;


    auto pyClassImageParams =
        nb::class_<ImmVision::ImageParams>
            (m, "ImageParams", " Set of display parameters and options for an Image\n\nIMMVISION_API_STRUCT")
        .def("__init__", [](ImmVision::ImageParams * self, bool RefreshImage = false, const std::optional<const cv::Size> & ImageDisplaySize = std::nullopt, const std::optional<const cv::Matx33d> & ZoomPanMatrix = std::nullopt, std::string ZoomKey = "", const std::optional<const ImmVision::ColormapSettingsData> & ColormapSettings = std::nullopt, std::string ColormapKey = "", bool PanWithMouse = true, bool ZoomWithMouseWheel = true, bool CanResize = true, bool ResizeKeepAspectRatio = true, int SelectedChannel = -1, bool ShowSchoolPaperBackground = true, bool ShowAlphaChannelCheckerboard = true, bool ShowGrid = true, bool DrawValuesOnZoomedPixels = true, bool ShowImageInfo = true, bool ShowPixelInfo = true, bool ShowZoomButtons = true, bool ShowOptionsPanel = false, bool ShowOptionsInTooltip = false, bool ShowOptionsButton = true, const std::optional<const std::vector<cv::Point>> & WatchedPixels = std::nullopt, bool AddWatchedPixelOnDoubleClick = true, bool HighlightWatchedPixels = true, const std::optional<const ImmVision::MouseInformation> & MouseInfo = std::nullopt)
        {
            new (self) ImmVision::ImageParams();  // placement new
            auto r = self;
            r->RefreshImage = RefreshImage;
            if (ImageDisplaySize.has_value())
                r->ImageDisplaySize = ImageDisplaySize.value();
            else
                r->ImageDisplaySize = cv::Size();
            if (ZoomPanMatrix.has_value())
                r->ZoomPanMatrix = ZoomPanMatrix.value();
            else
                r->ZoomPanMatrix = cv::Matx33d::eye();
            r->ZoomKey = ZoomKey;
            if (ColormapSettings.has_value())
                r->ColormapSettings = ColormapSettings.value();
            else
                r->ColormapSettings = ImmVision::ColormapSettingsData();
            r->ColormapKey = ColormapKey;
            r->PanWithMouse = PanWithMouse;
            r->ZoomWithMouseWheel = ZoomWithMouseWheel;
            r->CanResize = CanResize;
            r->ResizeKeepAspectRatio = ResizeKeepAspectRatio;
            r->SelectedChannel = SelectedChannel;
            r->ShowSchoolPaperBackground = ShowSchoolPaperBackground;
            r->ShowAlphaChannelCheckerboard = ShowAlphaChannelCheckerboard;
            r->ShowGrid = ShowGrid;
            r->DrawValuesOnZoomedPixels = DrawValuesOnZoomedPixels;
            r->ShowImageInfo = ShowImageInfo;
            r->ShowPixelInfo = ShowPixelInfo;
            r->ShowZoomButtons = ShowZoomButtons;
            r->ShowOptionsPanel = ShowOptionsPanel;
            r->ShowOptionsInTooltip = ShowOptionsInTooltip;
            r->ShowOptionsButton = ShowOptionsButton;
            if (WatchedPixels.has_value())
                r->WatchedPixels = WatchedPixels.value();
            else
                r->WatchedPixels = std::vector<cv::Point>();
            r->AddWatchedPixelOnDoubleClick = AddWatchedPixelOnDoubleClick;
            r->HighlightWatchedPixels = HighlightWatchedPixels;
            if (MouseInfo.has_value())
                r->MouseInfo = MouseInfo.value();
            else
                r->MouseInfo = ImmVision::MouseInformation();
        },
        nb::arg("refresh_image") = false, nb::arg("image_display_size") = nb::none(), nb::arg("zoom_pan_matrix") = nb::none(), nb::arg("zoom_key") = "", nb::arg("colormap_settings") = nb::none(), nb::arg("colormap_key") = "", nb::arg("pan_with_mouse") = true, nb::arg("zoom_with_mouse_wheel") = true, nb::arg("can_resize") = true, nb::arg("resize_keep_aspect_ratio") = true, nb::arg("selected_channel") = -1, nb::arg("show_school_paper_background") = true, nb::arg("show_alpha_channel_checkerboard") = true, nb::arg("show_grid") = true, nb::arg("draw_values_on_zoomed_pixels") = true, nb::arg("show_image_info") = true, nb::arg("show_pixel_info") = true, nb::arg("show_zoom_buttons") = true, nb::arg("show_options_panel") = false, nb::arg("show_options_in_tooltip") = false, nb::arg("show_options_button") = true, nb::arg("watched_pixels") = nb::none(), nb::arg("add_watched_pixel_on_double_click") = true, nb::arg("highlight_watched_pixels") = true, nb::arg("mouse_info") = nb::none()
        )
        .def_rw("refresh_image", &ImmVision::ImageParams::RefreshImage, " Refresh Image: images textures are cached. Set to True if your image matrix/buffer has changed\n (for example, for live video images)")
        .def_rw("image_display_size", &ImmVision::ImageParams::ImageDisplaySize, " Size of the displayed image (can be different from the matrix size)\n If you specify only the width or height (e.g (300, 0), then the other dimension\n will be calculated automatically, respecting the original image w/h ratio.")
        .def_rw("zoom_pan_matrix", &ImmVision::ImageParams::ZoomPanMatrix, "ZoomPanMatrix can be created using MakeZoomPanMatrix to create a view centered around a given point")
        .def_rw("zoom_key", &ImmVision::ImageParams::ZoomKey, "If displaying several images, those with the same ZoomKey will zoom and pan together")
        .def_rw("colormap_settings", &ImmVision::ImageParams::ColormapSettings, "\n Colormap Settings (useful for matrices with one channel, in order to see colors mapping float values)\n\n ColormapSettings stores all the parameter concerning the Colormap")
        .def_rw("colormap_key", &ImmVision::ImageParams::ColormapKey, "If displaying several images, those with the same ColormapKey will adjust together")
        .def_rw("pan_with_mouse", &ImmVision::ImageParams::PanWithMouse, "")
        .def_rw("zoom_with_mouse_wheel", &ImmVision::ImageParams::ZoomWithMouseWheel, "")
        .def_rw("can_resize", &ImmVision::ImageParams::CanResize, "Can the image widget be resized by the user")
        .def_rw("resize_keep_aspect_ratio", &ImmVision::ImageParams::ResizeKeepAspectRatio, "Does the widget keep an aspect ratio equal to the image when resized")
        .def_rw("selected_channel", &ImmVision::ImageParams::SelectedChannel, "\n Image display options\n\n if SelectedChannel >= 0 then only this channel is displayed")
        .def_rw("show_school_paper_background", &ImmVision::ImageParams::ShowSchoolPaperBackground, "Show a \"school paper\" background grid")
        .def_rw("show_alpha_channel_checkerboard", &ImmVision::ImageParams::ShowAlphaChannelCheckerboard, "show a checkerboard behind transparent portions of 4 channels RGBA images")
        .def_rw("show_grid", &ImmVision::ImageParams::ShowGrid, "Grid displayed when the zoom is high")
        .def_rw("draw_values_on_zoomed_pixels", &ImmVision::ImageParams::DrawValuesOnZoomedPixels, "Pixel values show when the zoom is high")
        .def_rw("show_image_info", &ImmVision::ImageParams::ShowImageInfo, "\n Image display options\n\n Show matrix type and size")
        .def_rw("show_pixel_info", &ImmVision::ImageParams::ShowPixelInfo, "Show pixel values")
        .def_rw("show_zoom_buttons", &ImmVision::ImageParams::ShowZoomButtons, "Show buttons that enable to zoom in/out (the mouse wheel also zoom)")
        .def_rw("show_options_panel", &ImmVision::ImageParams::ShowOptionsPanel, "Open the options panel")
        .def_rw("show_options_in_tooltip", &ImmVision::ImageParams::ShowOptionsInTooltip, "If set to True, then the option panel will be displayed in a transient tooltip window")
        .def_rw("show_options_button", &ImmVision::ImageParams::ShowOptionsButton, "If set to False, then the Options button will not be displayed")
        .def_rw("watched_pixels", &ImmVision::ImageParams::WatchedPixels, "\n Watched Pixels\n\n List of Watched Pixel coordinates")
        .def_rw("add_watched_pixel_on_double_click", &ImmVision::ImageParams::AddWatchedPixelOnDoubleClick, "Shall we add a watched pixel on double click")
        .def_rw("highlight_watched_pixels", &ImmVision::ImageParams::HighlightWatchedPixels, "Shall the watched pixels be drawn on the image")
        .def_rw("mouse_info", &ImmVision::ImageParams::MouseInfo, "Mouse position information. These values are filled after displaying an image")
        ;
    // #ifdef IMMVISION_SERIALIZE_JSON
    //

    m.def("image_params_to_json",
        ImmVision::ImageParamsToJson, nb::arg("params"));

    m.def("fill_image_params_from_json",
        ImmVision::FillImageParamsFromJson, nb::arg("json"), nb::arg("params"));

    m.def("image_params_from_json",
        ImmVision::ImageParamsFromJson, nb::arg("json"));
    // #endif
    //

    m.def("factor_image_params_display_only",
        ImmVision::FactorImageParamsDisplayOnly, "Create ImageParams that display the image only, with no decoration, and no user interaction");

    m.def("make_zoom_pan_matrix",
        ImmVision::MakeZoomPanMatrix,
        nb::arg("zoom_center"), nb::arg("zoom_ratio"), nb::arg("displayed_image_size"),
        "Create a zoom/pan matrix centered around a given point of interest");

    m.def("make_zoom_pan_matrix_scale_one",
        ImmVision::MakeZoomPanMatrix_ScaleOne, nb::arg("image_size"), nb::arg("displayed_image_size"));

    m.def("make_zoom_pan_matrix_full_view",
        ImmVision::MakeZoomPanMatrix_FullView, nb::arg("image_size"), nb::arg("displayed_image_size"));

    m.def("image",
        ImmVision::Image,
        nb::arg("label"), nb::arg("mat"), nb::arg("params"),
        " Display an image, with full user control: zoom, pan, watch pixels, etc.\n\n :param label\n     A legend that will be displayed.\n     Important notes:\n         - With ImGui and ImmVision, widgets *must* have a unique Ids.\n           For this widget, the id is given by this label.\n           Two widgets (for example) two images *cannot* have the same label or the same id!\n           (you can use ImGui::PushID / ImGui::PopID to circumvent this, or add suffixes with ##)\n\n           If they do, they might not refresh correctly!\n           To circumvent this, you can:\n              - Call `ImGui::PushID(\"some_unique_string\")` at the start of your function,\n                and `ImGui::PopID()` at the end.\n              - Or modify your label like this:\n                  \"MyLabel##some_unique_id\"\n                  (the part after \"##\" will not be displayed but will be part of the id)\n        - To display an empty legend, use \"##_some_unique_id\"\n\n :param mat\n     An image you want to display, under the form of an OpenCV matrix. All types of dense matrices are supported.\n\n :param params\n     Complete options (as modifiable inputs), and outputs (mouse position, watched pixels, etc)\n     @see ImageParams structure.\n     The ImageParams may be modified by this function: you can extract from them\n     the mouse position, watched pixels, etc.\n     Important note:\n         ImageParams is an input-output parameter, passed as a pointer.\n         Its scope should be wide enough so that it is preserved from frame to frame.\n         !! If you cannot zoom/pan in a displayed image, extend the scope of the ImageParams !!\n\n - This function requires that both imgui and OpenGL were initialized.\n   (for example, use `imgui_runner.run`for Python,  or `HelloImGui::Run` for C++)");

    m.def("image_display",
        [](const std::string & label_id, const cv::Mat & mat, const std::optional<const cv::Size> & imageDisplaySize = std::nullopt, bool refreshImage = false, bool showOptionsButton = false) -> cv::Point2d
        {
            auto ImageDisplay_adapt_mutable_param_with_default_value = [](const std::string & label_id, const cv::Mat & mat, const std::optional<const cv::Size> & imageDisplaySize = std::nullopt, bool refreshImage = false, bool showOptionsButton = false) -> cv::Point2d
            {

                const cv::Size& imageDisplaySize_or_default = [&]() -> const cv::Size {
                    if (imageDisplaySize.has_value())
                        return imageDisplaySize.value();
                    else
                        return cv::Size();
                }();

                auto lambda_result = ImmVision::ImageDisplay(label_id, mat, imageDisplaySize_or_default, refreshImage, showOptionsButton);
                return lambda_result;
            };

            return ImageDisplay_adapt_mutable_param_with_default_value(label_id, mat, imageDisplaySize, refreshImage, showOptionsButton);
        },
        nb::arg("label_id"), nb::arg("mat"), nb::arg("image_display_size") = nb::none(), nb::arg("refresh_image") = false, nb::arg("show_options_button") = false,
        " ImageDisplay: Only, display the image, with no user interaction (by default)\n\n Parameters:\n :param label_id\n     A legend that will be displayed.\n     Important notes:\n         - With ImGui and ImmVision, widgets must have a unique Ids. For this widget, the id is given by this label.\n           Two widgets (for example) two images *cannot* have the same label or the same id!\n           If they do, they might not refresh correctly!\n           To circumvent this, you can modify your label like this:\n              \"MyLabel##some_unique_id\"    (the part after \"##\" will not be displayed but will be part of the id)\n        - To display an empty legend, use \"##_some_unique_id\"\n        - if your legend is displayed (i.e. it does not start with \"##\"),\n          then the total size of the widget will be larger than the imageDisplaySize.\n\n :param mat:\n     An image you want to display, under the form of an OpenCV matrix. All types of dense matrices are supported.\n\n :param imageDisplaySize:\n     Size of the displayed image (can be different from the mat size)\n     If you specify only the width or height (e.g (300, 0), then the other dimension\n     will be calculated automatically, respecting the original image w/h ratio.\n\n :param refreshImage:\n     images textures are cached. Set to True if your image matrix/buffer has changed\n     (for example, for live video images)\n\n :param showOptionsButton:\n     If True, show an option button that opens the option panel.\n     In that case, it also becomes possible to zoom & pan, add watched pixel by double-clicking, etc.\n\n :param isBgrOrBgra:\n     set to True if the color order of the image is BGR or BGRA (as in OpenCV)\n.    Breaking change, oct 2024: the default is BGR for C++, RGB for Python!\n\n :return:\n      The mouse position in `mat` original image coordinates, as double values.\n      (i.e. it does not matter if imageDisplaySize is different from mat.size())\n      It will return (-1., -1.) if the mouse is not hovering the image.\n\n      Note: use ImGui::IsMouseDown(mouse_button) (C++) or imgui.is_mouse_down(mouse_button) (Python)\n            to query more information about the mouse.\n\n Note: this function requires that both imgui and OpenGL were initialized.\n       (for example, use `imgui_runner.run`for Python,  or `HelloImGui::Run` for C++)\n\n---\nPython bindings defaults:\n    If imageDisplaySize is None, then its default value will be: cv.Size()");

    m.def("image_display_resizable",
        ImmVision::ImageDisplayResizable,
        nb::arg("label_id"), nb::arg("mat"), nb::arg("size") = nb::none(), nb::arg("refresh_image") = false, nb::arg("resizable") = true, nb::arg("show_options_button") = false,
        " ImageDisplayResizable: display the image, with no user interaction (by default)\n The image can be resized by the user (and the new size will be stored in the size parameter, if provided)\n The label will not be displayed (but it will be used as an id, and must be unique)");

    m.def("available_colormaps",
        ImmVision::AvailableColormaps, " Return the list of the available color maps\n Taken from https://github.com/yuki-koyama/tinycolormap, thanks to Yuki Koyama");

    m.def("clear_texture_cache",
        ImmVision::ClearTextureCache, " Clears the internal texture cache of immvision (this is done automatically at exit time)\n\n Note: this function requires that both imgui and OpenGL were initialized.\n       (for example, use `imgui_runner.run`for Python,  or `HelloImGui::Run` for C++)");

    m.def("get_cached_rgba_image",
        ImmVision::GetCachedRgbaImage,
        nb::arg("label"),
        " Returns the RGBA image currently displayed by ImmVision::Image or ImmVision::ImageDisplay\n Note: this image must be currently displayed. This function will return the transformed image\n (i.e with ColorMap, Zoom, etc.)");

    m.def("version_info",
        ImmVision::VersionInfo, "Return immvision version info");


    m.def("inspector_add_image",
        [](const cv::Mat & image, const std::string & legend, const std::string & zoomKey = "", const std::string & colormapKey = "", const std::optional<const cv::Point2d> & zoomCenter = std::nullopt, double zoomRatio = -1.)
        {
            auto Inspector_AddImage_adapt_mutable_param_with_default_value = [](const cv::Mat & image, const std::string & legend, const std::string & zoomKey = "", const std::string & colormapKey = "", const std::optional<const cv::Point2d> & zoomCenter = std::nullopt, double zoomRatio = -1.)
            {

                const cv::Point2d& zoomCenter_or_default = [&]() -> const cv::Point2d {
                    if (zoomCenter.has_value())
                        return zoomCenter.value();
                    else
                        return cv::Point2d();
                }();

                ImmVision::Inspector_AddImage(image, legend, zoomKey, colormapKey, zoomCenter_or_default, zoomRatio);
            };

            Inspector_AddImage_adapt_mutable_param_with_default_value(image, legend, zoomKey, colormapKey, zoomCenter, zoomRatio);
        },
        nb::arg("image"), nb::arg("legend"), nb::arg("zoom_key") = "", nb::arg("colormap_key") = "", nb::arg("zoom_center") = nb::none(), nb::arg("zoom_ratio") = -1.,
        "---\nPython bindings defaults:\n    If zoomCenter is None, then its default value will be: cv.Point2()");

    m.def("inspector_show",
        ImmVision::Inspector_Show);

    m.def("inspector_clear_images",
        ImmVision::Inspector_ClearImages);


    auto pyClassGlTexture =
        nb::class_<ImmVision::GlTexture>
            (m, "GlTexture", "GlTexture contains an OpenGL texture which can be created or updated from a cv::Mat (C++), or numpy array (Python)")
        .def(nb::init<>(),
            "Create an empty texture")
        .def(nb::init<const cv::Mat &, bool>(),
            nb::arg("image"), nb::arg("is_color_order_bgr") = false,
            " Create a texture from an image (cv::Mat in C++, numpy array in Python)\n isColorOrderBGR: if True, the image is assumed to be in BGR order (OpenCV default)")
        .def("update_from_image",
            &ImmVision::GlTexture::UpdateFromImage,
            nb::arg("image"), nb::arg("is_color_order_bgr") = false,
            " Update the texture from a new image (cv::Mat in C++, numpy array in Python).\n(private API)")
        .def("size_im_vec2",
            &ImmVision::GlTexture::SizeImVec2, " Returns the size as ImVec2\n(private API)")
        .def_rw("texture_id", &ImmVision::GlTexture::TextureId, "OpenGL texture ID on the GPU")
        .def_rw("size", &ImmVision::GlTexture::Size, "Image size in pixels")
        ;
    ////////////////////    </generated_from:immvision.h>    ////////////////////


    ////////////////////    <generated_from:cv_drawing_utils.h>    ////////////////////

    { // <namespace CvDrawingUtils>
        nb::module_ pyNsCvDrawingUtils = m.def_submodule("cv_drawing_utils", "namespace CvDrawingUtils");
        auto pyEnumColors =
            nb::enum_<ImmVision::CvDrawingUtils::Colors>(pyNsCvDrawingUtils, "Colors", nb::is_arithmetic(), "")
                .value("black", ImmVision::CvDrawingUtils::Colors::Black, "")
                .value("red", ImmVision::CvDrawingUtils::Colors::Red, "")
                .value("green", ImmVision::CvDrawingUtils::Colors::Green, "")
                .value("blue", ImmVision::CvDrawingUtils::Colors::Blue, "")
                .value("white", ImmVision::CvDrawingUtils::Colors::White, "")
                .value("yellow", ImmVision::CvDrawingUtils::Colors::Yellow, "")
                .value("cyan", ImmVision::CvDrawingUtils::Colors::Cyan, "")
                .value("violet", ImmVision::CvDrawingUtils::Colors::Violet, "")
                .value("orange", ImmVision::CvDrawingUtils::Colors::Orange, "");


        pyNsCvDrawingUtils.def("colors_to_scalar",
            ImmVision::CvDrawingUtils::ColorsToScalar,
            nb::arg("value"),
            "(private API)");

        pyNsCvDrawingUtils.def("black",
            ImmVision::CvDrawingUtils::Black, "(private API)");

        pyNsCvDrawingUtils.def("red",
            ImmVision::CvDrawingUtils::Red, "(private API)");

        pyNsCvDrawingUtils.def("green",
            ImmVision::CvDrawingUtils::Green, "(private API)");

        pyNsCvDrawingUtils.def("blue",
            ImmVision::CvDrawingUtils::Blue, "(private API)");

        pyNsCvDrawingUtils.def("white",
            ImmVision::CvDrawingUtils::White, "(private API)");

        pyNsCvDrawingUtils.def("yellow",
            ImmVision::CvDrawingUtils::Yellow, "(private API)");

        pyNsCvDrawingUtils.def("cyan",
            ImmVision::CvDrawingUtils::Cyan, "(private API)");

        pyNsCvDrawingUtils.def("violet",
            ImmVision::CvDrawingUtils::Violet, "(private API)");

        pyNsCvDrawingUtils.def("orange",
            ImmVision::CvDrawingUtils::Orange, "(private API)");

        pyNsCvDrawingUtils.def("line",
            ImmVision::CvDrawingUtils::line,
            nb::arg("image"), nb::arg("a"), nb::arg("b"), nb::arg("color"), nb::arg("thickness") = 1,
            "(private API)");

        pyNsCvDrawingUtils.def("ellipse",
            ImmVision::CvDrawingUtils::ellipse,
            nb::arg("image"), nb::arg("center"), nb::arg("size"), nb::arg("color"), nb::arg("angle") = 0., nb::arg("start_angle") = 0., nb::arg("end_angle") = 360., nb::arg("thickness") = 1,
            "(private API)");

        pyNsCvDrawingUtils.def("circle",
            ImmVision::CvDrawingUtils::circle,
            nb::arg("image"), nb::arg("center"), nb::arg("radius"), nb::arg("color"), nb::arg("thickness") = 1,
            "(private API)");

        pyNsCvDrawingUtils.def("rectangle",
            ImmVision::CvDrawingUtils::rectangle,
            nb::arg("image"), nb::arg("pt1"), nb::arg("pt2"), nb::arg("color"), nb::arg("fill") = false, nb::arg("thickness") = 1,
            "(private API)");

        pyNsCvDrawingUtils.def("rectangle_size",
            ImmVision::CvDrawingUtils::rectangle_size,
            nb::arg("img"), nb::arg("pt"), nb::arg("size"), nb::arg("color"), nb::arg("fill") = false, nb::arg("thickness") = 1,
            "(private API)");

        pyNsCvDrawingUtils.def("text",
            ImmVision::CvDrawingUtils::text,
            nb::arg("img"), nb::arg("position"), nb::arg("msg"), nb::arg("color"), nb::arg("center_around_point") = false, nb::arg("add_cartouche") = false, nb::arg("font_scale") = 0.4, nb::arg("thickness") = 1,
            "(private API)");

        pyNsCvDrawingUtils.def("cross_hole",
            ImmVision::CvDrawingUtils::cross_hole,
            nb::arg("img"), nb::arg("position"), nb::arg("color"), nb::arg("size") = 2., nb::arg("size_hole") = 2., nb::arg("thickness") = 1,
            "(private API)");

        pyNsCvDrawingUtils.def("draw_named_feature",
            ImmVision::CvDrawingUtils::draw_named_feature,
            nb::arg("img"), nb::arg("position"), nb::arg("name"), nb::arg("color"), nb::arg("add_cartouche") = false, nb::arg("size") = 3., nb::arg("size_hole") = 2., nb::arg("thickness") = 1, nb::arg("font_scale") = 0.4,
            "(private API)");

        pyNsCvDrawingUtils.def("draw_transparent_pixel",
            ImmVision::CvDrawingUtils::draw_transparent_pixel,
            nb::arg("img_rgba"), nb::arg("position"), nb::arg("color"), nb::arg("alpha"),
            "(private API)");

        pyNsCvDrawingUtils.def("draw_grid",
            ImmVision::CvDrawingUtils::draw_grid,
            nb::arg("img_rgba"), nb::arg("line_color"), nb::arg("alpha"), nb::arg("x_spacing"), nb::arg("y_spacing"), nb::arg("x_start"), nb::arg("y_start"), nb::arg("x_end"), nb::arg("y_end"),
            "(private API)");

        pyNsCvDrawingUtils.def("stack_images_vertically",
            ImmVision::CvDrawingUtils::stack_images_vertically,
            nb::arg("img1"), nb::arg("img2"),
            "(private API)");

        pyNsCvDrawingUtils.def("stack_images_horizontally",
            ImmVision::CvDrawingUtils::stack_images_horizontally,
            nb::arg("img1"), nb::arg("img2"),
            "(private API)");

        pyNsCvDrawingUtils.def("make_alpha_channel_checkerboard_image",
            ImmVision::CvDrawingUtils::make_alpha_channel_checkerboard_image,
            nb::arg("size"), nb::arg("square_size") = 30,
            "(private API)");

        pyNsCvDrawingUtils.def("overlay_alpha_image_precise",
            ImmVision::CvDrawingUtils::overlay_alpha_image_precise,
            nb::arg("background_rgb_or_rgba"), nb::arg("overlay_rgba"), nb::arg("alpha"),
            "(private API)");

        pyNsCvDrawingUtils.def("converted_to_rgba_image",
            ImmVision::CvDrawingUtils::converted_to_rgba_image,
            nb::arg("input_mat"), nb::arg("is_bgr_order"),
            "(private API)");
    } // </namespace CvDrawingUtils>
    ////////////////////    </generated_from:cv_drawing_utils.h>    ////////////////////

    // </litgen_pydef> // Autogenerated code end
    // !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!  AUTOGENERATED CODE END !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
}

#endif // #else / #ifndef IMGUI_BUNDLE_WITH_IMMVISION
