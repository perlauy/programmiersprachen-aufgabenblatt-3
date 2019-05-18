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
