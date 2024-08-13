# LogicFactory

![Framework](LogicFactory.svg "framework")


# Build
- compile with docker
```
$ // get to the project root folder
$ cd <path>/LogicFactory
$ // build the docker image
$ docker build -t logic-factory:latest .
$ // run the docker image, and mount the project folder to the docker workspace
$ docker run -it -v <path>/LogicFactory:/workspace logic-factory:latest
$ // build with the docker environment
$ mkdir build && cd build
$ cmake ..
$ make -j 8
```

# Getting Started
- RUN with tcl
```
$ ./build/app/logicfactory -s "demo/test.tcl"
```

- RUN with command sequence
```
$ ./build/app/logicfactory -c "help; start;"
```

- RUN with command line
```
$ ./build/app/logicfactory
--------------------------------------------
*    Welcome to LogicFactory (Platform)    *
*               Version 0.1                *
*     https://github.com/Logic-Factory     *
--------------------------------------------
% help
```