uniform sampler2DRect video;
uniform sampler2DRect background;
uniform float greenAmt, redAmt;
void main()
{
	vec4 color = texture2DRect(video, gl_TexCoord[0].xy);
	vec4 color2 = texture2DRect(background, gl_TexCoord[0].xy);
	
	if(color.z > greenAmt && color.x < redAmt) {
		gl_FragColor = color2;
	} else {
		gl_FragColor = color;
	}	
}