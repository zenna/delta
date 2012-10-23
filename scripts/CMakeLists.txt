set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/modules/")

#set(CMAKE_CXX_FLAGS "-g -O3 -std=gnu++0x -Wall -stdlib=libc++ -DUSE_BOOST")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++0x -Wall")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -Wall")
set(CMAKE_CSS_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -Wall -O3")

ADD_EXECUTABLE(interpret interpret.cpp)
#target_link_libraries(new_executable  ${project_LIBRARIES})