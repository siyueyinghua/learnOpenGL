#include <glad/glad.h>
#include <GLFW/glfw3.h>
#define STB_IMAGE_IMPLEMENTATION
#include <glm/glm.hpp>
#include <glm/matrix.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/matrix_inverse.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtx/string_cast.hpp>
#include <shader.h>
#include <camera.h>
#include <model.h>
#include <iostream>


//----------------------
//  offscreen switch  //
//----------------------
//--#ifndef OFF_SCREEN
//--#define OFF_SCREEN 1
//--#ifndef FFMPE_G
//--#define FFMPEG 1
//--#endif
//--#endif

#if FFMPEG
#include <ffmpeg_encode.h>
enum Constants { SCREENSHOT_MAX_FILENAME = 256 };
static GLubyte *pixels = NULL;
static AVCodecContext *c = NULL;
static AVFrame *frame;
static AVPacket pkt;
static FILE *file;
static struct SwsContext *sws_context = NULL;
static uint8_t *rgb = NULL;
static int offscreen = 1;
static unsigned int max_nframes = 128;
static unsigned int nframes = 0;
static unsigned int time0;
#define PPM_BIT (1 << 0)
#define LIBPNG_BIT (1 << 1)
#define FFMPEG_BIT (1 << 2)
static unsigned int output_formats = PPM_BIT | LIBPNG_BIT | FFMPEG_BIT;
#endif



void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void mouse_callback(GLFWwindow* window, double xpos, double ypos);
void scroll_callback(GLFWwindow* window, double xoffset, double yoffset);
void processInput(GLFWwindow *window);

// settings
const unsigned int SCR_WIDTH = 1920;
const unsigned int SCR_HEIGHT = 1080;

// camera
Camera camera(glm::vec3(0.0f, 0.0f, 3.5f));
float lastX = SCR_WIDTH / 2.0f;
float lastY = SCR_HEIGHT / 2.0f;
bool firstMouse = true;

// timing
float deltaTime = 0.0f;
float lastFrame = 0.0f;

// lighting
glm::vec3 pointLightPos(1.2f, 1.0f, 2.0f);


int main()
{
    // glfw: initialize and configure
    // ------------------------------
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

    // glfw window creation
    // --------------------
    GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "LearnOpenGL", NULL, NULL);
    if (window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
    glfwSetCursorPosCallback(window, mouse_callback);
    glfwSetScrollCallback(window, scroll_callback);

    // tell GLFW to capture our mouse
    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

    // glad: load all OpenGL function pointers
    // ---------------------------------------
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }

    // tell stb_image.h to flip loaded texture's on the y-axis (before loading model).
    stbi_set_flip_vertically_on_load(true);

    // configure global opengl state
    // -----------------------------
    glEnable(GL_DEPTH_TEST);

    // build and compile shaders
    // -------------------------
    Shader ourShader("./src/shaders/4.model_loading_multi_light_normal.vs", "./src/shaders/4.model_loading_multi_light_normal.fs");

    // load models
    // -----------
    Model ourModel("../resources/objects/backpack/backpack.obj");


#if OFF_SCREEN
    /* Framebuffer configuration */
    // -------------------------
    unsigned int framebuffer;
    glGenFramebuffers(1, &framebuffer);
    glBindFramebuffer(GL_FRAMEBUFFER, framebuffer);

    /* Color renderbuffer. */
    // create a renderbuffer object for color attachment (we won't be sampling these)
    unsigned int color_rbo;
    glGenRenderbuffers(1, &color_rbo);
    glBindRenderbuffer(GL_RENDERBUFFER, color_rbo);
    //-- glRenderbufferStorage(GL_RENDERBUFFER, GL_RGB565, SCR_WIDTH, SCR_HEIGHT);
    glRenderbufferStorage(GL_RENDERBUFFER, GL_RGBA, SCR_WIDTH, SCR_HEIGHT);
    glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_RENDERBUFFER, color_rbo); // now actually attach it

    /* Depth renderbuffer. */
    // create a renderbuffer object for depth and stencil attachment (we won't be sampling these)
    unsigned int depth_stencil_rbo;
    glGenRenderbuffers(1, &depth_stencil_rbo);
    glBindRenderbuffer(GL_RENDERBUFFER, depth_stencil_rbo);
    glRenderbufferStorage(GL_RENDERBUFFER, GL_DEPTH24_STENCIL8, SCR_WIDTH, SCR_HEIGHT); // use a single renderbuffer object for both a depth AND stencil buffer.
    glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_DEPTH_STENCIL_ATTACHMENT, GL_RENDERBUFFER, depth_stencil_rbo); // now actually attach it

    /* Designate attachment for buffer manupulation command. */
    // <glReadBuffer> specifies a color buffer as the source for subsequent glReadPixels,
    // glCopyTexImage1D, glCopyTexImage2D, glCopyTexSubImage1D, glCopyTexSubImage2D, and glCopyTexSubImage3D commands
    glReadBuffer(GL_COLOR_ATTACHMENT0);

    /* Sanity check. */
    // now that we actually created the framebuffer and added all attachments we want to check if it is actually complete now
    if (glCheckFramebufferStatus(GL_FRAMEBUFFER) != GL_FRAMEBUFFER_COMPLETE)
        std::cout << "ERROR::FRAMEBUFFER:: Framebuffer is not complete!" << std::endl;

    glBindFramebuffer(GL_FRAMEBUFFER, 0);
#endif

#if FFMPEG
    #define PARA_NUM 1
 	GLint params[PARA_NUM];
    glGetInternalformativ(GL_RENDERBUFFER, GL_RGB565, GL_READ_PIXELS_FORMAT, PARA_NUM, params);
    for(int i=0; i<PARA_NUM; i++)
        std::cout << "I = " << i << ": GL_READ PIXELS FORMAT OF RGB565: 0x" << std::hex << params[i] << std::endl;
    glGetInternalformativ(GL_RENDERBUFFER, GL_RGB565, GL_READ_PIXELS_TYPE, PARA_NUM, params);
    for(int i=0; i<PARA_NUM; i++)
        std::cout << "I = " << i << ": GL_READ PIXELS TYPE OF RGB565: 0x" << std::hex << params[i] << std::endl;
    glGetInternalformativ(GL_RENDERBUFFER, GL_RGBA, GL_READ_PIXELS_FORMAT, PARA_NUM, params);
    for(int i=0; i<PARA_NUM; i++)
        std::cout << "I = " << i << ": GL_READ PIXELS FORMAT OF RGBA: 0x" << std::hex << params[i] << std::endl;

 	GLint64 params64[PARA_NUM];
    glGetInternalformati64v(GL_RENDERBUFFER, GL_RGB565, GL_READ_PIXELS_FORMAT, PARA_NUM, params64);
    for(int i=0; i<PARA_NUM; i++)
        std::cout << "I = " << i << ": GL_READ PIXELS FORMAT OF RGB565: 0x" << std::hex << params64[i] << std::endl;
    glGetInternalformati64v(GL_RENDERBUFFER, GL_RGB565, GL_READ_PIXELS_TYPE, PARA_NUM, params64);
    for(int i=0; i<PARA_NUM; i++)
        std::cout << "I = " << i << ": GL_READ PIXELS TYPE OF RGB565: 0x" << std::hex << params64[i] << std::endl;
    glGetInternalformati64v(GL_RENDERBUFFER, GL_RGBA, GL_READ_PIXELS_FORMAT, PARA_NUM, params64);
    for(int i=0; i<PARA_NUM; i++)
        std::cout << "I = " << i << ": GL_READ PIXELS FORMAT OF RGBA: 0x" << std::hex << params64[i] << std::endl;

    ffmpeg_encoder_start(&c, &file, "model_loading_light_noraml_demo_v1.mp4", &frame, AV_CODEC_ID_MPEG1VIDEO, 24, SCR_WIDTH, SCR_HEIGHT);
#endif

    // draw in wireframe
    //glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

    // render loop
    // -----------
    while (!glfwWindowShouldClose(window))
    {
        // per-frame time logic
        // --------------------
        float currentFrame = glfwGetTime();
        deltaTime = currentFrame - lastFrame;
        lastFrame = currentFrame;

        // input
        // -----
        processInput(window);

        // render
        // ------
        // 1 - set common variable
        // don't forget to enable shader before setting uniforms
        ourShader.use();

        // material properties and viewPos
        ourShader.setVec3("viewPos", camera.Position);
        ourShader.setFloat("material[0].shininess", 32.0f);

        // light properties
        // directional light
        ourShader.setVec3("dirLight.direction", -0.2f, -1.0f, -0.3f);
        ourShader.setVec3("dirLight.ambient", 0.05f, 0.05f, 0.05f);
        ourShader.setVec3("dirLight.diffuse", 0.4f, 0.4f, 0.4f);
        ourShader.setVec3("dirLight.specular", 0.5f, 0.5f, 0.5f);
        // point light
        ourShader.setVec3("pointLight.position", pointLightPos);
        ourShader.setVec3("pointLight.ambient", 0.05f, 0.05f, 0.05f);
        ourShader.setVec3("pointLight.diffuse", 0.8f, 0.8f, 0.8f);
        ourShader.setVec3("pointLight.specular", 1.0f, 1.0f, 1.0f);
        ourShader.setFloat("pointLight.constant", 1.0f);
        ourShader.setFloat("pointLight.linear", 0.09);
        ourShader.setFloat("pointLight.quadratic", 0.032);
        // spotLight
        ourShader.setVec3("spotLight.position", camera.Position);
        ourShader.setVec3("spotLight.direction", camera.Front);
        ourShader.setVec3("spotLight.ambient", 0.0f, 0.0f, 0.0f);
        ourShader.setVec3("spotLight.diffuse", 1.0f, 1.0f, 1.0f);
        ourShader.setVec3("spotLight.specular", 1.0f, 1.0f, 1.0f);
        ourShader.setFloat("spotLight.constant", 1.0f);
        ourShader.setFloat("spotLight.linear", 0.09);
        ourShader.setFloat("spotLight.quadratic", 0.032);
        ourShader.setFloat("spotLight.cutOff", glm::cos(glm::radians(12.5f)));
        ourShader.setFloat("spotLight.outerCutOff", glm::cos(glm::radians(15.0f)));

        // view/projection transformations
        glm::mat4 projection = glm::perspective(glm::radians(camera.Zoom), (float)SCR_WIDTH / (float)SCR_HEIGHT, 0.1f, 100.0f);
        glm::mat4 view = camera.GetViewMatrix();
        ourShader.setMat4("projection", projection);
        ourShader.setMat4("view", view);

        // render the loaded model
        glm::mat4 model = glm::mat4(1.0f);
        model = glm::translate(model, glm::vec3(0.0f, 0.0f, -1.0f)); // translate it down so it's at the center of the scene
        model = glm::scale(model, glm::vec3(0.8f, 0.8f, 0.8f));	// it's a bit too big for our scene, so scale it down
#define RATOTE_START_TIME 6
        if((float)glfwGetTime()>RATOTE_START_TIME)
        {
            float rotate_angle = ((float)glfwGetTime()-RATOTE_START_TIME)*0.05;
            model = glm::rotate(model, -rotate_angle, glm::vec3(0.0f, 1.0f, 0.0f));
        }
        //-- std::cout << ": glfwGetTime(): " << (float)glfwGetTime() << std::endl;
        ourShader.setMat4("model", model);
        // fixme: why cal and send normalMatrix here doesn't work
        // 2021-03-23: Because the name is wrong, should normalMatrix,not model
        glm::mat3 normalMatrix = glm::transpose(glm::inverse(glm::mat3(model)));
        ourShader.setMat3("normalMatrix", normalMatrix);

#if OFF_SCREEN
        // bind to framebuffer and draw scene as we normally would to color texture 
        glBindFramebuffer(GL_FRAMEBUFFER, framebuffer);

        // make sure we clear the framebuffer's content
        glClearColor(0.05f, 0.05f, 0.05f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        ourModel.Draw(ourShader);

        glBindFramebuffer(GL_FRAMEBUFFER, 0);
#endif

# if FFMPEG
        if (output_formats & FFMPEG_BIT) {
            frame->pts = nframes;
            ffmpeg_encoder_glread_rgb(&rgb, &pixels,  SCR_WIDTH, SCR_HEIGHT);
            ffmpeg_encoder_encode_frame(c, sws_context, rgb, pkt, frame, file);
        }
        nframes++;
#endif

        // 2 - render to default framebuffer to show on secreen
        glClearColor(0.05f, 0.05f, 0.05f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        ourModel.Draw(ourShader);

        // glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
        // -------------------------------------------------------------------------------
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    // End: program terminate, clearing all previously allocated resources.
#if OFF_SCREEN
    glDeleteFramebuffers(1, &framebuffer);
    glDeleteRenderbuffers(1, &color_rbo);
    glDeleteRenderbuffers(1, &depth_stencil_rbo);
#endif

#if FFMPEG
    free(pixels);
    if (output_formats & FFMPEG_BIT) {
        ffmpeg_encoder_finish(c, pkt, frame, file);
        free(rgb);
    }
#endif

    // glfw: terminate, clearing all previously allocated GLFW resources.
    // ------------------------------------------------------------------
    glfwTerminate();
    return 0;
}

// process all input: query GLFW whether relevant keys are pressed/released this frame and react accordingly
// ---------------------------------------------------------------------------------------------------------
void processInput(GLFWwindow *window)
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);

    if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
        camera.ProcessKeyboard(FORWARD, deltaTime);
    if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
        camera.ProcessKeyboard(BACKWARD, deltaTime);
    if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
        camera.ProcessKeyboard(LEFT, deltaTime);
    if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
        camera.ProcessKeyboard(RIGHT, deltaTime);
}

// glfw: whenever the window size changed (by OS or user resize) this callback function executes
// ---------------------------------------------------------------------------------------------
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    // make sure the viewport matches the new window dimensions; note that width and 
    // height will be significantly larger than specified on retina displays.
    glViewport(0, 0, width, height);
}

// glfw: whenever the mouse moves, this callback is called
// -------------------------------------------------------
void mouse_callback(GLFWwindow* window, double xpos, double ypos)
{
    if (firstMouse)
    {
        lastX = xpos;
        lastY = ypos;
        firstMouse = false;
    }

    float xoffset = xpos - lastX;
    float yoffset = lastY - ypos; // reversed since y-coordinates go from bottom to top

    lastX = xpos;
    lastY = ypos;

    camera.ProcessMouseMovement(xoffset, yoffset);
}

// glfw: whenever the mouse scroll wheel scrolls, this callback is called
// ----------------------------------------------------------------------
void scroll_callback(GLFWwindow* window, double xoffset, double yoffset)
{
    camera.ProcessMouseScroll(yoffset);
}

