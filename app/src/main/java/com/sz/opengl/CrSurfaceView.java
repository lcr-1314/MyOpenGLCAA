package com.sz.opengl;

import android.content.Context;
import android.util.AttributeSet;
import android.view.SurfaceHolder;
import android.view.SurfaceView;

public class CrSurfaceView extends SurfaceView implements SurfaceHolder.Callback {

    private CrNativeOpengl nativeOpengl;

    public void setNativeOpengl(CrNativeOpengl nativeOpengl){
        this.nativeOpengl = nativeOpengl;
    }

    public CrSurfaceView(Context context) {
        this(context, null);
    }

    public CrSurfaceView(Context context, AttributeSet attrs) {
        this(context, attrs, 0);
    }

    public CrSurfaceView(Context context, AttributeSet attrs, int defStyleAttr) {
        super(context, attrs, defStyleAttr);
        getHolder().addCallback(this);
    }

    @Override
    public void surfaceCreated(SurfaceHolder holder) {
        if (nativeOpengl != null) {
            nativeOpengl.surfaceCreate(holder.getSurface());
        }
    }

    @Override
    public void surfaceChanged(SurfaceHolder holder, int format, int width, int height) {
        if(nativeOpengl != null){
            nativeOpengl.surfaceChange(width, height);
        }
    }

    @Override
    public void surfaceDestroyed(SurfaceHolder holder) {

    }
}
