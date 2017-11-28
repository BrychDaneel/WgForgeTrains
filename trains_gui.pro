QT += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets


DEFINES += QT_DEPRECATED_WARNINGS

TARGET = trains_gui
TEMPLATE = app

INCLUDEPATH += include libs

SOURCES += src/gui/main.cpp \
    src/client/TCPTrainClient.cpp \
    src/convertors/json/DynamicMapReader.cpp \
    src/convertors/json/ModelConvertor.cpp \
    src/convertors/json/MoveWriter.cpp \
    src/convertors/json/PlayerReader.cpp \
    src/convertors/json/StaticMapReader.cpp \
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
    src/Runner.cpp \
    src/gui/WorldWidget.cpp

HEADERS += \
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
    include/Runner.h \
    include/gui/WorldWidget.h \
    include/gui/WorldWidget.h \
    include/gui/Ticker.h
