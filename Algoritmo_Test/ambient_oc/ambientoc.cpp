#include "ambientoc.h"
#include "/Users/fabiopsh/Documents/Universita/Tirocinio/Algoritmo_Test/CINOLIB/include/cinolib/gl/gl_glfw.h"
#include "/Users/fabiopsh/Documents/Universita/Tirocinio/Algoritmo_Test/CINOLIB/include/cinolib/gl/glproject.h"
#include "/Users/fabiopsh/Documents/Universita/Tirocinio/Algoritmo_Test/CINOLIB/include/cinolib/gl/glunproject.h"
#include "/Users/fabiopsh/Documents/Universita/Tirocinio/Algoritmo_Test/CINOLIB/include/cinolib/sphere_coverage.h"
#include "/Users/fabiopsh/Documents/Universita/Tirocinio/Algoritmo_Test/CINOLIB/include/cinolib/meshes/meshes.h"
#include "/Users/fabiopsh/Documents/Universita/Tirocinio/Algoritmo_Test/CINOLIB/include/cinolib/parallel_for.h"
#include "/Users/fabiopsh/Documents/Universita/Tirocinio/Algoritmo_Test/CINOLIB/include/cinolib/gl/offline_gl_context.h"
#include <math.h>
#include <stdio.h>

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
    /**
     * Inizializzo tutte le variabili utili per l'algoritmo
     * (ne mancano alcune)
     */
    std::vector<float> ao(m.num_polys(),0);
    std::vector<vec3d> dirs;
    sphere_coverage(sample_dirs, dirs);

    /**Controllo che sia possibile istanziare un ambiente OPENGL
     * Se non è possibile mando un messaggio di errore, se è possibile
     * inizializzo tutte le varie funzioni di OpenGL
     */
    GLFWwindow* GL_context = create_offline_GL_context(buffer_size, buffer_size);
    if(GL_context==NULL)
    {
        std::cerr << "Impossible to create a GL context. Make sure GLFW has been initialized" << std::endl;
        return;
    }
    glfwMakeContextCurrent(GL_context);
    glEnable(GL_DEPTH_TEST);
    glMatrixMode(GL_PROJECTION);
    glPushMatrix();
    glLoadIdentity();
    glViewport(0,0,buffer_size,buffer_size);

    /**
     * Qui trasformo la sfera di punti che ho trovato in una semisfera filtrando tutti
     * i punti che si trovano sotto il piano coincidente con il triangolo preso in 
     * considerazione, ho bisogno quindi di una funzione che faccia da filtro
     * che prenda la sfera e un piano e restituisca in una semisfera di punti che 
     * poi di fatto è un vettore di direzioni che mi serviranno per ogni triangolo
     */

    for (int id = 0; id < m.num_polys(); id++){
       vec3d normalOfPoly = m.poly_data(id).normal;
       std::vector<vec3d> dirsOfPolys;
       for (vec3d dir : dirs){
        /*
            //Calcolo l'angolo tra i due vettori, la norma del poligono e la dir
            float alpha = acos((normalOfPoly.x() * dir.x() + normalOfPoly.y() * dir.y() + normalOfPoly.z() * dir.z())/(sqrt(pow(normalOfPoly.x(),2) + pow(normalOfPoly.y(),2) + pow(normalOfPoly.z(),2)) * sqrt(pow(dir.x(),2) + pow(dir.y(),2) + pow(dir.z(),2))));
            //Trasformo da radianti a gradi
            alpha = alpha * (180.0/3.141592653589793238463);
*/
            //il dot product ci fa rispasmiare computazione e se è >= 0 l'angolo è <= di 90 gradi
            if (normalOfPoly.dot(dir) >= 0){dirsOfPolys.push_back(dir);}
       }
       //Adesso per ogni direzione devo tracciare una linea dal centro del poly e vedere se ha collisione
       for (vec3d dir : dirsOfPolys){
            if(!m.poly_data(id).flags[HIDDEN]){
                    
            }
       }
    }




    /**
     * Qui per ogni triangolo della mesh faccio scorrere e mando un raggio dal centro del triangolo
     * verso tutti i punti della semisfera che ho.
     */



    /**
     * Qui per ogni raggio sparato controllo le collisioni con i triangoli, in base al fatto che trovo 
     * una collisione o no salvo in un buffer il punteggio di occlusione ambientale che devo applicare al triangolo.
     * 
     * Sommo tutti i valori ottenuti da tutti i raggi ottenendo così il punteggio finale.
     */




    /**
     * Qui dopo aver ottenuto il punteggio di ogni triangolo della mesh applico tramite le adeguate funzioni di openGL 
     * l'oc ad ogni triangolo.
     */
    /*
    auto min_max = std::minmax_element(ao.begin(), ao.end());   //Coppia di range di AO
    auto min     = *min_max.first;
    auto max     = *min_max.second;
    //Scorro tutti gli ID del poligono
    for(uint pid=0; pid<m.num_polys(); ++pid)
    {
        m.poly_data(pid).AO = (m.poly_data(pid).flags[HIDDEN]) ? 1.0 : (ao[pid]-min)/max; //Applico l'AO al poligono
    }
    */
    
}
}
/*
float dot_product(vec3d vector_a, vec3d vector_b) {
   float product = 0;
   product = vector_a.x() * vector_b.x() + vector_a.y() * vector_b.y() + vector_a.z() * vector_b.z();
   return product;
}
*/