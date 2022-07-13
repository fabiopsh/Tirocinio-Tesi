#include "ambient_oc/ambientoc.h"
#include "CINOLIB/include/cinolib/meshes/drawable_trimesh.h"
#include "CINOLIB/include/cinolib/gl/glcanvas.h"
#include "CINOLIB/include/cinolib/meshes/meshes.h"
#include "CINOLIB/include/cinolib/gl/surface_mesh_controls.h"
#include "/Users/fabiopsh/Documents/Universita/Tirocinio/Algoritmo_Test/CINOLIB/include/cinolib/ambient_occlusion.h"
#include "CINOLIB/include/cinolib/profiler.h"
int main()
{
    using namespace cinolib;
    DrawableTrimesh<> m("/Users/fabiopsh/Documents/Universita/Tirocinio/Algoritmo_Test/mesh/protein.obj");
    //DrawableTrimesh<> m("/Users/fabiopsh/Documents/Universita/Tirocinio/Algoritmo_Test/mesh/bunny.obj");
    //DrawableQuadmesh<> m("/Users/fabiopsh/Documents/Universita/Tirocinio/Algoritmo_Test/mesh/bamboo_pen.obj");
    GLcanvas gui;
    SurfaceMeshControls<DrawableTrimesh<>> menu(&m, &gui);
    Profiler tempo;
    //SurfaceMeshControls<DrawableQuadmesh<>> menu(&m, &gui);
    gui.push(&m);
    gui.push(&menu);
    tempo.push("Tempo AO: ");
    ambient_occlusion_psh(m);
    tempo.pop();
    m.updateGL();

    gui.callback_app_controls = [&]()
    {
        if(ImGui::SliderFloat("AOPSH", &m.AO_alpha, 0.f, 1.f))
        {
            m.updateGL();
        }
    };
    return gui.launch();
}