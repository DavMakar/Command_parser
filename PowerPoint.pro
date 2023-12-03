QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    PowerPoint.cpp \
    view/ItemsToolBar.cpp \
    view/CommandBar.cpp \
    view/CommandLog.cpp \
    view/WorkingArea.cpp \
    cli/controller.cpp \
    cli/commandCreator.cpp \
    cli/commandRegistry.cpp \ 
    cli/commands/CommandArgument.cpp \
    cli/commands/AddCommand.cpp \
#    cli/commands/ChangeItemCommand.cpp \
    cli/commands/GoSlideCommand.cpp \
    cli/commands/CreateCommand.cpp \
    cli/commands/DisplayCommand.cpp \
    cli/commands/ListCommand.cpp \
    cli/commands/LoadCommand.cpp \
    cli/commands/QuitCommand.cpp \
    cli/commands/RemoveCommand.cpp \
    cli/commands/SaveCommand.cpp \
    document/itemRegistry.cpp \
    director/director.cpp \ 
    document/document.cpp \ 
    document/Slide.cpp \
    document/item.cpp \ 
    document/Rect.cpp \ 
    document/Point.cpp \
    serializer/Visitor.cpp \
    serializer/TxtSerializer.cpp \
    serializer/TxtDeserializer.cpp \ 


HEADERS += \
    PowerPoint.hpp \
    view/ItemsToolBar.hpp \
    view/CommandBar.hpp \
    view/CommandLog.hpp \
    view/WorkingArea.hpp \
    cli/controller.hpp \
    cli/commandCreator.hpp \
    cli/commandRegistry.cpp \ 
    cli/commands/command.hpp \
    cli/commands/CommandArgument.hpp \
    cli/commands/AddCommand.hpp \
#    cli/commands/ChangeItemCommand.hpp \
    cli/commands/GoSlideCommand.hpp \
    cli/commands/CreateCommand.hpp \
    cli/commands/DisplayCommand.hpp \
    cli/commands/ListCommand.hpp \
    cli/commands/LoadCommand.hpp \
    cli/commands/QuitCommand.hpp \
    cli/commands/RemoveCommand.hpp \
    cli/commands/SaveCommand.hpp \
    document/itemRegistry.hpp \
    director/director.hpp \
    document/document.hpp \ 
    document/Slide.hpp \
    document/item.hpp \ 
    document/Rect.hpp \ 
    document/Point.hpp \
    serializer/Visitor.hpp \
    serializer/TxtSerializer.hpp \
    serializer/TxtDeserializer.hpp \ 

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    icons.qrc
