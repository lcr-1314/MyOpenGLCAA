//
// Created by lenovo on 2020/6/6.
//

#ifndef MYOPENGLCAA_CREGLTHREAD_H
#define MYOPENGLCAA_CREGLTHREAD_H

#include <EGL/eglplatform.h>
#include "pthread.h"
#include "CrEglHelper.h"
#include <unistd.h>

class CrEglThread {


public:
    pthread_t eglThread = -1;
    ANativeWindow *nativeWindow = NULL;

    bool isCreate = false;
    bool isChange = false;
    bool isExit = false;
    bool isStart = false;

    bool surfaceWidth = 0;
    bool surfaceHeight = 0;

public:

    CrEglThread();
    ~CrEglThread();

    void onSurfaceCreate(EGLNativeWindowType window);
    void onSurfaceChange(int width, int height);
};


#endif //MYOPENGLCAA_CREGLTHREAD_H
