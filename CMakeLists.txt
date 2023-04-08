# CMakeList.txt: Workflow-fire 的 CMake 项目，在此处包括源代码并定义
# 项目特定的逻辑。
#
cmake_minimum_required (VERSION 3.8)
include_directories(include)

# Enable Hot Reload for MSVC compilers if supported.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project ("Workflow-fire")

# 将源代码添加到此项目的可执行文件。
add_executable (Workflow-fire  include/config_manager.h include/data_processing_engine.h include/data_source.h include/data_parser.h include/data_output.h include/http_data_source.h include/pipe_data_source.h include/http_data_parser.h include/pipe_data_parser.h include/http_data_output.h include/pipe_data_output.h src/main.cpp src/config_manager.cpp src/data_processing_engine.cpp src/http_data_source.cpp src/pipe_data_source.cpp src/http_data_parser.cpp src/pipe_data_parser.cpp src/http_data_output.cpp src/pipe_data_output.cpp )

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET Workflow-fire PROPERTY CXX_STANDARD 20)
endif()

if (MSVC)
    # 设置Visual Studio中的工作目录
    set_target_properties(Workflow-fire PROPERTIES VS_DEBUGGER_WORKING_DIRECTORY "${CMAKE_SOURCE_DIR}")
elseif (CMAKE_BUILD_TYPE MATCHES Debug)
    # 设置其他IDE或调试工具的工作目录
    set_target_properties(Workflow-fire PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}")
endif()

# TODO: 如有需要，请添加测试并安装目标。
