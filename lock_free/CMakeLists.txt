ADD_EXECUTABLE(lock_free_1 main_1.cpp)
TARGET_LINK_LIBRARIES(lock_free_1 ${Boost_LIBRARIES})

ADD_EXECUTABLE(lock_free_2 main_2.cpp)
TARGET_LINK_LIBRARIES(lock_free_2 ${Boost_LIBRARIES})

ADD_EXECUTABLE(lock_free_3 main_3.cpp)
TARGET_LINK_LIBRARIES(lock_free_3 ${Boost_LIBRARIES})