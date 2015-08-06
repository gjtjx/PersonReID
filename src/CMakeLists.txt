aux_source_directory(./ SRC_LIST)

add_executable( PID ${SRC_LIST} )

SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

SET(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)

find_package( OpenCV )

include_directories( ${OpenCV_INCLUDE_DIRS} 
			${PROJECT_SOURCE_DIR}/includes 
			${PROJECT_SOURCE_DIR}/includes/commands )

target_link_libraries( PID ${OpenCV_LIBS} )