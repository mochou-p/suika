// suika

#version 430

layout (location = 0) in vec3 vert_position;
layout (location = 1) in vec3 vert_color;
layout (location = 2) in vec2 tex_coord;

out vec4 vertex_color;
out vec2 texture_coord;

void main()
{
   gl_Position   = vec4(vert_position, 1.0);
   vertex_color  = vec4(vert_color,    1.0);
   texture_coord = tex_coord;
}
