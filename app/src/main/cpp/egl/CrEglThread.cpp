//
// Created by lenovo on 2020/6/6.
//


#include <GLES2/gl2.h>
#include "CrEglThread.h"


CrEglThread::CrEglThread() {

}

CrEglThread::~CrEglThread() {

}

void *eglThreadImpl(void *context) {
    CrEglThread *crEglThread = static_cast<CrEglThread *>(context);
    if(crEglThread != NULL){
        CrEglHelper *crEglHelper = new CrEglHelper();
        crEglHelper->initEgl(crEglThread->nativeWindow);
        crEglThread->isExit = true;

        while (true) {
            if (crEglThread->isCreate) {
                LOGD("eglthread call surfaceCreate");
                crEglThread->isCreate = false;
            }

            if (crEglThread->isChange) {
                LOGD("eglthread call surfaceChange");
                crEglThread->isChange = false;
                glViewport(0, 0, 1080, 1920);
                crEglThread->isStart = true;
            }

            //draw
            LOGD("draw");
            if (crEglThread->isStart) {
                glClearColor(0.0f, 1.0f, 1.0f, 1.0f);
                glClear(GL_COLOR_BUFFER_BIT);
                crEglHelper->swapBuffers();
            }
            usleep(1000000 / 60);
            if (crEglThread->isExit) {
                break;
            }
        }
    }

    return 0;
}

void CrEglThread::onSurfaceCreate(EGLNativeWindowType window) {
    if(eglThread = -1){
        isCreate = true;
        nativeWindow = window;

        pthread_create(&eglThread, NULL, eglThreadImpl, this);
    }
}

void CrEglThread::onSurfaceChange(int width, int height) {
    isChange = true;
    surfaceWidth = width;
    surfaceHeight = height;
}
