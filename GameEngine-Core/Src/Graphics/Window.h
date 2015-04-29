#pragma once
#include <iostream>
#include <glew.h>
#include <glfw3.h>

namespace Silcoish {
    namespace Graphics {
        
#define MAX_KEYS 1024
#define MAX_BUTTONS 32

        class Window
        {
        private:
            friend struct GLFWwindow;
            char* m_Name;
            int m_Width;
            int m_Height;
            GLFWwindow *window;

            bool keys[MAX_KEYS];
            bool mouseButtons[MAX_BUTTONS];
            double mouseX, mouseY;
        public:
            Window(char* title, int width, int height);
            ~Window();
            void Clear();
            void Update();

            inline GLFWwindow* GetWindow() { return window; }

            bool isKeyPressed(unsigned int keyCode) const;
            bool isMouseButtonPressed(unsigned int mouseButtonCode) const;
            void getMousePosition(double& x, double& y) const;
        private:
            bool Init(char* title, int width, int height);
            friend static void KeyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);
            friend static void MouseButtonCallback(GLFWwindow* window, int button, int action, int mods);
            friend static void CursorPositionCallback(GLFWwindow* window, double xpos, double ypos);

        };
    }
}