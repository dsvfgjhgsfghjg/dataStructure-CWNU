# 设置 CMake 的最低版本要求
cmake_minimum_required(VERSION 3.10)

# 设置项目名称和版本（这些是可选的，但推荐设置）
project(MyCppProject VERSION 1.0)

# 指定 C++ 标准（例如，C++11、C++14、C++17 等）
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# 添加包含目录（如果有的话）
# include_directories(${PROJECT_SOURCE_DIR}/include)

# 添加源文件到项目中
set(SOURCE_FILES
        main.cpp
        binaryTree.c
        # 在这里添加你的其他源文件，例如：foo.cpp bar.cpp
)

# 添加可执行文件目标
add_executable(MyCppExecutable ${SOURCE_FILES})

# 如果你的项目依赖于外部库，你需要在这里链接它们
# 例如：target_link_libraries(MyCppExecutable PRIVATE SomeLibrary)
add_executable(contacts contacts.c)
add_executable(matrix matrix.c)