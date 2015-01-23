//
//  ofxCrossfadeShader.h
//  ofxCrossfadeShader
//
//  Created by erik on 23/1/15.
//
//

#pragma once

#include "ofMain.h"

class ofxCrossfadeShader
{
private:
    
    ofShader shader;

    
    void setup()
    {
        
#define STRINGIFY(x) #x
        string ShaderSrc = STRINGIFY(
                uniform sampler2DRect textureA;
                uniform sampler2DRect textureB;
                uniform float pct;
                void main()
                {
                    vec4 pA = texture2DRect(textureA, gl_TexCoord[0].xy);
                    vec4 pB = texture2DRect(textureB, gl_TexCoord[0].xy);
                    vec4 pMix = pA * (1.0 - pct) + pB * pct;
                    gl_FragColor = pMix;
                }

        );
        shader.setupShaderFromSource(GL_FRAGMENT_SHADER, ShaderSrc);
        shader.linkProgram();
#undef STRINGIFY
    }
    
public:
    
    ofxCrossfadeShader()
    {
        setup();
    }
    ~ofxCrossfadeShader()
    {
        ofLog() << "~ofxCrossfadeShader()";
    }
    
    void begin(ofTexture& imgA, ofTexture& imgB, float pct)
    {
        shader.begin();
            shader.setUniformTexture("textureA", imgA, 0);
            shader.setUniformTexture("textureB", imgB, 1);
            shader.setUniform1f("pct", pct);
        
    }
    
    void end(){
        shader.end();
    }
    
    static void beginShader(ofTexture& imgA, ofTexture& imgB, float pct)
    {
        instance()->begin(imgA, imgB, pct);
    }
    static void endShader(){
        instance()->end();
    }
    
    static ofPtr<ofxCrossfadeShader> instance()
    {
        
        static ofPtr<ofxCrossfadeShader>factory = ofPtr<ofxCrossfadeShader>(new ofxCrossfadeShader());
        return factory;
    }
};

/* EOF */