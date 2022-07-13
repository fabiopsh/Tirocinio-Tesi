#include "ambientoc.h"
#include "/Users/fabiopsh/Documents/Universita/Tirocinio/Algoritmo_Test/CINOLIB/include/cinolib/gl/gl_glfw.h"
#include "/Users/fabiopsh/Documents/Universita/Tirocinio/Algoritmo_Test/CINOLIB/include/cinolib/gl/glproject.h"
#include "/Users/fabiopsh/Documents/Universita/Tirocinio/Algoritmo_Test/CINOLIB/include/cinolib/gl/glunproject.h"
#include "/Users/fabiopsh/Documents/Universita/Tirocinio/Algoritmo_Test/CINOLIB/include/cinolib/sphere_coverage.h"
#include "/Users/fabiopsh/Documents/Universita/Tirocinio/Algoritmo_Test/CINOLIB/include/cinolib/meshes/meshes.h"
#include "/Users/fabiopsh/Documents/Universita/Tirocinio/Algoritmo_Test/CINOLIB/include/cinolib/parallel_for.h"
#include "/Users/fabiopsh/Documents/Universita/Tirocinio/Algoritmo_Test/CINOLIB/include/cinolib/gl/offline_gl_context.h"
#include "/Users/fabiopsh/Documents/Universita/Tirocinio/Algoritmo_Test/CINOLIB/include/cinolib/drawable_octree.h"
#include <math.h>
#include <stdio.h>

namespace cinolib
{

template<class Mesh>
CINO_INLINE
void ambient_occlusion_psh(      Mesh & m,
                                  const int    buffer_size,
                                  const uint   sample_dirs)
{
    std::vector<float> ao(m.num_polys(),0);
    std::vector<vec3d> dirs;
    sphere_coverage(sample_dirs, dirs);

    DrawableOctree octree;
    octree.debug_mode(false); // dump times and statistics
    octree.build_from_mesh_polys(m);
    octree.updateGL();


    for (int id = 0; id < m.num_polys(); id++){
       vec3d normalOfPoly = m.poly_data(id).normal;
       std::vector<vec3d> dirsOfPolys;
       for (vec3d dir : dirs){
            if (normalOfPoly.dot(dir) >= 0){dirsOfPolys.push_back(dir);}
       }
       for (vec3d dir : dirsOfPolys){   //Adesso per ogni direzione devo vedere se ha collisione
                std::set<std::pair<double,uint>> hits;
                vec3d  polyCenter = m.poly_centroid(id);
                if(octree.intersects_ray(polyCenter, dir, hits)) //Se trova un poligono
                    {ao[id] += (hits.size()>1) ? 1 : 0;}
       }
        ao[id] = ao[id]/dirsOfPolys.size();
    }
    for(uint pid=0; pid<m.num_polys(); ++pid)       //Scorro tutti gli ID del poligono e Applico AO
    {
        if(ao[pid]!=0){
            m.poly_data(pid).AO = 1 - ao[pid];    //Applico l'AO al poligono se è leggermente nascosto
            std::cout<<"Valore AO del poly: "<<pid<<" Valore: "<<m.poly_data(pid).AO<<" Valore Collisioni: "<<ao[pid]<<std::endl;
        }else {m.poly_data(pid).AO = 1;}                //Se è perfettamente visibile   
    }  
}
}