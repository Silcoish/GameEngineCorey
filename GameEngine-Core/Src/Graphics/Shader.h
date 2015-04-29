#pragma once

#include <iostream>
#include <vector>
#include <glew.h> 

#include "../Maths/Mat4.h"
#include "../Utils/FileUtils.h"

namespace Silcoish {
    namespace Graphics {
        
        class Shader
        {
        private:
            const char* vertexPath;
            const char* fragmentPath;
        public:
            GLuint shaderID;
            Shader(const char* vertPath, const char* fragPath);
            ~Shader();


            /*void setUniform1f(const GLchar *name, float value);
            void setUniform1i(const GLchar *name, int value);
            void setUniform2f(const GLchar *name, Silcoish::Maths::Vec2& value);
            void setUniform3f(const GLchar *name, Maths::Vec3& value);
            void setUniform4f(const GLchar *name, Maths::Vec4& value);
            void setUniformMat4(const GLchar *name, const Maths::Mat4& matrix);*/

            void enable() const;
            void disable() const;
        private:
            //GLint getUniformLocation(GLchar *name);
            GLuint load();
        };

    }
}