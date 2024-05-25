# 指定CMake的最低版本要求
cmake_minimum_required(VERSION 3.10)

# 定义项目名称和支持的语言
project(myproject CXX) # CXX表示C++

# 添加头文件搜索路径
include_directories(${PROJECT_SOURCE_DIR}/include)

# 添加源文件目录到变量中
set(SRC_DIR ${PROJECT_SOURCE_DIR}/src)

# 从源文件目录中添加源文件到变量中
file(GLOB SRC_FILES "${SRC_DIR}/*.cpp")

# 生成可执行文件，并链接源文件
add_executable(bin ${SRC_FILES})
