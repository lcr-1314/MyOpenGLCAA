#include <jni.h>
#include <string>

#include "egl/CrEglHelper.h"
#include "android/native_window.h"
#include "android/native_window_jni.h"
#include "GLES2/gl2.h"

CrEglHelper * eglHelper = NULL;
ANativeWindow *nativeWindow = NULL;

extern "C"
JNIEXPORT void JNICALL
Java_com_sz_opengl_CrNativeOpengl_surfaceCreate(JNIEnv *env, jobject thiz, jobject surface) {

    nativeWindow = ANativeWindow_fromSurface(env, surface);

    eglHelper = new CrEglHelper();
    eglHelper->initEgl(nativeWindow);

    glViewport(0, 0, 1080, 1920);
    glClearColor(1.0f, 1.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    eglHelper->swapBuffers();
}