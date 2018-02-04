TEMPLATE = app
CONFIG += c++11

SOURCES += main.cpp \
    generated/remotepos.grpc.pb.cc \
    generated/remotepos.pb.cc

HEADERS += \
    generated/remotepos.grpc.pb.h \
    generated/remotepos.pb.h

LIBS += -L/home/sunkiss/astim/grpc-1.9.0/libs/opt -lgrpc++ -lprotobuf
