cmake_minimum_required(VERSION 3.20)
project(coursegame)

set(CMAKE_CXX_STANDARD 14)

add_executable(coursegame main.cpp Cell/Cell.cpp Cell/Cell.h CellView/CellView.cpp CellView/CellView.h Player/Player.cpp Player/Player.h Field/Field.cpp Field/Field.h FieldView/FieldView.cpp FieldView/FieldView.h CommandReader/CommandReader.cpp CommandReader/CommandReader.h Event/IEvent.h Controller/Controller.cpp Controller/Controller.h Event/PlayerEvent/HpIncrease/HpIncrease.cpp Event/PlayerEvent/HpIncrease/HpIncrease.h Event/PlayerEvent/HpDecrease/HpDecrease.cpp Event/PlayerEvent/HpDecrease/HpDecrease.h Event/PlayerEvent/PlayerEvent.cpp Event/PlayerEvent/PlayerEvent.h Event/FieldEvent/FieldEvent.cpp Event/FieldEvent/FieldEvent.h Event/FieldEvent/CellChangeToMine/CellChangeToMine.cpp Event/FieldEvent/CellChangeToMine/CellChangeToMine.h Event/FieldEvent/CellChangeToWall/CellChangeToWall.cpp Event/FieldEvent/CellChangeToWall/CellChangeToWall.h Event/FieldEvent/CellChangeToBuff/CellChangeToBuff.cpp Event/FieldEvent/CellChangeToBuff/CellChangeToBuff.h Event/PlayerEvent/StatsIncrease/StatsIncrease.cpp Event/PlayerEvent/StatsIncrease/StatsIncrease.h)
