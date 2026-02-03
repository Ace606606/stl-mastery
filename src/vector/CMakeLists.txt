set(MODULE_NAME vector_demo)
set(MODULE_SRC
     "vector_demo.cpp"
)

add_executable(${MODULE_NAME} ${MODULE_SRC})

target_include_directories(${MODULE_NAME} PRIVATE ${PROJECT_INCLUDE_DIR})