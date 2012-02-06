// Example of GLSL shader with GLGraphics.
// Adapted from Vitamin's shaderlib:
// http://www.pixelnerve.com/processing/libraries/shaderlib/
// More online resources about GLSL:
// http://nehe.gamedev.net/data/articles/article.asp?article=21
// http://zach.in.tu-clausthal.de/teaching/cg_literatur/glsl_tutorial/index.html

import processing.opengl.*;
import codeanticode.glgraphics.*;

GLModel poly;
GLTexture colorTex;
GLTexture heightTex;
GLSLShader shader;
float angle;

void setup() 
{
  size(1024, 512, GLConstants.GLGRAPHICS);
  
  colorTex = new GLTexture(this, "earth.jpg");
  heightTex = new GLTexture(this, "earthbumps.jpg");
  
  shader = new GLSLShader(this, "bump.vert", "bump.frag");
  createModel();
}

void draw() 
{
  GLGraphics renderer = (GLGraphics)g;
  renderer.beginGL();
  
  background(0);  
  
  rotateX( float(mouseY)/200.0 );
  translate( 0, float(mouseY/2), -float(mouseY/2) );

  shader.start(); // Enabling shader.
  // The parameters of the GLSL shader (uniforms and attributes) can be set
  // with the methods setTexUniform, setIntUniform, setFloatUniform, etc.:
  shader.setTexUniform("colormap", 0);
  shader.setTexUniform("bumpmap", 1);
  shader.setFloatUniform("maxHeight", mouseX/2);
  // Any geometry drawn between the shader's stop() and end() will be 
  // processed by the shader.
  renderer.model(poly);
  shader.stop(); // Disabling shader.

  renderer.endGL();  
}

void createModel()
{
  
  int xsz = 128;
  int ysz = 64;
  
    // Creating rectangle, texture and GLSL shader.
  poly = new GLModel(this, 294912, TRIANGLE_STRIP, GLModel.STATIC);
  
  poly.initNormals();
  
  int count = 0;
  /*poly.beginUpdateVertices();
  for(int i = 0; i<xsz; i++) {
    for(int j = 0; j<ysz; j+=2) {
      poly.updateVertex(count, i*4, j*4, 0);
      count++;
      poly.updateVertex(count, i*4, (j*4) + 2, 0);
      count++;
    } 
  }*/
  
  
  poly.beginUpdateVertices();
  for(int i = 0; i<xsz; i++) {
    for(int j = 0; j<ysz; j++) {
      for( int nTri = 0; nTri < 6; nTri++ ){
        float flX = (float) (i*8) + ( ( nTri == 1 || nTri == 2 || nTri == 5 ) ? 8 : 0.0f );
        float flY = (float) (j*8) + ( ( nTri == 2 || nTri == 4 || nTri == 5 ) ? 8 : 0.0f );
        
        poly.updateVertex(count, flX, flY, 0);
        count++;
      }
    }
  }
  
  poly.endUpdateVertices();

  // Enabling the use of texturing...
  poly.initTexures(2);
  poly.setTexture(0, colorTex);
  poly.setTexture(1, heightTex);
   
   count = 0;
  // Setting the texture coordinates.
  poly.beginUpdateTexCoords(0);
  for(int i = 0; i<xsz; i++) {
    for(int j = 0; j<ysz; j++) {
      //poly.updateTexCoord(count, (float) i/ (float)xsz, (float) j/ (float)ysz);
      
      for( int nTri = 0; nTri < 6; nTri++ ){
        float flX = (float) i + (( nTri == 1 || nTri == 2 || nTri == 5 ) ? 1.0 : 0.0f);
        float flY = (float) j + (( nTri == 2 || nTri == 4 || nTri == 5 ) ? 1.0 : 0.0f);
        
        poly.updateTexCoord(count, flX / (float)xsz, flY / (float) ysz);
        count++;
      }
    } 
  }
  poly.endUpdateTexCoords();
  
  
  count = 0;
  // Setting the texture coordinates.
  poly.beginUpdateTexCoords(1);
     for(int i = 0; i<xsz; i++) {
    for(int j = 0; j<ysz; j++) {
       for( int nTri = 0; nTri < 6; nTri++ ){
        float flX = (float) i + (( nTri == 1 || nTri == 2 || nTri == 5 ) ? 1.0 : 0.0f);
        float flY = (float) j + (( nTri == 2 || nTri == 4 || nTri == 5 ) ? 1.0 : 0.0f);
        
        poly.updateTexCoord(count, flX / (float) xsz, flY / (float)ysz);
        count++;
      }
    } 
  }
  poly.endUpdateTexCoords();
  
  count = 0;
  poly.beginUpdateNormals();
     for(int i = 0; i<xsz; i++) {
    for(int j = 0; j<ysz; j++) {
      for( int nTri = 0; nTri < 6; nTri++ ){
      poly.updateNormal(count, 0, 0, 1);
      count++;
      }
    } 
  }
  poly.endUpdateNormals();

}
