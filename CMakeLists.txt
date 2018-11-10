cmake_minimum_required(VERSION 3.12)
project(a6)

set(CMAKE_CXX_STANDARD 14)

add_executable(a6 main.cpp Card.cpp Card.h DeckOfCards.cpp DeckOfCards.h Hand.cpp Hand.h)