cmake_minimum_required(VERSION 3.23)
project(lab2)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")
add_subdirectory(domino)
add_executable(lab2 main.cpp
        functions.cpp
        functions.cpp
        functions.h)
target_link_libraries(lab2 domino)
#для сборки из консоли:
#mkdir build # создание директории для файлов сборки
#cd build # переход в директорию сборки
#cmake .. # генерация файлов сборки на основе CMakeLists.txt
#make # сборка проекта
#mv main.cpp ../second
#mv CMakeLists.txt domino.h domino.cpp ../second/domino
#ssh login@samos.dozen.mephi.ru
#scp CMakeLists.txt main.cpp domino.h domino.cpp login@samos.dozen.mephi.ru:transit
