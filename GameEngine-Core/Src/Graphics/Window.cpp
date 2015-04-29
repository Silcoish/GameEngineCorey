#include "Window.h";

namespace Silcoish
{
    namespace Graphics
    {
        void Terminate(GLFWwindow* win);

        Window::Window(char* title, int width, int height)
        {
            if(!Init(title, width, height))
                glfwTerminate();

            for (int i = 0; i < MAX_KEYS; i++)
                keys[i] = false;
        }

        Window::~Window() {
            glfwTerminate();
        }

        bool Window::Init(char* title, int width, int height)
        {

            if (!glfwInit())
            {
                exit(EXIT_FAILURE);
                return false;
            }

            window = glfwCreateWindow(width, height, title, NULL, NULL);

            if (!window)
            {
                glfwTerminate();
                exit(EXIT_FAILURE);
                return false;
            }

            glfwMakeContextCurrent(window);
            glfwSetWindowUserPointer(window, this);
            glfwSwapInterval(1);

            //set up close callback function
            glfwSetWindowCloseCallback(window, Terminate);
            glfwSetKeyCallback(window, KeyCallback);
            glfwSetMouseButtonCallback(window, MouseButtonCallback);
            glfwSetCursorPosCallback(window, CursorPositionCallback);

            GLenum err;

            if ((err = glewInit()) != GLEW_OK)
            {
                std::cout << glewGetErrorString(err) << std::endl;
                return false;
            }


            std::cout << "OpenGL " << glGetString(GL_VERSION) << std::endl;
            return true;
        }

        void Window::Clear()
        {
            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        }

        void Window::Update()
        {
            glfwPollEvents();
            glfwSwapBuffers(window);
        }

        bool Window::isKeyPressed(unsigned int keycode) const
        {
            if (keycode >= MAX_KEYS)
                return false;

            return keys[keycode];
        }

        bool Window::isMouseButtonPressed(unsigned int mouseButtonCode) const
        {
            if (mouseButtonCode >= MAX_BUTTONS)
                return false;

            return mouseButtons[mouseButtonCode];
        }

        void Window::getMousePosition(double& x, double& y) const
        {
            x = mouseX;
            y = mouseY;
        }

        /* Callback Functions */
        void Terminate(GLFWwindow* win) // Terminate
        {
            glfwDestroyWindow(win);
            glfwTerminate();
            exit(EXIT_SUCCESS);
        }

        void KeyCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
        {
            Window* win = (Window*) glfwGetWindowUserPointer(window);
            win->keys[key] = action != GLFW_RELEASE;
        }

        void MouseButtonCallback(GLFWwindow* window, int button, int action, int mods)
        {
            Window* win = (Window*)glfwGetWindowUserPointer(window);
            win->mouseButtons[button] = action != GLFW_RELEASE;
        }

        void CursorPositionCallback(GLFWwindow* window, double xpos, double ypos)
        {
            Window* win = (Window*)glfwGetWindowUserPointer(window);
            win->mouseX = xpos;
            win->mouseY = ypos;
        }
        
    }
}
