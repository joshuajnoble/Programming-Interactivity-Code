
uniform float rot;
uniform float imgWidth, imgHeight;
varying out vec2 txtCoords;

void main()
{
	
	float cosX = (cos(rot) * imgWidth) * 0.5;
	float sinY = (sin(rot) * imgHeight) * 0.5;
	
	gl_Position = gl_PositionIn[0];
	
	gl_Position.x += cosX;

        txtCoords.x = imgWidth - clamp(gl_Position.x, 0., imgWidth);
	txtCoords.y = imgHeight - clamp(gl_Position.y, 0., imgHeight);

	EmitVertex(); // done with the point

	gl_Position = gl_PositionIn[0];
	gl_Position.x += cosX;
	gl_Position.y += sinY;

        txtCoords.x = imgWidth - clamp(gl_Position.x, 0., imgWidth);
	txtCoords.y = imgHeight - clamp(gl_Position.y, 0., imgHeight);

	EmitVertex(); // done with the point

	gl_Position = gl_PositionIn[0];

	gl_Position.x -= cosX;
	gl_Position.y -= sinY;

        txtCoords.x = imgWidth - clamp(gl_Position.x, 0., imgWidth);
	txtCoords.y = imgHeight - clamp(gl_Position.y, 0., imgHeight);

	EmitVertex();  // done with the point
	EndPrimitive(); // end the triangle
}
