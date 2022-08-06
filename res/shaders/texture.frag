// suika

#version 430

in vec4 vertex_color;
in vec2 texture_coord;

uniform sampler2D u_texture;

void main()
{
    gl_FragColor = texture(u_texture, texture_coord) * vertex_color;
}
