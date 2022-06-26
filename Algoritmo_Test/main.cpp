#include "ambient_oc/ambientoc.h"
#include "CINOLIB/include/cinolib/meshes/drawable_trimesh.h"
#include "CINOLIB/include/cinolib/gl/glcanvas.h"
#include "CINOLIB/include/cinolib/meshes/meshes.h"
#include "CINOLIB/include/cinolib/gl/surface_mesh_controls.h"

int main()
{
    using namespace cinolib;
    DrawableTrimesh<> m("mesh/triangolo.obj");
    GLcanvas gui;
    gui.push(&m);
    return gui.launch();
}