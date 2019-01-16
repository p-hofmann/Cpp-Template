# C++ Mega Project Template
[![TraviCI](https://api.travis-ci.com/p-hofmann/Cpp-Template.svg?branch=master)](https://travis-ci.com/p-hofmann/Cpp-Template)
[![CircleCI](https://circleci.com/gh/p-hofmann/Cpp-Template/tree/master.svg?style=svg)](https://circleci.com/gh/p-hofmann/Cpp-Template/tree/master)  
This [template](https://github.com/p-hofmann/Cpp-Template) uses modern tools to organize and test a big C++ project.
* **Organized**  
The organisational power of [CMake](https://cmake.org/) and [Git submodul](https://git-scm.com/) allows for a clear folder structure.  
* **Multi-platform** (Linux, Windows, Darwin)  
Supporting multiple operation systems causes issues such as preprocessor directives cluttering up your code.
This template uses a way to reduce such preprocessor directives ([Cpp-FileSystem-Emulator](https://github.com/catchorg/Cpp-FileSystem-Emulator)) using CMake.
* **Continuous integration** (Travis CI, Circle CI)  
Testing on ones own machine is an insufficient way testing code meant for multiple platforms.
Even Continuous Integration sites, like [Circle CI](https://circleci.com/), 
often only support a limited selection of platforms.  
Because of that [Travis CI](https://travis-ci.com/) is recommend, which provides images for Linux, OSX and Windows.
* **Unittests** (Catch2)  
All modules include unittests using [Catch2](https://github.com/catchorg/Catch2).
The [Catch2](https://github.com/catchorg/Catch2) source is not included in this repository, 
but is cloned from the remote repository when the unittests are build.  

Much of the template structure and other parts are from ideas gained from guides 
and code bits and pieces from [https://stackoverflow.com/](https://stackoverflow.com/).  
Notable influences are:
* Guides
  - [It's Time To Do CMake Right](https://pabloariasal.github.io/2018/02/19/its-time-to-do-cmake-right/) by Pablo Arias
  - [Effective Modern CMake](https://gist.github.com/mbinna/c61dbb39bca0e4fb7d1f73b0d66a4fd1) by Manuel Binna
* Travis CI
  - The config file for [Travis CI](https://travis-ci.com/) is a near identical copy of [Catch2](https://github.com/catchorg/Catch2)'s config, 
  which does very extensive tests.

This template is by no means perfect or even finished and will expand and improve.

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
  - [Catch2](https://github.com/catchorg/Catch2) will be downloaded as part of CMake when run on unittests.

## Git submodule
Git submodule is an integral part of this template.
It is possible to use CMake's 'ExternalProject' instead, see 'CMakeLists.txt' in the 'tests' folder for an example.  
Git submodule has been chosen, as fewer maintenance is expected than from a CMake script.

### Git submodule - add
Use https urls for submodules, the ssh alternative requires a key, 
which will not exist on the continuous integration platform.
```
git submodule add https://github.com/p-hofmann/submodule.git include/submodule
```

### Git submodule - move/rename
```
git mv include/submodule include/submoduleNew
```

### Git submodule - delete
```
rm -rf include/submodule
git submodule deinit -f -- include/submodule    
rm -rf .git/modules/include/submodule
git rm -f include/submodule
```

### Git submodule - init submodules
After a project is cloned, the submodules are still empty. Those are cloned int the sub-folders with this command:
```
git submodule update --init --recursive
```
### Git submodule - update submodules to latest version
```
git submodule update --remote --recursive --merge
```

## TODO:
* Continuous Integration
  - Use of valgrind in Windows OS setup.
  - Make sure library is build in addition to Unittests.
    * Maybe use linked library in unittests instead of source.
  - Find out if images of different architectures for each OS are available on travis.
* CMake
  - Make sure all project dependencies are made.
  - 'Install library' configuration example.
  - Prevention of loading a project twice (like done with Catch2).
  - Consider a 'CMakeLists.txt' in 'external', dealing with all external projects.
  - Consider a 'CMakeLists.txt' in 'src', dealing only with the current project.
  - Consider a 'CMakeLists.txt' in 'include', dealing only with submodules of the current project.
* Git
  - Modify template to also work with private git repositories.
  - Add example of SSH instead of Https url to repositories
