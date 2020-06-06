package com.sz.opengl;

import android.view.Surface;

public class CrNativeOpengl {

    static {
        System.loadLibrary("native-lib");
    }

    public native void surfaceCreate(Surface surface);

    public native void surfaceChange(int width, int height);
}
