package com.sz.myopenglcaa;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;

import com.sz.opengl.CrNativeOpengl;
import com.sz.opengl.CrSurfaceView;

public class MainActivity extends AppCompatActivity {
    private CrSurfaceView surfaceView;
    private CrNativeOpengl nativeOpengl;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        surfaceView = findViewById(R.id.crsurfaceview);
        nativeOpengl = new CrNativeOpengl();
        surfaceView.setNativeOpengl(nativeOpengl);
    }

}
