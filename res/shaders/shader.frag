// suika

#version 330

uniform vec2 u_screen;

void main()
{
    vec2 uv = (gl_FragCoord.xy / u_screen) * 2.0 - 1.0;

    gl_FragColor = vec4(abs(uv), 0.0, 1.0);
}
