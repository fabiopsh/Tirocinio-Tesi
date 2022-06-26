#include "ambientoc.h"
#include "/Users/fabiopsh/Documents/Universita/Tirocinio/Algoritmo_Test/CINOLIB/include/cinolib/gl/gl_glfw.h"
#include "/Users/fabiopsh/Documents/Universita/Tirocinio/Algoritmo_Test/CINOLIB/include/cinolib/gl/glproject.h"
#include "/Users/fabiopsh/Documents/Universita/Tirocinio/Algoritmo_Test/CINOLIB/include/cinolib/gl/glunproject.h"
#include "/Users/fabiopsh/Documents/Universita/Tirocinio/Algoritmo_Test/CINOLIB/include/cinolib/sphere_coverage.h"
#include "/Users/fabiopsh/Documents/Universita/Tirocinio/Algoritmo_Test/CINOLIB/include/cinolib/meshes/meshes.h"
#include "/Users/fabiopsh/Documents/Universita/Tirocinio/Algoritmo_Test/CINOLIB/include/cinolib/parallel_for.h"
#include "/Users/fabiopsh/Documents/Universita/Tirocinio/Algoritmo_Test/CINOLIB/include/cinolib/gl/offline_gl_context.h"

/**
 * L'obiettivo di questo algoritmo è poter calcolare l'ambient occlusion a partire da al singolo 
 * poligono e calcolare tramite un raggio che parte dal centroide un valore che ci indica
 * da quanti altri poligoni è coperto il poligono preso in considerazione e in base a questo dato 
 * applicare l'occlusione ambientale adeguata.
 * 
 * E' importante notare che dal centroide partiranno tanti raggi quanti sono i punti nella semisfera 
 * coincidente con la norma dalla quale proviene della luce e quindi sarà necessario
 * memorizzare per ogni triangolo del raycast in quelle direzioni.
 * 
 * Per la semisfera invece basterà crearne una sola e farla ruotare per farla coincidere con il poligono
 * nella direzione giusta, in modo da non dover creare tante semisfere quanti sono i poligoni.
 * 
 */


namespace cinolib
{

template<class Mesh>
CINO_INLINE
void ambient_occlusion_psh(      Mesh & m,
                                  const int    buffer_size,
                                  const uint   sample_dirs)
{
    //Inizializzo le variabili necessarie per l'algoritmo
    std::vector<float> ao(m.num_polys(),0);
    std::vector<vec3d> dirs;
    sphere_coverage(sample_dirs, dirs);

    //Controllo che sia possibile istanziare un ambiente OPENGL
    GLFWwindow* GL_context = create_offline_GL_context(buffer_size, buffer_size);
    if(GL_context==NULL)
    {
        std::cerr << "Impossible to create a GL context. Make sure GLFW has been initialized" << std::endl;
        return;
    }

    //Inizializzo varie funzioni GL
    glfwMakeContextCurrent(GL_context);
    glEnable(GL_DEPTH_TEST);
    glMatrixMode(GL_PROJECTION);
    glPushMatrix();
    glLoadIdentity();
    glViewport(0,0,buffer_size,buffer_size);

    //Per ogni direzione trovata eseguo l'algoritmo, quindi lavorando su ogni singolo poligono
    for(vec3d dir : dirs){


    }

}
}

