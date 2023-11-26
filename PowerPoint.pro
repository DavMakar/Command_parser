QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    ItemsToolBar.cpp \
    main.cpp \
    cli/tokenizer.cpp \
    CommandBar.cpp \
    CommandLog.cpp \
    WorkingArea.cpp \
    PowerPoint.cpp \
    cli/controller.cpp \
    cli/commandCreator.cpp \
    cli/factoryRegistry.cpp \
    cli/command_factories/AddFactory.cpp \
    cli/command_factories/ChangeFactory.cpp \
    cli/command_factories/CreateFactory.cpp \
    cli/command_factories/DisplayFactory.cpp \
    cli/command_factories/ListFactory.cpp \
    cli/command_factories/LoadFactory.cpp \
    cli/command_factories/QuitFactory.cpp \
    cli/command_factories/RemoveFactory.cpp \
    cli/command_factories/SaveFactory.cpp \
    cli/commands/AddCommand.cpp \
    cli/commands/ChangeItemCommand.cpp \
    cli/commands/ChangeSlideCommand.cpp \
    cli/commands/CreateCommand.cpp \
    cli/commands/DisplayCommand.cpp \
    cli/commands/ListCommand.cpp \
    cli/commands/LoadCommand.cpp \
    cli/commands/QuitCommand.cpp \
    cli/commands/RemoveCommand.cpp \
    cli/commands/SaveCommand.cpp \
    cli/itemRegistry.cpp \
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
    ItemsToolBar.hpp \
    cli/tokenizer.hpp \
    CommandBar.hpp \
    CommandLog.hpp \
    PowerPoint.hpp \
    WorkingArea.hpp \
    cli/controller.hpp \
    cli/commandCreator.hpp \
    cli/factoryRegistry.hpp \
    cli/command_factories/commandFactory.hpp \
    cli/commands/command.hpp \
    cli/command_factories/AddFactory.hpp \
    cli/command_factories/ChangeFactory.hpp \
    cli/command_factories/CreateFactory.hpp \
    cli/command_factories/DisplayFactory.hpp \
    cli/command_factories/ListFactory.hpp \
    cli/command_factories/LoadFactory.hpp \
    cli/command_factories/QuitFactory.hpp \
    cli/command_factories/RemoveFactory.hpp \
    cli/command_factories/SaveFactory.hpp \
    cli/commands/AddCommand.hpp \
    cli/commands/ChangeItemCommand.hpp \
    cli/commands/ChangeSlideCommand.hpp \
    cli/commands/CreateCommand.hpp \
    cli/commands/DisplayCommand.hpp \
    cli/commands/ListCommand.hpp \
    cli/commands/LoadCommand.hpp \
    cli/commands/QuitCommand.hpp \
    cli/commands/RemoveCommand.hpp \
    cli/commands/SaveCommand.hpp \
    cli/itemRegistry.hpp \
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
