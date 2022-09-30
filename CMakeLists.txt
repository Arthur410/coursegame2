cmake_minimum_required(VERSION 3.20)
project(coursegame)

set(CMAKE_CXX_STANDARD 14)

add_executable(coursegame main.cpp Cell/Cell.cpp Cell/Cell.h CellView/CellView.cpp CellView/CellView.h Player/Player.cpp Player/Player.h Field/Field.cpp Field/Field.h FieldView/FieldView.cpp FieldView/FieldView.h CommandReader/CommandReader.cpp CommandReader/CommandReader.h Event/Event.h Controller/Controller.cpp Controller/Controller.h)
