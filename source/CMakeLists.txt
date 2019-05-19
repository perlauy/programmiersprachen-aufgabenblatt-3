# Build aufgabe_2_und_3
add_executable(aufgabe_2_und_3
  aufgabe_2_und_3.cpp
)


# Build tests
add_executable(tests
  tests.cpp
  )

# Build aufgabe_4
add_executable(aufgabe_4
  window.cpp
  glew.c
  vec2.cpp
  mat2.cpp
  circle.cpp
  rect.cpp
  circledrawer.hpp
  aufgabe_4.cpp
  )

# Build aufgabe_6
add_executable(aufgabe_6
  window.cpp
  glew.c
  vec2.cpp
  mat2.cpp
  circle.cpp
  aufgabe_6.cpp
  )

# Build aufgabe_7
add_executable(aufgabe_7
  window.cpp
  glew.c
  vec2.cpp
  mat2.cpp
  circle.cpp
  aufgabe_7.cpp
  )

target_link_libraries(aufgabe_4
  glfw
  ${GLFW_LIBRARIES}
  nanovg
  ${OPENGL_LIBRARIES}
  )
add_dependencies(aufgabe_4 glfw nanovg ${COPY_BINARY})

target_link_libraries(aufgabe_6
  glfw
  ${GLFW_LIBRARIES}
  nanovg
  ${OPENGL_LIBRARIES}
  )
add_dependencies(aufgabe_4 glfw nanovg ${COPY_BINARY})

target_link_libraries(aufgabe_7
  glfw
  ${GLFW_LIBRARIES}
  nanovg
  ${OPENGL_LIBRARIES}
  )
add_dependencies(aufgabe_4 glfw nanovg ${COPY_BINARY})
# Build example
add_executable(example
  window.cpp
  glew.c
  vec2.cpp
  mat2.cpp
  circle.cpp
  rect.cpp
  example.cpp
  )
target_link_libraries(example
  glfw
  ${GLFW_LIBRARIES}
  nanovg
  ${OPENGL_LIBRARIES}
  )
add_dependencies(example glfw nanovg ${COPY_BINARY})


# Build aufgabe_8
add_executable(aufgabe_8
  window.cpp
  glew.c
  vec2.cpp
  mat2.cpp
  circle.cpp
  aufgabe_8.cpp
  )

target_link_libraries(aufgabe_8
  glfw
  ${GLFW_LIBRARIES}
  nanovg
  ${OPENGL_LIBRARIES}
  ) 


# Build aufgabe_9
add_executable(aufgabe_9
  aufgabe_9.cpp
  )

# Build aufgabe_11
add_executable(aufgabe_11
  aufgabe_11.cpp
  )
# Build aufgabe_12
add_executable(aufgabe_12
  aufgabe_12.cpp
  )
# Build aufgabe_13
add_executable(aufgabe_13
  aufgabe_13.cpp
  )


# Build aufgabe_14
add_executable(aufgabe_14
  window.cpp
  glew.c
  vec2.cpp
  mat2.cpp
  circle.cpp
  aufgabe_14.cpp
  )

target_link_libraries(aufgabe_14
  glfw
  ${GLFW_LIBRARIES}
  nanovg
  ${OPENGL_LIBRARIES}
  ) 

