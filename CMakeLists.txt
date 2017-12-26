cmake_minimum_required(VERSION 2.8)


project(console)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED on)
set(CMAKE_CXX_FLAGS -O2)

set(SOURCE
    src/main_console.cpp
    src/convertors/json/ModelConvertor.cpp
    src/convertors/json/CoordsMapReader.cpp
    src/convertors/json/MoveWriter.cpp
    src/convertors/json/PlayerReader.cpp
    src/convertors/json/UpgradeWriter.cpp
    src/convertors/json/StaticMapReader.cpp
    src/convertors/json/DynamicMapReader.cpp
    src/world/Market.cpp
    src/world/BasePost.cpp
    src/world/Town.cpp
    src/world/Line.cpp
    src/world/EventFactory.cpp
    src/world/World.cpp
    src/world/Train.cpp
    src/world/Storage.cpp
    src/world/PostFactory.cpp
    src/world/Player.cpp
    src/world/Point.cpp
    src/world/events/TrainCollisionEvent.cpp
    src/world/events/BaseEvent.cpp
    src/world/events/ParasitesAssaultEvent.cpp
    src/world/events/HijackersAssaultEvent.cpp
    src/CommandSender.cpp
    src/Runner.cpp
    src/models/PlayerModel.cpp
    src/models/PointModel.cpp
    src/models/EventModel.cpp
    src/models/LineModel.cpp
    src/models/UpgradeModel.cpp
    src/models/DynamicMap.cpp
    src/models/TrainModel.cpp
    src/models/StaticMap.cpp
    src/models/PostModel.cpp
    src/models/MoveModel.cpp
    src/client/TCPTrainClient.cpp
    src/ai/HomeChecker.cpp
    src/ai/SwitchAI.cpp
    src/ai/TrainAI.cpp
    src/ai/TrainGoalPredictor.cpp
    src/ai/LineBlocker.cpp
    src/ai/BotSharedData.cpp
    src/ai/ComplexBot.cpp
    src/ai/UpgradeAI.cpp
    src/ai/PathCalculator.cpp
    src/ai/CollisionAllower.cpp
    src/ai/Barrier.cpp
    src/network/TCPSession.cpp
    src/network/TCPSocket.cpp
    src/network/TCPClient.cpp
    libs/easylogging++/easylogging++.cc
    )

include_directories(include libs)

add_executable(console ${SOURCE})
