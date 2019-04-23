#pragma once
#undef ERROR
#include <windows.h>
#include <GL/gl.h>   // OpenGL Linker add openGL32.lib, gdi32.lib and User32.lib
#include <GL/glu.h>  // OpenGL Utility Library Linker 
 
using namespace System::Windows::Forms;

namespace OpenGLForm
{
    public ref class Create_OpenGL: 
    public System::Windows::Forms::NativeWindow
{

public:
    Create_OpenGL(System::Windows::Forms::Form ^parentForm, GLsizei iX, GLsizei iY,
            GLsizei iWidth, GLsizei iHeight)
    {
		// "gcnew" is an operator, just like the "new" operator, except that you don't have to delete anything created with it. It's garbase collected.
		// "CreateParams" Gets the required creation parameters when the control handle is created
		// The "^" is the managed equivalent of a * (pointer) which in C++/CLI terminology is called a 'handle' to a 'reference type' (since you can still have unmanaged pointers).
        CreateParams^ cp = gcnew CreateParams;

        // Set the position on the form
        cp->X = iX;
        cp->Y = iY;
        cp->Height = iHeight;
        cp->Width = iWidth;

        // Specify the form as the parent.
        cp->Parent = parentForm->Handle;

        // Create as a child of the specified parent
        // and make OpenGL compliant (no clipping)
        cp->Style = WS_CHILD | WS_VISIBLE | 
                    WS_CLIPSIBLINGS | WS_CLIPCHILDREN;

        // Create the actual window
        this->CreateHandle(cp);

        m_hDC = GetDC((HWND)this->Handle.ToPointer());

        if(m_hDC)
            MySetPixelFormat(m_hDC);
    }

 virtual System::Void Render(System::Void)
{
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f); // Clear screen to black
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glEnable(GL_DEPTH_TEST); // Turn on Z-depth buffering
    glEnable(GL_CULL_FACE);  // Turn on backface culling          
    glFrontFace(GL_CCW);     // Treat counter-clockwise ordering of vertices as front facing

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(40.0, 1.0, 1.0, 1000.0); // Field of view 40, width/height, near clip, far clip
             
    glMatrixMode(GL_MODELVIEW); 
    glLoadIdentity(); 
    gluLookAt(0, 0, 10, // where the camera is located
    0.0, 0.0, 0.0,      // where the camera is looking
    0.0, 1.0, 0.0);         // direction of up (Y direction)

    glBegin(GL_TRIANGLES);      // 3 vertices counter clockwise 
    glColor3f(1.0,0.0,0.0);   // Red colour
    glVertex3f(0.0, 1.0, 0.0);    // Equilateral triangle centred on (0,0,0)
    glVertex3f(-0.866, -0.5, 0);   // on XY plane, each vertex is |1| from origin. 
    glVertex3f(0.866, -0.5, 0);
    glEnd();

	SwapOpenGLBuffers();
}

System::Void SwapOpenGLBuffers(System::Void)
{
    SwapBuffers(m_hDC) ;
}

private:
    HDC m_hDC;
    HGLRC m_hglrc;

	protected:
    ~Create_OpenGL(System::Void)
    {
        this->DestroyHandle();
    }

	 GLint MySetPixelFormat(HDC hdc)
    {
        PIXELFORMATDESCRIPTOR pfd = { 
            sizeof(PIXELFORMATDESCRIPTOR),    // size of this pfd 
            1,                                // version number 
            PFD_DRAW_TO_WINDOW |              // support window 
            PFD_SUPPORT_OPENGL |              // support OpenGL 
            PFD_DOUBLEBUFFER,                 // double buffered 
            PFD_TYPE_RGBA,                    // RGBA type 
            24,                               // 24-bit color depth 
            0, 0, 0, 0, 0, 0,                 // color bits ignored 
            0,                                // no alpha buffer 
            0,                                // shift bit ignored 
            0,                                // no accumulation buffer 
            0, 0, 0, 0,                       // accum bits ignored 
            32,                               // 32-bit z-buffer     
            0,                                // no stencil buffer 
            0,                                // no auxiliary buffer 
            PFD_MAIN_PLANE,                   // main layer 
            0,                                // reserved 
            0, 0, 0                           // layer masks ignored 
        }; 
    
        GLint  iPixelFormat; 
     
        // get the device context's best, available pixel format match 
        if((iPixelFormat = ChoosePixelFormat(hdc, &pfd)) == 0)
        {
            MessageBox::Show("ChoosePixelFormat Failed");
            return 0;
        }
         
        // make that match the device context's current pixel format 
        if(SetPixelFormat(hdc, iPixelFormat, &pfd) == FALSE)
        {
            MessageBox::Show("SetPixelFormat Failed");
            return 0;
        }
    
        if((m_hglrc = wglCreateContext(m_hDC)) == NULL)
        {
            MessageBox::Show("wglCreateContext Failed");
            return 0;
        }
        
        if((wglMakeCurrent(m_hDC, m_hglrc)) == NULL)
        {
            MessageBox::Show("wglMakeCurrent Failed");
            return 0;
        }
    
        return 1;
    }
};
}
