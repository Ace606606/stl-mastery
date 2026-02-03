set(TEST_NAME stl_tests)
set(TEST_SRC
     "test_vector.cpp"
)

add_executable(${TEST_NAME} ${TEST_SRC})

target_link_libraries(${TEST_NAME} PRIVATE gtest gtest_main)

target_include_directories(${TEST_NAME} PRIVATE ${PROJECT_INCLUDE_DIR})

include(GoogleTest)
gtest_discover_tests(${TEST_NAME})