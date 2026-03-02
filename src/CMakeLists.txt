set(header_path "${${PROJECT_NAME}_SOURCE_DIR}/include")
set(header_circle ${header_path}/circle.h)
set(header_tasks ${header_path}/tasks.h)
set(src_circle circle.cpp)
set(src_tasks tasks.cpp)

add_library(${PROJECT_NAME} SHARED
  ${header_circle}
  ${header_tasks}
  ${src_circle}
  ${src_tasks})
  
target_include_directories(${PROJECT_NAME}
  PUBLIC ${CMAKE_CURRENT_BINARY_DIR}
         ${${PROJECT_NAME}_SOURCE_DIR}/include)
target_link_libraries(${PROJECT_NAME}
  pthread)

add_executable(${PROJECT_NAME}.info main.cpp)
target_include_directories(${PROJECT_NAME}.info
  PUBLIC ${CMAKE_CURRENT_BINARY_DIR}
         ${${PROJECT_NAME}_SOURCE_DIR}/include)
target_link_libraries(${PROJECT_NAME}.info
  ${PROJECT_NAME})


install(TARGETS ${PROJECT_NAME}
        LIBRARY DESTINATION "${lib_dest}"
    ARCHIVE DESTINATION "${lib_dest}"
    COMPONENT library)
install(TARGETS ${PROJECT_NAME}.info
        RUNTIME DESTINATION "${tool_dest}"
    COMPONENT library)
install(FILES ${header_circle} ${header_tasks} DESTINATION "${include_dest}")
