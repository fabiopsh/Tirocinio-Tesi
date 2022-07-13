#ifndef CINO_AMBIENT_OCCLUSION_H
#define CINO_AMBIENT_OCCLUSION_H

#ifdef CINOLIB_USES_OPENGL_GLFW_IMGUI

#include "/Users/fabiopsh/Documents/Universita/Tirocinio/Algoritmo_Test/CINOLIB/include/cinolib/cino_inline.h"
#include "sys/types.h"

namespace cinolib
{
template<class Mesh>
CINO_INLINE
void ambient_occlusion_psh(      Mesh & m,
                                  const uint   sample_dirs = 32);

}

#ifndef  CINO_STATIC_LIB
#include "ambientoc.cpp"
#endif

#endif // CINOLIB_USES_OPENGL_GLFW_IMGUI
#endif // CINO_AMBIENT_OCCLUSION_H