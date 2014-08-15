TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

# GL and related includes/libs
# #include <libdrm/ > or #include <GL> it source files
INCLUDEPATH += /usr/include \
/usr/include/glm

LIBS += -lGLEW -lGLU -lGL

# SDL2 libs
LIBS += -lSDL2_image -lSDL2 -lpthread

*-g++*
{
	QMAKE_CXXFLAGS += -O3 -std=c++11 -pedantic -D_REENTRANT
}

SOURCES += main.cpp \
    display/display.cpp \
    mesh/mesh.cpp \
	mesh/format/obj/obj_loader.cpp \
	shader/shader.cpp \
    texture/texture.cpp \
    transform/transform.cpp \
	camera/camera.cpp


HEADERS += \
	display/display.h \
    mesh/mesh.h \
	mesh/format/obj/obj_loader.h \
    shader/shader.h \
    texture/texture.h \
    transform/transform.h \
    camera/camera.h

OTHER_FILES += \
	res/shaders/basicShader.frag \
	res/shaders/basicShader.vert

include(deployment.pri)
qtcAddDeployment()



