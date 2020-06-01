//
// Created by lenovo on 2020/6/1.
//

#ifndef MYOPENGLCAA_CREGLHELPER_H
#define MYOPENGLCAA_CREGLHELPER_H


#include "EGL/egl.h"
#include "../log/CrAndroidLog.h"

#define TAG "CrEglHelper"

class CrEglHelper {

public:
    EGLDisplay mEglDisplay;
    EGLSurface mEglSurface;
    EGLConfig  mEglConfig;
    EGLContext mEglContext;

public:
    CrEglHelper();
    ~CrEglHelper();

    int initEgl(EGLNativeWindowType win);

    int swapBuffers();

    void destroyEgl();
};

#endif //MYOPENGLCAA_CREGLHELPER_H
