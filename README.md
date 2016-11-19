## Building the stand-alone project

To compile:
    cd build
    cmake ..
    make
    
To run
    cd build/computer_vision/

You can then chose to run it on either the CUDA GPU or the CPUs

The Unified backend will try to dynamically load the backend libraries. The priority of backends is CUDA -> OpenCL -> CPU
