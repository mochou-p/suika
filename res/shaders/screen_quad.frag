// suika

#version 430

uniform vec2 u_screen;

void main()
{
    vec2 uv = gl_FragCoord.xy / u_screen;

    gl_FragColor = vec4(uv, 0.0, 1.0);
}
