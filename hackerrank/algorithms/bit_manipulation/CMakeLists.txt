project(${PROJECT_NAME}-bit-manipulation)

file(GLOB SRC_FILES "${PROJECT_SOURCE_DIR}/*.cpp")
foreach(SRC_FILEPATH ${SRC_FILES})
	get_filename_component(SRC_FILENAME ${SRC_FILEPATH} NAME)
	build_target(${SRC_FILENAME})
endforeach()
