# S’assure que la version de make est suffisamment récente
cmake_minimum_required(VERSION 2.6)

# Indique le nom du projet
project(demo_cpp)

# Ajoute le répertoire include des fichiers .h au chemin de recherche des #include "xx.h"
include_directories(include)

# Impose le répertoire de création du fichier exécutable
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/../bin)

# Impose certaines options de compilation
set(CMAKE_C_FLAGS "-g -Wall -Wextra -ansi -pedantic-errors")

# Génère la liste des fichiers .cpp devant être compilés à partir des fichiers présents dans le répertoire src
file(
     GLOB_RECURSE
     srcFiles
     src/*.cpp
)
         
# Crée l'exécutable monExe à partir de la liste des fichiers .cpp
add_executable(
monExe
${srcFiles}
)
         
         
         
