cmake_minimum_required(VERSION 3.19)
cmake_policy(VERSION 3.19)

# Initialize Mbed OS build system. 
# Note: This block must be before the include of app.cmake
set(MBED_APP_JSON_PATH mbed_app.json)

include(mbed-os/tools/cmake/app.cmake)
add_subdirectory(mbed-os)

project(mbed-example-localfilesystem)

add_executable(mbed-example-localfilesystem mbed-example-localfilesystem.cpp)
target_link_libraries(mbed-example-localfilesystem mbed-os) # Can also link to mbed-baremetal here
mbed_set_post_build(mbed-example-localfilesystem)

mbed_finalize_build()