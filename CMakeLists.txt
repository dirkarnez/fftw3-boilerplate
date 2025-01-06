cmake_minimum_required(VERSION 3.18)

# set(CMAKE_FIND_DEBUG_MODE TRUE)

project("fftw3-playground")

# set(CMAKE_CXX_STANDARD 11)
# set(CMAKE_CXX_STANDARD_REQUIRED ON)

# MUST BE in capital
find_package(FFTW3 REQUIRED)

if(FFTW3_FOUND)
    message(STATUS "FFTW3_FOUND YES")
else()
    message(STATUS "NO")
endif()

# include_directories(${FFTW3_INCLUDE_DIRS})

add_executable(${PROJECT_NAME}
    "src/main.cpp"
)

target_link_libraries(${PROJECT_NAME} FFTW3::fftw3)
target_link_options(${PROJECT_NAME} PRIVATE "-static")