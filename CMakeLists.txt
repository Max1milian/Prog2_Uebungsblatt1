CMAKE_MINIMUM_REQUIRED(VERSION 3.20.0)

project(Uebungsblatt1
LANGUAGES CXX C
VERSION 0.0.1
DESCRIPTION "CMake Version vom Uebungsblatt1")

add_executable(${PROJECT_NAME} main.cpp datenbank.h kennzeichen.h)