cmake_minimum_required(VERSION 2.8.0)
add_definitions(-DUNICOD -D_UNICOD)
project(zcTest)
set(CMAKE_CXX_STANDARD 11)
SET(CMAKE_BUILD_TYPE "release")
SET(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -O2 -Wall -g")
SET(CMAKE_CXX_FLAGS_RELEASE "$ENV{CXXFLAGS} -O2 -Wall -g")

include_directories(./)

file(GLOB_RECURSE source ./*.h  ./*.cpp )
source_group(Temp FILES ${source})
add_executable(${PROJECT_NAME} ${source})
#target_link_libraries(zcTest PUBLIC Calibration)
#target_include_directories(${PROJECT_NAME} PRIVATE 
#                           ${hearder}
#                           )

################################################################
SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR})  
SET(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR})
#link_libraries(${PROJECT_BINARY_DIR}/release/*.lib)
#link_libraries(${PROJECT_BINARY_DIR}/debug/*.lib)
#install(TARGETS zcTest
#		CONFIGURATIONS Release 
#        RUNTIME DESTINATION ${PROJECT_BINARY_DIR}/install/release
#        LIBRARY DESTINATION ${PROJECT_BINARY_DIR}/install/release
#        ARCHIVE DESTINATION ${PROJECT_BINARY_DIR}/install/release)		
#install(TARGETS zcTest
#		CONFIGURATIONS Debug
#        RUNTIME DESTINATION ${PROJECT_BINARY_DIR}/install/debug
#        LIBRARY DESTINATION ${PROJECT_BINARY_DIR}/install/debug
#        ARCHIVE DESTINATION ${PROJECT_BINARY_DIR}/install/debug)