cmake_minimum_required(VERSION 3.13)
project(OpcodeHandler)

set(CMAKE_CXX_STANDARD 17)

#add_executable(OpcodeHandler src/main.cpp src/Middlewares/Authorization/BaseAuthorization/Permission.cpp include/Permission.h include/Opcodes.h src/Authenticate/Authenticate.cpp include/Authenticate.h src/Player/Player.cpp include/Player.h src/WorldPacket/WorldPacket.cpp include/WorldPacket.h src/Middlewares/Authorization/Administrator/Administrator.cpp include/Administrator.h include/Permissions.h src/Middlewares/Authorization/Handler/Authorization.cpp include/Authorization.h include/Middleware.h src/OpcodeTable/OpcodeTable.cpp include/OpcodeTable.h src/TransportLayer/TransportLayer.cpp include/TransportLayer.h include/MiddlewareManager.h include/InvokeHandler.h src/Middlewares/InvokeHandler/InvokeHandler.cpp src/Middlewares/Authorization/GameMaster/GameMaster.cpp include/GameMaster.h include/TransportLayerException.h src/Middlewares/DemuxHandler/DemuxHandler.cpp include/DemuxHandler.h src/Middlewares/Priest/Priest.cpp include/Priest.h)

#Bring the headers, such as Student.h into the project
include_directories(include)

file(GLOB_RECURSE source_files
        "src/*.cpp")

add_executable(OpcodeHandler ${source_files})