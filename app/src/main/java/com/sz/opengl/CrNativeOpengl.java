package com.sz.opengl;

import android.view.Surface;
import android.view.SurfaceView;

public class CrNativeOpengl {

    static {
        System.loadLibrary("native-lib");
    }

    public native void surfaceCreate(Surface surface);
}
