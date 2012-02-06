varying vec2 txtCoords;
uniform sampler2DRect tex;

void main()
{
	gl_FragColor = texture2DRect(tex, txtCoords.xy);
}
