#include "Shader.h"

namespace Silcoish {
    namespace Graphics {

        Shader::Shader(const char* vertPath, const char* fragPath) :
            vertexPath(vertPath), fragmentPath(fragPath)
        {
            shaderID = load();
        }

        Shader::~Shader()
        {
            glDeleteProgram(shaderID);
        }

        GLuint Shader::load()
        {
            GLuint program = glCreateProgram();
            GLuint vertex = glCreateShader(GL_VERTEX_SHADER);
            GLuint fragment = glCreateShader(GL_FRAGMENT_SHADER);

            std::string vertSourceString = FileUtils::readFile(vertexPath);
            std::string fragSourceString = FileUtils::readFile(fragmentPath);

            const char* vertSource = vertSourceString.c_str();
            const char* fragSource = fragSourceString.c_str();

            glShaderSource(vertex, 1, &vertSource, NULL);
            glCompileShader(vertex);

            GLint result;
            glGetShaderiv(vertex, GL_COMPILE_STATUS, &result);
            if (result == GL_FALSE)
            {
                GLint length;
                glGetShaderiv(vertex, GL_INFO_LOG_LENGTH, &length);
                std::vector<char> error(length);
                glGetShaderInfoLog(vertex, length, &length, &error[0]);
                std::cout << "Failed to compile vertex shader!" << std::endl << &error[0] << std::endl;
                glDeleteShader(vertex);
                return 0;
            }

            glShaderSource(fragment, 1, &fragSource, NULL);
            glCompileShader(fragment);

            glGetShaderiv(fragment, GL_COMPILE_STATUS, &result);
            if (result == GL_FALSE)
            {
                GLint length;
                glGetShaderiv(fragment, GL_INFO_LOG_LENGTH, &length);
                std::vector<char> error(length);
                glGetShaderInfoLog(fragment, length, &length, &error[0]);
                std::cout << "Failed to compile fragment shader!" << std::endl << &error[0] << std::endl;
                glDeleteShader(fragment);
                return 0;
            }

            glAttachShader(program, vertex);
            glAttachShader(program, fragment);

            glLinkProgram(program);
            glValidateProgram(program);

            glDeleteShader(vertex);
            glDeleteShader(fragment);

            return program;
        }

        /*void Shader::setUniform1f(const GLchar *name, float value)
        {

        }
        void Shader::setUniform1i(const GLchar *name, int value)
        {

        }
        void Shader::setUniform2f(const GLchar *name, Maths::Vec2& value)
        {

        }
        void Shader::setUniform3f(const GLchar *name, Maths::Vec3& value)
        {

        }
        void Shader::setUniform4f(const GLchar *name, Maths::Vec4& value)
        {

        }
        void Shader::setUniformMat4(const GLchar *name, const Maths::Mat4& matrix)
        {

        }*/

        void Shader::enable() const
        {
            glUseProgram(shaderID);
        }

        void Shader::disable() const
        {
            glUseProgram(0);
        }

    }
}