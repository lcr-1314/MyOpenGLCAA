#include <jni.h>
#include <string>

#include "egl/CrEglThread.h"
#include "android/native_window.h"
#include "android/native_window_jni.h"

ANativeWindow *nativeWindow = NULL;
CrEglThread * crEglThread = NULL;

extern "C"
JNIEXPORT void JNICALL
Java_com_sz_opengl_CrNativeOpengl_surfaceCreate(JNIEnv *env, jobject thiz, jobject surface) {

    nativeWindow = ANativeWindow_fromSurface(env, surface);
    crEglThread = new CrEglThread();
    crEglThread->onSurfaceCreate(nativeWindow);

}

extern "C"
JNIEXPORT void JNICALL
Java_com_sz_opengl_CrNativeOpengl_surfaceChange(JNIEnv *env, jobject thiz, jint width,
                                                jint height) {
    if(crEglThread != NULL){
        crEglThread->onSurfaceChange(width, height);
    }
}