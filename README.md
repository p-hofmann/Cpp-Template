# C++ Template
[![TraviCI](https://api.travis-ci.com/p-hofmann/Cpp-Template.svg?branch=master)](https://travis-ci.com/p-hofmann/Cpp-Template)
[![CircleCI](https://circleci.com/gh/p-hofmann/Cpp-Template/tree/master.svg?style=svg)](https://circleci.com/gh/p-hofmann/Cpp-Template/tree/master)  
A template showcasing the organisational power of cmake + git submodules  
[C++ template](https://github.com/p-hofmann/Cpp-Template) deals with the issue of organizing a big C++ project.
In addition to that, 
this project also includes ways to deal with different operation systems ([Cpp-FileSystem-Emulator](https://github.com/catchorg/Cpp-FileSystem-Emulator)) 
or even architecture ([Cpp-Template-Sub1-Sub](https://github.com/catchorg/Cpp-Template-Sub1-Sub)).  
All modules include unittests using [Catch2](https://github.com/catchorg/Catch2).
The [Catch2](https://github.com/catchorg/Catch2) source is not included in this repository as expected, but is cloned from the remote repository when the project is build.  
Continuous integration using [Travis CI](https://travis-ci.com/) is supported. The Code is there tested on Linux, Darwin and Windows OS.
[Circle CI](https://circleci.com/) is supported, but the Code is tested on Linux only. for now.

## Project Layout

├── CMakeLists.txt  
├── .travis.yml  
├── .circleci  
│&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;└── config.yml  
├── include  
│&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;├── Cpp-Template  
│&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;│ &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;└── project.h   
│&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;├── Cpp-Template-Sub1  
│&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;├── Cpp-FileSystem-Emulator  
├── libs  
│&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;└── library.a  
├── src  
│&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;├── project.cpp  
├── external  
│&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;└── catch2  
│&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;└── catch.hpp  
└── tests  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;├── CMakeLists.txt  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;└── test_project.cpp  

* .travis.yml
  - Configuration file for [Travis CI](https://travis-ci.com/) support.
* .circleci/config.yml
  - Configuration file for [Circle CI](https://circleci.com/) support.
* include/Cpp-Template
  - Header location of current module.
* include/Cpp-Template-Sub1
  - Submodule of this module. 
  - Not a third party project and considered part of this build, 
it is included in the 'include' folder, not the 'external' folder.
* include/Cpp-FileSystem-Emulator
  - Submodule of this module.
  - Part of this project, 
but is also its own project and it is debatable if it should be in external or include folder.
* libs
  - Location of libraries made by the submodules.
* src
  - Source files of current module.
* external
  - External projects that are not developed as part of this project.
* tests
  - Unittest files of current module.
* catch2
  - External project for unittests.
  - [Catch2](https://github.com/catchorg/Catch2) will be downloaded as part of cmake when run on unittests.

## TODO:
* Continuous Integration
  - Use of valgrind in Windows OS setup.
  - Make sure library is build in addition to Unittests.
    * Maybe use linked library in unittests instead of source.
* Cmake
  - Make sure all project dependencies are declared.
  - 'Install library' configuration example.
  - Prevention of loading a project twice (like done with Catch2).
