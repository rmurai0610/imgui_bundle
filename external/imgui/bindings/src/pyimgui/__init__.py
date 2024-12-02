# Part of ImGui Bundle - MIT License - Copyright (c) 2022-2023 Pascal Thomet - https://github.com/pthom/imgui_bundle
import os
from typing import Union, Tuple, List

__all__ = ["__version__", "compilation_time"]

import pyimgui_ext as imgui
from imgui import (
    ImVec2,
    ImVec4,
    ImColor,
    FLT_MIN,
    FLT_MAX,
)  # noqa: F401

ImVec2Like = Union[ImVec2, Tuple[int | float, int | float], List[int | float]]
ImVec4Like = Union[
    ImVec4,
    Tuple[int | float, int | float, int | float, int | float],
    List[int | float],
]

imgui.ImVec2Like = ImVec2Like
imgui.ImVec4Like = ImVec4Like

__all__.extend(
    [
        "imgui",
        "ImVec2",
        "ImVec2Like",
        "ImVec4Like",
        "ImVec4",
        "ImColor",
        "FLT_MIN",
        "FLT_MAX",
        "IM_COL32",
    ]
)

# Patch after imgui v1.90.9, where
# the enum ImGuiDir_ was renamed to ImGuiDir and ImGuiSortDirection_ was renamed to ImGuiSortDirection
# this enables old python to continue to work
imgui.Dir_ = imgui.Dir
imgui.SortDirection_ = imgui.SortDirection
