"""ImGuizmo: Immediate mode 3D gizmo for scene editing and other controls based on Dear Imgui
https://github.com/CedricGuillemet/ImGuizmo
"""
# ruff: noqa: F821
from typing import List, Optional, Any, overload
from imgui_bundle.imgui import ImVec2, ImVec4
from imgui_bundle.imgui.internal import ImRect
import enum
import numpy as np

from imgui_bundle.imgui import ImU32, ImDrawList

ImGuiContext = Any

ImGuiZoomSliderFlags = int
ImGuiZoomSliderFlags_None = im_zoom_slider.ImGuiZoomSliderFlags_.none  # noqa

Matrix16 = np.ndarray  # np.type=float, shape=[4, 4]
Matrix6 = np.ndarray  # np.type=float, shape=[6]
Matrix3 = np.ndarray  # np.type=float, shape=[3]

SelectedPoints = List[im_curve_edit.EditPoint]

# fmt: off
# !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!  AUTOGENERATED CODE !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
# <litgen_stub> // Autogenerated code below! Do not edit!
####################    <generated_from:Editable.h>    ####################
#
# Several utilities to help the use of the Immediate Gui paradigm in the context of pure functions
# (i.e. one input, one output, no modifiable parameter)
#


#  ------------------------------------------------------------------------
#      <template specializations for class Editable>
class Editable_SelectedPoints:  # Python specialization for Editable<SelectedPoints>
    """ Editable: a simple structure to extend ImGui's policy of "returning True when changed",
     by adding with a modified return value to the functions output
    """
    def __init__(self, value: SelectedPoints, edited: bool = False) -> None:
        pass

    def __bool__(self) -> bool:
        """ Invoke this operator to check for user modification"""
        pass

    # (this version is adapted for relatively lightweight objects, since it does copy the values.
    #  however, anything less than 1KB should be OK, since copying 1KB per frame at 200FPS should be
    #  unnoticeable)
    value: SelectedPoints
    edited: bool = False


class Editable_int:  # Python specialization for Editable<int>
    """ Editable: a simple structure to extend ImGui's policy of "returning True when changed",
     by adding with a modified return value to the functions output
    """
    def __init__(self, value: int, edited: bool = False) -> None:
        pass

    def __bool__(self) -> bool:
        """ Invoke this operator to check for user modification"""
        pass

    # (this version is adapted for relatively lightweight objects, since it does copy the values.
    #  however, anything less than 1KB should be OK, since copying 1KB per frame at 200FPS should be
    #  unnoticeable)
    value: int
    edited: bool = False


class Editable_Matrix16:  # Python specialization for Editable<Matrix16>
    """ Editable: a simple structure to extend ImGui's policy of "returning True when changed",
     by adding with a modified return value to the functions output
    """
    def __init__(self, value: Matrix16, edited: bool = False) -> None:
        pass

    def __bool__(self) -> bool:
        """ Invoke this operator to check for user modification"""
        pass

    # (this version is adapted for relatively lightweight objects, since it does copy the values.
    #  however, anything less than 1KB should be OK, since copying 1KB per frame at 200FPS should be
    #  unnoticeable)
    value: Matrix16
    edited: bool = False


class Editable_Range:  # Python specialization for Editable<Range>
    """ Editable: a simple structure to extend ImGui's policy of "returning True when changed",
     by adding with a modified return value to the functions output
    """
    def __init__(self, value: Range, edited: bool = False) -> None:
        pass

    def __bool__(self) -> bool:
        """ Invoke this operator to check for user modification"""
        pass

    # (this version is adapted for relatively lightweight objects, since it does copy the values.
    #  however, anything less than 1KB should be OK, since copying 1KB per frame at 200FPS should be
    #  unnoticeable)
    value: Range
    edited: bool = False
#      </template specializations for class Editable>
#  ------------------------------------------------------------------------
####################    </generated_from:Editable.h>    ####################


####################    <generated_from:ImCurveEditPure.h>    ####################
# THIS FILE WAS GENERATED AUTOMATICALLY. DO NOT EDIT.

#////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#                       ImGuizmoPure/ImCurveEditPure.h                                                         //
#//////////////////////////////////////////////////////////////////////////////////////////////////////////////
# Part of ImGui Bundle - MIT License - Copyright (c) 2022-2024 Pascal Thomet - https://github.com/pthom/imgui_bundle

#////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#                       ImGuizmo/ImCurveEdit.h included by ImGuizmoPure/ImCurveEditPure.h                      //
#//////////////////////////////////////////////////////////////////////////////////////////////////////////////
# https://github.com/CedricGuillemet/ImGuizmo
# v 1.89 WIP
#
# The MIT License(MIT)
#
# Copyright(c) 2021 Cedric Guillemet
#
# Permission is hereby granted, free of charge, to any person obtaining a copy
# of this software and associated documentation files(the "Software"), to deal
# in the Software without restriction, including without limitation the rights
# to use, copy, modify, merge, publish, distribute, sublicense, and / or sell
# copies of the Software, and to permit persons to whom the Software is
# furnished to do so, subject to the following conditions :
#
# The above copyright notice and this permission notice shall be included in all
# copies or substantial portions of the Software.
#
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
# IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
# FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.IN NO EVENT SHALL THE
# AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
# LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
# OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
# SOFTWARE.
#



#////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#                       ImGuizmoPure/Editable.h included by ImGuizmoPure/ImCurveEditPure.h                     //
#//////////////////////////////////////////////////////////////////////////////////////////////////////////////
# Part of ImGui Bundle - MIT License - Copyright (c) 2022-2024 Pascal Thomet - https://github.com/pthom/imgui_bundle
#
# Several utilities to help the use of the Immediate Gui paradigm in the context of pure functions
# (i.e. one input, one output, no modifiable parameter)
#



#////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#                       ImGuizmoPure/ImCurveEditPure.h continued                                               //
#//////////////////////////////////////////////////////////////////////////////////////////////////////////////




# <submodule im_curve_edit>
class im_curve_edit:  # Proxy class that introduces typings for the *submodule* im_curve_edit
    pass  # (This corresponds to a C++ namespace. All method are static!)
    class CurveType(enum.Enum):
        curve_none = enum.auto()     # (= 0)
        curve_discrete = enum.auto() # (= 1)
        curve_linear = enum.auto()   # (= 2)
        curve_smooth = enum.auto()   # (= 3)
        curve_bezier = enum.auto()   # (= 4)

    class EditPoint:
        curve_index: int
        point_index: int
        def __lt__(self, other: ImCurveEdit.EditPoint) -> bool:
            pass
        def __init__(self) -> None:
            """Autogenerated default constructor"""
            pass

    class Delegate:
        focused: bool = False
        def get_curve_count(self) -> int:                    # overridable (pure virtual)
            pass
        def is_visible(self, param_0: int) -> bool:          # overridable
            pass
        def get_curve_type(self, param_0: int) -> CurveType: # overridable
            pass
        def get_min(self) -> ImVec2:                         # overridable (pure virtual)
            pass
        def get_max(self) -> ImVec2:                         # overridable (pure virtual)
            pass
        def get_curve_color(                                 # overridable (pure virtual)
            self,
            curve_index: int
            ) -> int:
            pass
        def edit_point(                                      # overridable (pure virtual)
            self,
            curve_index: int,
            point_index: int,
            value: ImVec2
            ) -> int:
            pass
        def add_point(                                       # overridable (pure virtual)
            self,
            curve_index: int,
            value: ImVec2
            ) -> None:
            pass
        def get_background_color(self) -> int:               # overridable
            pass
        # handle undo/redo thru this functions
        def begin_edit(self, param_0: int) -> None:          # overridable
            pass
        def end_edit(self) -> None:                          # overridable
            pass

        def __init__(self) -> None:
            """Autogenerated default constructor"""
            pass

    class DelegatePure(ImCurveEdit.Delegate):

        def get_points_list( # overridable (pure virtual)
            self,
            curve_index: int
            ) -> List[ImVec2]:
            pass

        def __init__(self) -> None:
            """Autogenerated default constructor"""
            pass


    @staticmethod
    def edit_pure(
        delegate: DelegatePure,
        size: ImVec2,
        id: int,
        clipping_rect: Optional[ImRect] = None
        ) -> EditableSelectedPoints:
        pass

# </submodule im_curve_edit>
####################    </generated_from:ImCurveEditPure.h>    ####################


####################    <generated_from:ImGradientPure.h>    ####################
# THIS FILE WAS GENERATED AUTOMATICALLY. DO NOT EDIT.





#////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#                       ImGuizmoPure/Editable.h included by ImGuizmoPure/ImGradientPure.h                      //
#//////////////////////////////////////////////////////////////////////////////////////////////////////////////
# Part of ImGui Bundle - MIT License - Copyright (c) 2022-2024 Pascal Thomet - https://github.com/pthom/imgui_bundle
#
# Several utilities to help the use of the Immediate Gui paradigm in the context of pure functions
# (i.e. one input, one output, no modifiable parameter)
#




#////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#                       ImGuizmoPure/ImGradientPure.h continued                                                //
#//////////////////////////////////////////////////////////////////////////////////////////////////////////////



# <submodule im_gradient>
class im_gradient:  # Proxy class that introduces typings for the *submodule* im_gradient
    pass  # (This corresponds to a C++ namespace. All method are static!)
    class Delegate:
        def edit_point(                             # overridable (pure virtual)
            self,
            point_index: int,
            value: ImVec4
            ) -> int:
            pass
        def get_point(self, t: float) -> ImVec4:    # overridable (pure virtual)
            pass
        def add_point(self, value: ImVec4) -> None: # overridable (pure virtual)
            pass
        def __init__(self) -> None:
            """Autogenerated default constructor"""
            pass

    class DelegateStl(ImGradient.Delegate):

        def get_points_list(self) -> List[ImVec4]: # overridable (pure virtual)
            pass

        def __init__(self) -> None:
            """Autogenerated default constructor"""
            pass

    @staticmethod
    def edit_pure(delegate: DelegateStl, size: ImVec2) -> EditableInt:
        pass

# </submodule im_gradient>
####################    </generated_from:ImGradientPure.h>    ####################


####################    <generated_from:ImZoomSliderPure.h>    ####################
# THIS FILE WAS GENERATED AUTOMATICALLY. DO NOT EDIT.

#////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#                       ImGuizmoPure/ImZoomSliderPure.h                                                        //
#//////////////////////////////////////////////////////////////////////////////////////////////////////////////
# Part of ImGui Bundle - MIT License - Copyright (c) 2022-2024 Pascal Thomet - https://github.com/pthom/imgui_bundle

#////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#                       ImGuizmo/ImZoomSlider.h included by ImGuizmoPure/ImZoomSliderPure.h                    //
#//////////////////////////////////////////////////////////////////////////////////////////////////////////////
# https://github.com/CedricGuillemet/ImGuizmo
# v 1.89 WIP
#
# The MIT License(MIT)
#
# Copyright(c) 2021 Cedric Guillemet
#
# Permission is hereby granted, free of charge, to any person obtaining a copy
# of this software and associated documentation files(the "Software"), to deal
# in the Software without restriction, including without limitation the rights
# to use, copy, modify, merge, publish, distribute, sublicense, and / or sell
# copies of the Software, and to permit persons to whom the Software is
# furnished to do so, subject to the following conditions :
#
# The above copyright notice and this permission notice shall be included in all
# copies or substantial portions of the Software.
#
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
# IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
# FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.IN NO EVENT SHALL THE
# AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
# LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
# OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
# SOFTWARE.
#


#////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#                       ImGuizmoPure/Editable.h included by ImGuizmoPure/ImZoomSliderPure.h                    //
#//////////////////////////////////////////////////////////////////////////////////////////////////////////////
# Part of ImGui Bundle - MIT License - Copyright (c) 2022-2024 Pascal Thomet - https://github.com/pthom/imgui_bundle
#
# Several utilities to help the use of the Immediate Gui paradigm in the context of pure functions
# (i.e. one input, one output, no modifiable parameter)
#




#////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#                       ImGuizmoPure/ImZoomSliderPure.h continued                                              //
#//////////////////////////////////////////////////////////////////////////////////////////////////////////////



# <submodule im_zoom_slider>
class im_zoom_slider:  # Proxy class that introduces typings for the *submodule* im_zoom_slider
    pass  # (This corresponds to a C++ namespace. All method are static!)
    """ namespace"""
    class ImGuiZoomSliderFlags_(enum.Enum):
        none = enum.auto()             # (= 0)
        vertical = enum.auto()         # (= 1)
        no_anchors = enum.auto()       # (= 2)
        no_middle_carets = enum.auto() # (= 4)
        no_wheel = enum.auto()         # (= 8)


    class Range:
        min: float
        max: float
        def __init__(self, min: float, max: float) -> None:
            pass
        def center(self) -> float:
            pass
        def length(self) -> float:
            pass

    @staticmethod
    def im_zoom_slider_pure(
        full_range: Range,
        current_range: Range,
        wheel_ratio: float = 0.01,
        flags: ImGuiZoomSliderFlags = ImGuiZoomSliderFlags_None
        ) -> EditableRange:
        pass


# </submodule im_zoom_slider>
####################    </generated_from:ImZoomSliderPure.h>    ####################


####################    <generated_from:ImGuizmoPure.h>    ####################
# THIS FILE WAS GENERATED AUTOMATICALLY. DO NOT EDIT.

#////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#                       ImGuizmoPure/ImGuizmoPure.h                                                            //
#//////////////////////////////////////////////////////////////////////////////////////////////////////////////
# Part of ImGui Bundle - MIT License - Copyright (c) 2022-2024 Pascal Thomet - https://github.com/pthom/imgui_bundle


#////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#                       ImGuizmo/ImGuizmo.h included by ImGuizmoPure/ImGuizmoPure.h                            //
#//////////////////////////////////////////////////////////////////////////////////////////////////////////////
# https://github.com/CedricGuillemet/ImGuizmo
# v 1.89 WIP
#
# The MIT License(MIT)
#
# Copyright(c) 2021 Cedric Guillemet
#
# Permission is hereby granted, free of charge, to any person obtaining a copy
# of this software and associated documentation files(the "Software"), to deal
# in the Software without restriction, including without limitation the rights
# to use, copy, modify, merge, publish, distribute, sublicense, and / or sell
# copies of the Software, and to permit persons to whom the Software is
# furnished to do so, subject to the following conditions :
#
# The above copyright notice and this permission notice shall be included in all
# copies or substantial portions of the Software.
#
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
# IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
# FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.IN NO EVENT SHALL THE
# AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
# LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
# OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
# SOFTWARE.
#
# -------------------------------------------------------------------------------------------
# History :
# 2019/11/03 View gizmo
# 2016/09/11 Behind camera culling. Scaling Delta matrix not multiplied by source matrix scales. local/world rotation and translation fixed. Display message is incorrect (X: ... Y:...) in local mode.
# 2016/09/09 Hatched negative axis. Snapping. Documentation update.
# 2016/09/04 Axis switch and translation plan autohiding. Scale transform stability improved
# 2016/09/01 Mogwai changed to Manipulate. Draw debug cube. Fixed inverted scale. Mixing scale and translation/rotation gives bad results.
# 2016/08/31 First version
#
# -------------------------------------------------------------------------------------------
# Future (no order):
#
# - Multi view
# - display rotation/translation/scale infos in local/world space and not only local
# - finish local/world matrix application
# - OPERATION as bitmask
#
# -------------------------------------------------------------------------------------------
# Example




#////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#                       ImGuizmoPure/Editable.h included by ImGuizmoPure/ImGuizmoPure.h                        //
#//////////////////////////////////////////////////////////////////////////////////////////////////////////////
# Part of ImGui Bundle - MIT License - Copyright (c) 2022-2024 Pascal Thomet - https://github.com/pthom/imgui_bundle
#
# Several utilities to help the use of the Immediate Gui paradigm in the context of pure functions
# (i.e. one input, one output, no modifiable parameter)
#




#////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#                       ImGuizmoPure/ImGuizmoPure.h continued                                                  //
#//////////////////////////////////////////////////////////////////////////////////////////////////////////////






# <submodule im_guizmo>
class im_guizmo:  # Proxy class that introduces typings for the *submodule* im_guizmo
    pass  # (This corresponds to a C++ namespace. All method are static!)
    @staticmethod
    def set_drawlist(drawlist: Optional[ImDrawList] = None) -> None:
        """ call inside your own window and before Manipulate() in order to draw gizmo to that window.
         Or pass a specific ImDrawList to draw to (e.g. ImGui::GetForegroundDrawList()).
        """
        pass

    @staticmethod
    def begin_frame() -> None:
        """ call BeginFrame right after ImGui_XXXX_NewFrame();"""
        pass

    @staticmethod
    def set_im_gui_context(ctx: ImGuiContext) -> None:
        """ this is necessary because when imguizmo is compiled into a dll, and imgui into another
         globals are not shared between them.
         More details at https://stackoverflow.com/questions/19373061/what-happens-to-global-and-static-variables-in-a-shared-library-when-it-is-dynam
         expose method to set imgui context
        """
        pass

    @staticmethod
    @overload
    def is_over() -> bool:
        """ return True if mouse cursor is over any gizmo control (axis, plan or screen component)"""
        pass

    @staticmethod
    def is_using() -> bool:
        """ return True if mouse IsOver or if the gizmo is in moving state"""
        pass

    @staticmethod
    def is_using_any() -> bool:
        """ return True if any gizmo is in moving state"""
        pass

    @staticmethod
    def enable(enable: bool) -> None:
        """ enable/disable the gizmo. Stay in the state until next call to Enable.
         gizmo is rendered with gray half transparent color when disabled
        """
        pass

    # helper functions for manualy editing translation/rotation/scale with an input float
    # translation, rotation and scale float points to 3 floats each
    # Angles are in degrees (more suitable for human editing)
    # example:
    # float matrixTranslation[3], matrixRotation[3], matrixScale[3];
    # ImGuizmo::DecomposeMatrixToComponents(gizmoMatrix.m16, matrixTranslation, matrixRotation, matrixScale);
    # ImGui::InputFloat3("Tr", matrixTranslation, 3);
    # ImGui::InputFloat3("Rt", matrixRotation, 3);
    # ImGui::InputFloat3("Sc", matrixScale, 3);
    # ImGuizmo::RecomposeMatrixFromComponents(matrixTranslation, matrixRotation, matrixScale, gizmoMatrix.m16);
    #
    # These functions have some numerical stability issues for now. Use with caution.

    @staticmethod
    def set_rect(x: float, y: float, width: float, height: float) -> None:
        pass
    @staticmethod
    def set_orthographic(is_orthographic: bool) -> None:
        """ default is False"""
        pass

    # Render a cube with face color corresponding to face normal. Usefull for debug/tests

    class OPERATION(enum.Enum):
        """ call it when you want a gizmo
         Needs view and projection matrices.
         matrix parameter is the source matrix (where will be gizmo be drawn) and might be transformed by the function. Return deltaMatrix is optional
         translation is applied in world space
        """
        translate_x = enum.auto()   # (= (1u << 0))
        translate_y = enum.auto()   # (= (1u << 1))
        translate_z = enum.auto()   # (= (1u << 2))
        rotate_x = enum.auto()      # (= (1u << 3))
        rotate_y = enum.auto()      # (= (1u << 4))
        rotate_z = enum.auto()      # (= (1u << 5))
        rotate_screen = enum.auto() # (= (1u << 6))
        scale_x = enum.auto()       # (= (1u << 7))
        scale_y = enum.auto()       # (= (1u << 8))
        scale_z = enum.auto()       # (= (1u << 9))
        bounds = enum.auto()        # (= (1u << 10))
        scale_xu = enum.auto()      # (= (1u << 11))
        scale_yu = enum.auto()      # (= (1u << 12))
        scale_zu = enum.auto()      # (= (1u << 13))

        translate = enum.auto()     # (= OPERATION.translate_x | OPERATION.translate_y | OPERATION.translate_z)
        rotate = enum.auto()        # (= OPERATION.rotate_x | OPERATION.rotate_y | OPERATION.rotate_z | OPERATION.rotate_screen)
        scale = enum.auto()         # (= OPERATION.scale_x | OPERATION.scale_y | OPERATION.scale_z)
        scaleu = enum.auto()        # (= OPERATION.scale_xu | OPERATION.scale_yu | OPERATION.scale_zu)  # universal
        universal = enum.auto()     # (= OPERATION.translate | OPERATION.rotate | OPERATION.scaleu)


    class MODE(enum.Enum):
        local = enum.auto() # (= 0)
        world = enum.auto() # (= 1)



    @staticmethod
    def set_id(id: int) -> None:
        pass

    # return True if the cursor is over the operation's gizmo
    @staticmethod
    @overload
    def is_over(op: OPERATION) -> bool:
        pass
    @staticmethod
    def set_gizmo_size_clip_space(value: float) -> None:
        pass

    @staticmethod
    def allow_axis_flip(value: bool) -> None:
        """ Allow axis to flip
         When True (default), the guizmo axis flip for better visibility
         When False, they always stay along the positive world/local axis
        """
        pass

    @staticmethod
    def set_axis_limit(value: float) -> None:
        """ Configure the limit where axis are hidden"""
        pass
    @staticmethod
    def set_plane_limit(value: float) -> None:
        """ Configure the limit where planes are hiden"""
        pass

    class COLOR(enum.Enum):
        direction_x = enum.auto()           # (= 0)  # directionColor[0]
        direction_y = enum.auto()           # (= 1)  # directionColor[1]
        direction_z = enum.auto()           # (= 2)  # directionColor[2]
        plane_x = enum.auto()               # (= 3)  # planeColor[0]
        plane_y = enum.auto()               # (= 4)  # planeColor[1]
        plane_z = enum.auto()               # (= 5)  # planeColor[2]
        selection = enum.auto()             # (= 6)  # selectionColor
        inactive = enum.auto()              # (= 7)  # inactiveColor
        translation_line = enum.auto()      # (= 8)  # translationLineColor
        scale_line = enum.auto()            # (= 9)
        rotation_using_border = enum.auto() # (= 10)
        rotation_using_fill = enum.auto()   # (= 11)
        hatched_axis_lines = enum.auto()    # (= 12)
        text = enum.auto()                  # (= 13)
        text_shadow = enum.auto()           # (= 14)
        count = enum.auto()                 # (= 15)

    class Style:
        def __init__(self) -> None:
            pass

        translation_line_thickness: float     # Thickness of lines for translation gizmo
        translation_line_arrow_size: float    # Size of arrow at the end of lines for translation gizmo
        rotation_line_thickness: float        # Thickness of lines for rotation gizmo
        rotation_outer_line_thickness: float  # Thickness of line surrounding the rotation gizmo
        scale_line_thickness: float           # Thickness of lines for scale gizmo
        scale_line_circle_size: float         # Size of circle at the end of lines for scale gizmo
        hatched_axis_line_thickness: float    # Thickness of hatched axis lines
        center_circle_size: float             # Size of circle at the center of the translate/scale gizmo


    @staticmethod
    def get_style() -> Style:
        pass



    class MatrixComponents:
        translation: Matrix3
        rotation: Matrix3
        scale: Matrix3
        def __init__(self) -> None:
            """Autogenerated default constructor"""
            pass

    # helper functions for manualy editing translation/rotation/scale with an input float
    # translation, rotation and scale float points to 3 floats each
    # Angles are in degrees (more suitable for human editing)
    # example:
    # float matrixTranslation[3], matrixRotation[3], matrixScale[3];
    # ImGuizmo::DecomposeMatrixToComponents(gizmoMatrix.m16, matrixTranslation, matrixRotation, matrixScale);
    # ImGui::InputFloat3("Tr", matrixTranslation, 3);
    # ImGui::InputFloat3("Rt", matrixRotation, 3);
    # ImGui::InputFloat3("Sc", matrixScale, 3);
    # ImGuizmo::RecomposeMatrixFromComponents(matrixTranslation, matrixRotation, matrixScale, gizmoMatrix.m16);
    #
    # These functions have some numerical stability issues for now. Use with caution.
    @staticmethod
    def decompose_matrix_to_components(matrix: Matrix16) -> MatrixComponents:
        pass
    @staticmethod
    def recompose_matrix_from_components(
        matrix_components: MatrixComponents
        ) -> Matrix16:
        pass

    # Render a cube with face color corresponding to face normal. Usefull for debug/tests
    @staticmethod
    def draw_cubes(
        view: Matrix16,
        projection: Matrix16,
        matrices: List[Matrix16]
        ) -> None:
        pass
    @staticmethod
    def draw_grid(
        view: Matrix16,
        projection: Matrix16,
        matrix: Matrix16,
        grid_size: float
        ) -> None:
        pass

    @staticmethod
    def manipulate(
        view: Matrix16,
        projection: Matrix16,
        operation: OPERATION,
        mode: MODE,
        object_matrix: Matrix16,
        delta_matrix: Optional[Matrix16] = None,
        snap: Optional[Matrix3] = None,
        local_bounds: Optional[Matrix6] = None,
        bounds_snap: Optional[Matrix3] = None
        ) -> EditableMatrix16:
        """ Manipulate may change the objectMatrix parameter:
         if it was changed, it will return (True, newObjectMatrix)
        """
        pass

    @staticmethod
    @overload
    def view_manipulate(
        view: Matrix16,
        length: float,
        position: ImVec2,
        size: ImVec2,
        background_color: ImU32
        ) -> EditableMatrix16:
        """
         Please note that this cubeview is patented by Autodesk : https://patents.google.com/patent/US7782319B2/en
         It seems to be a defensive patent in the US. I don't think it will bring troubles using it as
         other software are using the same mechanics. But just in case, you are now warned!

         ViewManipulate may change the view parameter: if it was changed, it will return (True, newView)
        """
        pass

    @staticmethod
    @overload
    def view_manipulate(
        view: Matrix16,
        projection: Matrix16,
        operation: OPERATION,
        mode: MODE,
        matrix: Matrix16,
        length: float,
        position: ImVec2,
        size: ImVec2,
        background_color: ImU32
        ) -> EditableMatrix16:
        """ use this version if you did not call Manipulate before and you are just using ViewManipulate
         ViewManipulate may change the view parameter: if it was changed, it will return (True, newView)
        """
        pass

# </submodule im_guizmo>
####################    </generated_from:ImGuizmoPure.h>    ####################

# </litgen_stub> // Autogenerated code end!
