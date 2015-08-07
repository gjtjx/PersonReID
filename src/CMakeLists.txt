file(GLOB_RECURSE PID_SRC ${PROJECT_SOURCE_DIR}/src/*.cpp)
file(GLOB_RECURSE PID_HEADERS ${PROJECT_SOURCE_DIR}/includes/*.h)
message("PID_SRC:" ${PID_SRC})
set (PID_INCLUDE_DIRS "")
foreach (_headerFile ${PID_HEADERS})
    get_filename_component(_dir ${_headerFile} PATH)
    list (APPEND PID_INCLUDE_DIRS ${_dir})
endforeach()
list(REMOVE_DUPLICATES PID_INCLUDE_DIRS)

include_directories(${PID_INCLUDE_DIRS})
add_executable ( PIDEXE ${PID_SRC})

SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

SET(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)

find_package( OpenCV )

#include_directories( ${OpenCV_INCLUDE_DIRS} 
#			${PROJECT_SOURCE_DIR}/includes 
#			${PROJECT_SOURCE_DIR}/includes/commands )

target_link_libraries( PIDEXE ${OpenCV_LIBS} )