TEMPLATE = app
CONFIG += c++11
QT += qml quick location

SOURCES += main.cpp \
    playermodel.cpp \
    pos_server.cpp \
    generated/remotepos.grpc.pb.cc \
    generated/remotepos.pb.cc \
    dbroutines.cpp

RESOURCES += qml.qrc

HEADERS += \
    playermodel.h \
    pos_server.h \
    generated/remotepos.grpc.pb.h \
    generated/remotepos.pb.h \
    dbroutines.h

LIBS += -L/home/sunkiss/astim/grpc-1.9.0/libs/opt -lgrpc++ -lprotobuf -lsqlite3
