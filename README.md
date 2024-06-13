# LogicFactory

![Framework](LogicFactory.svg "framework")


# Startup
- compile with docker
```
> // get to the project root folder
> cd <path>/LogicFactory
> // build the docker image
> docker build -t logic-factory:latest .
> // run the docker image, and mount the project folder to the docker workspace
> docker run -it -v <path>/LogicFactory:/workspace logic-factory:latest
> // build with the docker environment
> mkdir build && cd build
> cmake ..
> make -j 8
```