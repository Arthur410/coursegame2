cmake_minimum_required(VERSION 3.20)
project(coursegame)

set(CMAKE_CXX_STANDARD 14)

add_executable(coursegame main.cpp Cell/Cell.cpp Cell/Cell.h CellView/CellView.cpp CellView/CellView.h Player/Player.cpp Player/Player.h Field/Field.cpp Field/Field.h FieldView/FieldView.cpp FieldView/FieldView.h CommandReader/CommandReader.cpp CommandReader/CommandReader.h Event/IEvent.h Controller/Controller.cpp Controller/Controller.h Event/PlayerEvent/medicalEvent/MedicalEvent.cpp Event/PlayerEvent/medicalEvent/MedicalEvent.h Event/PlayerEvent/mineEvent/MineEvent.cpp Event/PlayerEvent/mineEvent/MineEvent.h Event/PlayerEvent/PlayerEvent.cpp Event/PlayerEvent/PlayerEvent.h Event/CellEvent/CellEvent.cpp Event/CellEvent/CellEvent.h Event/CellEvent/CellChangeToWall/CellChangeToWall.cpp Event/CellEvent/CellChangeToWall/CellChangeToWall.h Event/CellEvent/CellChangeToExit/CellChangeToExit.cpp Event/CellEvent/CellChangeToExit/CellChangeToExit.h)
