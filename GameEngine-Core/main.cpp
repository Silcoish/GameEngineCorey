#include <glew.h>
#include <glfw3.h>
#include <iostream>

#include "Src/Graphics/Window.h"
#include "Src/Graphics/Shader.h"
#include "Src/Maths/Maths.h";

using namespace Silcoish;
using namespace Silcoish::Graphics;
using namespace Silcoish::Maths;

int main()
{
    if (!glfwInit())
        std::cout << "ERROR" << std::endl;

   Window window("New Window Title", 960, 540);
   glClearColor(0.2f, 0.3f, 0.8f, 1.0f);


   GLfloat verticies[] =
   {
       4, 3, 0,
       12, 3, 0,
       4, 6, 0,
       4, 6, 0,
       12, 6, 0,
       12, 3, 0
   };

   GLuint vbo;
   glGenBuffers(1, &vbo);
   glBindBuffer(GL_ARRAY_BUFFER, vbo);
   glBufferData(GL_ARRAY_BUFFER, sizeof(verticies), verticies, GL_STATIC_DRAW);
   glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
   glEnableVertexAttribArray(0);

   Mat4 ortho = Mat4::orthographic(0.0f, 16.0f, 0.0f, 9.0f, -1.0f, 1.0f);

   Shader shader("Src/Shaders/basic.vert", "Src/Shaders/basic.frag");
   shader.enable();
   glUniformMatrix4fv(glGetUniformLocation(shader.shaderID, "pr_matrix"), 1, GL_FALSE, ortho.elements);

   while (!glfwWindowShouldClose(window.GetWindow()))
   {
       window.Clear();
       glDrawArrays(GL_TRIANGLES, 0, 6);
       window.Update();
   }

    return 0;
} 