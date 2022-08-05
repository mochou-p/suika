// suika

#version 430

layout (location = 0) in vec3 vert_position;
layout (location = 1) in vec3 vert_color;
layout (location = 2) in vec2 tex_coord;

out vec3 vertex_color;
out vec2 texture_coord;

void main()
{
   gl_Position   = vec4(vert_position, 1.0);
   vertex_color  = vert_color;
   texture_coord = vec2(tex_coord.x, tex_coord.y);
}
