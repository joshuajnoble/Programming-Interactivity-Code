uniform sampler2D colormap;
uniform sampler2D bumpmap;
varying vec2 TexCoord;
uniform float maxHeight;

void main(void) 
{
    TexCoord = gl_MultiTexCoord0.st;

    vec4 bumpColor = texture2D(bumpmap, TexCoord);
    float df = 0.30*bumpColor.x + 0.59*bumpColor.y + 0.11*bumpColor.z;
    vec4 newVertexPos = vec4(gl_Normal * df * float(maxHeight), 0.0) + gl_Vertex;

    gl_Position = gl_ModelViewProjectionMatrix * newVertexPos;
}