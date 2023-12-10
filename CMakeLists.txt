cmake_minimum_required(VERSION 3.23)
project(lab2)

set(CMAKE_CXX_STANDARD 20)

add_executable(lab2 main.cpp domino/domino.h domino/domino.cpp)

#для сборки из консоли:
#mkdir build # создание директории для файлов сборки
#cd build # переход в директорию сборки
#cmake .. # генерация файлов сборки на основе CMakeLists.txt
#make # сборка проекта