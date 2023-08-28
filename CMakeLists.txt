cmake_minimum_required(VERSION 3.2)
project(freeverb LANGUAGES CXX)

###################
#  Build options  #
###################

option(FREEVERB_DENORMAL_SAMPLES "Add code to denormalizing samples, not needed if the host sets denormals to off" OFF)

###################
#  Create target  #
###################

add_library(freeverb STATIC Components/allpass.cpp
                            Components/comb.cpp
                            Components/revmodel.cpp)

target_include_directories(freeverb PUBLIC include Components)
target_compile_features(freeverb PUBLIC cxx_std_17)

if (FREEVERB_DENORMAL_SAMPLES)
    target_compile_definitions(freeverb PRIVATE FREEVERB_DENORMAL_SAMPLES=1 )
endif()
