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
 * Qui trasformo la sfera di punti che ho trovato in una semisfera, ho bisogno quindi di una funzione
 * che prenda la sfera e la trasformi in una semisfera, poi dato un tale valore di rotazione del piano
 * permetta di far ruotare questi punti per poterli far coincidere con la normale di ogni triangolo
 */




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


}
}

