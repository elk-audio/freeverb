cmake_minimum_required(VERSION 3.5)
project(freeverb LANGUAGES CXX)

###################
#  Build options  #
###################

option(FREEVERB_UNDENORMALIZE "Skip undenormalizing samples, useful if the host sets denormals to off" ON)

###################
#  Create target  #
###################

add_library(freeverb STATIC Components/allpass.cpp
                            Components/comb.cpp
                            Components/revmodel.cpp)

target_include_directories(freeverb PUBLIC Components)
target_compile_options(freeverb PRIVATE -fno-rtti -ffast-math)
target_compile_features(freeverb PUBLIC cxx_std_17)

if (FREEVERB_UNDENORMALIZE)
    target_compile_definitions(freeverb PRIVATE FREEVERB_UNDENORMALIZE=1)
endif()
