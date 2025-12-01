# Ambient Occlusion con Cinolib

### Tirocinio e Tesi di Laurea Triennale in Informatica
**Università degli Studi di Cagliari**

| Dettagli | |
| :--- | :--- |
| **Candidato:** | **Fabio Piscitelli** |
| **Relatore:** | **Prof. Marco Livesu** |
| **Anno Accademico:** | 2021 / 2022 |
| **Corso:** | Laurea Triennale in Informatica |

![Badge C++](https://img.shields.io/badge/Language-C++17-blue.svg) ![Badge Cinolib](https://img.shields.io/badge/Library-Cinolib-orange.svg) ![Badge License](https://img.shields.io/badge/License-MIT-green.svg)

---

## 📄 Descrizione del Progetto

Questa repository contiene il codice sorgente sviluppato durante il percorso di **Tirocinio e Tesi** presso l'Università degli Studi di Cagliari.

Il progetto verte sull'implementazione di algoritmi di **Ambient Occlusion (AO)** su mesh poligonali, utilizzando **Cinolib**, una libreria *header-only* per il geometry processing sviluppata presso l'Università di Cagliari e il CNR-IMATI.

L'obiettivo è stato quello di studiare e implementare tecniche per il calcolo dell'occlusione ambientale per migliorare la resa grafica e la percezione della profondità nelle geometrie 3D, analizzando le performance e la qualità visiva dei risultati.

## 🛠 Tecnologie Utilizzate

* **C++:** Linguaggio principale di sviluppo.
* **[Cinolib](https://github.com/mlivesu/cinolib):** Libreria per l'elaborazione di mesh poligonali e poliedriche.
* **OpenGL / GLUI:** Per il rendering grafico e l'interfaccia utente (integrati in Cinolib).
* **Qt Creator / Visual Studio / CMake:** Ambienti di sviluppo e build system.

## 🚀 Funzionalità

* Caricamento di modelli 3D in vari formati supportati da Cinolib (`.obj`, `.off`, `.stl`, ecc.).
* Implementazione dell'algoritmo di **Ambient Occlusion** (specificare qui se Screen-Space o Object-Space/Ray-tracing).
* Visualizzazione della mappa di occlusione sulla superficie della mesh (shading o color-coding).
* Interfaccia per il tuning dei parametri in tempo reale.

## 📦 Installazione e Compilazione

### 1. Clonare la Repository
È necessario clonare la repository includendo i sottomoduli (per scaricare anche Cinolib se linkato, altrimenti assicurarsi che la libreria sia presente).

```bash
git clone --recursive [https://github.com/fabiopsh/Tirocinio-Tesi.git](https://github.com/fabiopsh/Tirocinio-Tesi.git)
cd Tirocinio-Tesi
