QT += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += object_parallel_to_source

CONFIG += c++11

DEFINES += QT_DEPRECATED_WARNINGS

TARGET = trains_gui
TEMPLATE = app

INCLUDEPATH += include libs

HEADERS += \
    include/ai/IBot.h \
    include/ai/JustDoItBot.h \
    include/client/ITrainClient.h \
    include/client/TCPTrainClient.h \
    include/convertors/json/DynamicMapReader.h \
    include/convertors/json/ModelConvertor.h \
    include/convertors/json/MoveWriter.h \
    include/convertors/json/PlayerReader.h \
    include/convertors/json/StaticMapReader.h \
    include/convertors/IDynamicMapReader.h \
    include/convertors/IModelConvertor.h \
    include/convertors/IMoveWriter.h \
    include/convertors/IPlayerReader.h \
    include/convertors/IStaticMapReader.h \
    include/gui/QWorldWidget.h \
    include/models/DynamicMap.h \
    include/models/LineModel.h \
    include/models/MoveModel.h \
    include/models/PlayerModel.h \
    include/models/PointModel.h \
    include/models/PostModel.h \
    include/models/PostType.h \
    include/models/SpeedType.h \
    include/models/StaticMap.h \
    include/models/TrainModel.h \
    include/network/ResposeMessage.h \
    include/network/TCPClient.h \
    include/network/TCPSession.h \
    include/network/TCPSocket.h \
    include/utils/GraphPlaner.h \
    include/world/BasePost.h \
    include/world/ICommandSender.h \
    include/world/IPost.h \
    include/world/Line.h \
    include/world/Player.h \
    include/world/Point.h \
    include/world/PostFactory.h \
    include/world/Train.h \
    include/world/World.h \
    include/CommandSender.h \
    include/QRunnerThread.h \
    include/Runner.h \
    libs/nlohmann/json.hpp \
    include/world/Town.h \
    include/world/Market.h \
    include/utils/pi.h \
    include/ai/ArtMarket.h \
    include/ai/ArtTown.h \
    include/ai/IBot.h \
    include/ai/Post.h \
    include/ai/ScoreCalc.h \
    libs/easylogging++/easylogging++.h \
    include/ai/NPBot.h \
    include/ai/IPathGenerator.h \
    include/ai/GreedyBot.h \
    include/ai/generators/Annealing.h \
    include/models/GoodType.h \
    include/models/EventModel.h \
    include/models/EventType.h \
    include/convertors/IUpgradeWriter.h \
    include/convertors/json/UpgradeWriter.h \
    include/models/UpgradeModel.h \
    include/convertors/ICoordsMapReader.h \
    include/convertors/json/CoordsMapReader.h \
    include/models/CoordModel.h \
    include/world/events/BaseEvent.h \
    include/world/events/HijackersAssaultEvent.h \
    include/world/events/ParasitesAssaultEvent.h \
    include/world/events/TrainCollisionEvent.h \
    include/world/EventFactory.h \
    include/world/IEvent.h \
    include/models/CoordsMap.h \
    include/ai/CollisionAllower.h \
    include/ai/TrainGoalPredictor.h \
    include/world/Storage.h \
    include/ai/CollisionAllower.h \
    include/ai/GreedyBot.h \
    include/ai/IBot.h \
    include/ai/IBotSegment.h \
    include/ai/IPathGenerator.h \
    include/ai/JustDoItBot.h \
    include/ai/NPBot.h \
    include/ai/Post.h \
    include/ai/ScoreCalc.h \
    include/ai/TrainAI.h \
    include/ai/TrainGoalPredictor.h \
    include/ai/UpgradeAI.h \
    include/ai/ComplexBot.h

SOURCES += \
    src/ai/JustDoItBot.cpp \
    src/client/TCPTrainClient.cpp \
    src/convertors/json/DynamicMapReader.cpp \
    src/convertors/json/ModelConvertor.cpp \
    src/convertors/json/MoveWriter.cpp \
    src/convertors/json/PlayerReader.cpp \
    src/convertors/json/StaticMapReader.cpp \
    src/gui/QWorldWidget.cpp \
    src/models/DynamicMap.cpp \
    src/models/LineModel.cpp \
    src/models/MoveModel.cpp \
    src/models/PlayerModel.cpp \
    src/models/PointModel.cpp \
    src/models/PostModel.cpp \
    src/models/StaticMap.cpp \
    src/models/TrainModel.cpp \
    src/network/TCPClient.cpp \
    src/network/TCPSession.cpp \
    src/network/TCPSocket.cpp \
    src/utils/GraphPlaner.cpp \
    src/world/BasePost.cpp \
    src/world/Line.cpp \
    src/world/Player.cpp \
    src/world/Point.cpp \
    src/world/PostFactory.cpp \
    src/world/Train.cpp \
    src/world/World.cpp \
    src/CommandSender.cpp \
    src/main_gui.cpp \
    src/QRunnerThread.cpp \
    src/Runner.cpp \
    src/world/Town.cpp \
    src/world/Market.cpp \
    src/ai/ArtMarket.cpp \
    src/ai/ArtTown.cpp \
    src/ai/Post.cpp \
    src/ai/ScoreCalc.cpp \
    libs/easylogging++/easylogging++.cc \
    src/ai/NPBot.cpp \
    src/ai/GreedyBot.cpp \
    src/ai/generators/Annealing.cpp \
    src/models/EventModel.cpp \
    src/convertors/json/UpgradeWriter.cpp \
    src/models/UpgradeModel.cpp \
    src/convertors/json/CoordsMapReader.cpp \
    src/world/events/BaseEvent.cpp \
    src/world/events/HijackersAssaultEvent.cpp \
    src/world/events/ParasitesAssaultEvent.cpp \
    src/world/events/TrainCollisionEvent.cpp \
    src/world/EventFactory.cpp \
    src/ai/CollisionAllower.cpp \
    src/ai/TrainGoalPredictor.cpp \
    src/world/Storage.cpp \
    src/ai/TrainAI.cpp \
    src/ai/UpgradeAI.cpp \
    src/ai/ComplexBot.cpp

DISTFILES +=


