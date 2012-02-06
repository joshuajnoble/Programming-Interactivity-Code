uniform sampler2D colormap;
uniform sampler2D bumpmap;
varying vec2 TexCoord;

void main(void) {
    gl_FragColor = texture2D(colormap, TexCoord);
}