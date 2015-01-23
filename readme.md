ofxofxCrossfadeShader
======================

how to use
------
		ofxCrossfadeShader::beginShader(imgTexRefA, imgTexRefB, pct);
				tex.draw(0, 0);
		ofxCrossfadeShader::endShader();
		
		or
		
		ofxCrossfadeShader hueShader;		
		ofxCrossfadeShader.begin(imgTexRefA, imgTexRefB, pct);
				tex.draw(0, 0);
		ofxCrossfadeShader.end();
		
