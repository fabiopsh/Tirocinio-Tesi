#include "ambient_oc/ambientoc.h"
#include "CINOLIB/include/cinolib/meshes/drawable_trimesh.h"
#include "CINOLIB/include/cinolib/gl/glcanvas.h"
#include "CINOLIB/include/cinolib/meshes/meshes.h"
#include "CINOLIB/include/cinolib/gl/surface_mesh_controls.h"

int main()
{
    using namespace cinolib;
    //Carico la Mesh
    DrawableTrimesh<> m("/Users/fabiopsh/Documents/Universita/Tirocinio/Algoritmo_Test/mesh/triangolo.obj");
    GLcanvas gui;
    //La inserisco nell'interfaccia
    gui.push(&m);
    //Applico l'algoritmo di ambient occlusion
    ambient_occlusion_psh(m);
    //Aggiorno la mesh
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